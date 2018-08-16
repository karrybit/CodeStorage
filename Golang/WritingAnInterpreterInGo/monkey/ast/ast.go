package ast

import (
	"bytes"

	"../token"
)

// Node 構文木のNode
type Node interface {
	TokenLiteral() string
	String() string
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

func (p *Program) String() string {
	var out bytes.Buffer

	for _, s := range p.Statements {
		out.WriteString(s.String())
	}

	return out.String()
}

// Identifier 変数
type Identifier struct {
	Token token.Token // token.IDENT トークン
	Value string
}

// TokenLiteral IdentifierのTokenのLiteralを（変数名（可変））を返却する
func (i *Identifier) TokenLiteral() string { return i.Token.Literal }
// String Identifierを文字列化する（e.g.）"hoge"）
func (i *Identifier) String() string { return i.Value }
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
// String LetStatementを文字列化する（e.g.）"let hoge = 10;"）
func (ls *LetStatement) String() string {
	var out bytes.Buffer

	out.WriteString(ls.TokenLiteral() + " ")
	out.WriteString(ls.Name.String())
	out.WriteString(" = ")

	if ls.Value != nil {
		out.WriteString(ls.Value.String())
	}

	out.WriteString(";")

	return out.String()
}
func (ls *LetStatement) statementNode()       {}

// ReturnStatement return文
type ReturnStatement struct {
	Token       token.Token // 'return' トークン
	ReturnValue Expression  // returnする内容(= 式)
}

// TokenLiteral ReturnStatementのTokenのLiteralを（"return"）を返却する
func (rs *ReturnStatement) TokenLiteral() string { return rs.Token.Literal }
// String ReturnStatementを文字列化する（e.g.）"return 10;"）
func (rs *ReturnStatement) String() string {
	var out bytes.Buffer

	out.WriteString(rs.TokenLiteral() + " ")
	
	if rs.ReturnValue != nil {
		out.WriteString(rs.ReturnValue.String())
	}

	out.WriteString(";")

	return out.String()
}
func (rs *ReturnStatement) statementNode()       {}

// ExpressionStatement 式文
type ExpressionStatement struct {
	Token 	   token.Token // 式の最初のトークン
	Expression Expression
}

// TokenLiteral ExpressionStatementのTokenのLiteralを（"return"）を返却する
func (es *ExpressionStatement) TokenLiteral() string { return es.Token.Literal }
// String ExpressionStatementを文字列化する（e.g.）"10"）
func (es *ExpressionStatement) String() string {
	var out bytes.Buffer

	if es.Expression != nil {
		return es.Expression.String()
	}

	return ""
}
func (es *ExpressionStatement) statementNode()	     {}