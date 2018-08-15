package ast

import "../token"

// Node 構文木のNode
type Node interface {
	TokenLiteral() string
}

// Statement 文
type Statement interface {
	Node
	statementNode()
}

// Expression 式
type Expression interface {
	Node
	expressionNode()
}

// Program 文の集合、つまりプログラムそのもの
type Program struct {
	Statements []Statement
}

// TokenLiteral プログラムの0番目のTokenのLiteralを返却する
func (p *Program) TokenLiteral() string {
	if len(p.Statements) > 0 {
		return p.Statements[0].TokenLiteral()
	}
	return ""
}

// Identifier 変数
type Identifier struct {
	Token token.Token // token.IDENT トークン
	Value string
}

// TokenLiteral IdentifierのTokenのLiteralを（変数名（可変））を返却する
func (i *Identifier) TokenLiteral() string { return i.Token.Literal }

// 変数それ自体は値を返却するので、expressionNodeを実装する
func (i *Identifier) expressionNode() {}

// LetStatement let文
type LetStatement struct {
	Token token.Token // 'let' トークン
	Name  *Identifier // 変数名
	Value Expression  // 式
}

// TokenLiteral LetStatementのTokenのLiteralを（"let"）を返却する
func (ls *LetStatement) TokenLiteral() string { return ls.Token.Literal }
func (ls *LetStatement) statementNode()       {}

// ReturnStatement return文
type ReturnStatement struct {
	Token       token.Token // 'return' トークン
	ReturnValue Expression  // returnする内容(= 式)
}

// TokenLiteral ReturnStatementのTokenのLiteralを（"return"）を返却する
func (rs *ReturnStatement) TokenLiteral() string { return rs.Token.Literal }
func (rs *ReturnStatement) statementNode()       {}
