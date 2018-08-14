package ast

import "../token"

// Node Tokenとどう絡むんだ？
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

// Program なんだこれは
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

// Identifier Valueが謎ですね...
type Identifier struct {
	Token token.Token // token.IDENT トークン
	Value string
}

// TokenLiteral IdentifierのTokenのLiteralを返却する
func (i *Identifier) TokenLiteral() string { return i.Token.Literal }
func (i *Identifier) expressionNode()      {}

// LetStatement LET文
type LetStatement struct {
	Token token.Token // token.LET トークン
	Name  *Identifier
	Value Expression
}

// TokenLiteral "LET"を返却する
func (ls *LetStatement) TokenLiteral() string { return ls.Token.Literal }
func (ls *LetStatement) statementNode()       {}
