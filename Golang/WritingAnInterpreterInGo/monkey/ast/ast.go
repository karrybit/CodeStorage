package ast

import (
	"bytes"
	"strings"

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
func (ls *LetStatement) statementNode() {}

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
func (rs *ReturnStatement) statementNode() {}

// ExpressionStatement 式文
type ExpressionStatement struct {
	Token      token.Token // 式の最初のトークン
	Expression Expression
}

// TokenLiteral ExpressionStatementのTokenのLiteralを（"return"）を返却する
func (es *ExpressionStatement) TokenLiteral() string { return es.Token.Literal }

// String ExpressionStatementを文字列化する（e.g.）"10"）
func (es *ExpressionStatement) String() string {
	if es.Expression != nil {
		return es.Expression.String()
	}

	return ""
}
func (es *ExpressionStatement) statementNode() {}

// IntegerLiteral 整数リテラル
type IntegerLiteral struct {
	Token token.Token
	Value int64
}

// TokenLiteral IntegerLiteralのTokenのLiteralを（"5"）を返却する
func (il *IntegerLiteral) TokenLiteral() string { return il.Token.Literal }

// String IntegerLiteralのTokenのLiteralを（"5"）を返却する
func (il *IntegerLiteral) String() string  { return il.Token.Literal }
func (il *IntegerLiteral) expressionNode() {}

// PrefixExpression 前置演算子
type PrefixExpression struct {
	Token    token.Token
	Operator string
	Right    Expression
}

// TokenLiteral PrefixExpressionのTokenのLiteralを（"!"）を返却する
func (pe *PrefixExpression) TokenLiteral() string { return pe.Token.Literal }

// String PrefixExpressionを文字列化する（e.g.）"(!5)"）
func (pe *PrefixExpression) String() string {
	var out bytes.Buffer
	out.WriteString("(")
	out.WriteString(pe.Operator)
	out.WriteString(pe.Right.String())
	out.WriteString(")")

	return out.String()
}
func (pe *PrefixExpression) expressionNode() {}

// InfixExpression 中置演算子
type InfixExpression struct {
	Token    token.Token
	Left     Expression
	Operator string
	Right    Expression
}

// TokenLiteral InfixExpressionのTokenのLiteralを（"+"）を返却する
func (oe *InfixExpression) TokenLiteral() string { return oe.Token.Literal }

// String InfixExpressionを文字列化する（e.g.）"(5 + 5)"）
func (oe *InfixExpression) String() string {
	var out bytes.Buffer
	out.WriteString("(")
	out.WriteString(oe.Left.String())
	out.WriteString(" " + oe.Operator + " ")
	out.WriteString(oe.Right.String())
	out.WriteString(")")

	return out.String()
}
func (oe *InfixExpression) expressionNode() {}

// Boolean 真偽値
type Boolean struct {
	Token token.Token
	Value bool
}

// TokenLiteral BooleanのTokenのLiteralを（"true"）を返却する
func (b *Boolean) TokenLiteral() string { return b.Token.Literal }

// String BooleanのTokenのLiteralを（"true"）を返却する
func (b *Boolean) String() string  { return b.Token.Literal }
func (b *Boolean) expressionNode() {}

// IfExpression if式
type IfExpression struct {
	Token       token.Token
	Condition   Expression
	Consequence *BlockStatement
	Alternative *BlockStatement
}

// TokenLiteral IfExpressionのTokenのLiteralを（"if"）を返却する
func (ie *IfExpression) TokenLiteral() string { return ie.Token.Literal }

// String IfExpressionのif-elseそれぞれの文を文字列化して返却する
func (ie *IfExpression) String() string {
	var out bytes.Buffer

	out.WriteString("if")
	out.WriteString(ie.Condition.String())
	out.WriteString(" ")
	out.WriteString(ie.Consequence.String())

	if ie.Alternative != nil {
		out.WriteString(ie.Alternative.String())
	}

	return out.String()
}
func (ie *IfExpression) expressionNode() {}

// BlockStatement .
type BlockStatement struct {
	Token      token.Token
	Statements []Statement
}

// TokenLiteral BlockStatementのTokenのLiteralを（"if"）を返却する
func (bs *BlockStatement) TokenLiteral() string { return bs.Token.Literal }

// String BlockStatementを文字列化して返却する
func (bs *BlockStatement) String() string {
	var out bytes.Buffer

	for _, s := range bs.Statements {
		out.WriteString(s.String())
	}

	return out.String()
}
func (bs *BlockStatement) expressionNode() {}

// FunctionLiteral 関数リテラル
type FunctionLiteral struct {
	Token      token.Token
	Parameters []*Identifier
	Body       *BlockStatement
}

// TokenLiteral FunctionLiteralのTokenのLiteralを（"fn"）を返却する
func (fl *FunctionLiteral) TokenLiteral() string { return fl.Token.Literal }

// String BlockStatementを文字列化して返却する
func (fl *FunctionLiteral) String() string {
	var out bytes.Buffer

	params := []string{}
	for _, p := range fl.Parameters {
		params = append(params, p.String())
	}

	out.WriteString(fl.TokenLiteral())
	out.WriteString("(")
	out.WriteString(strings.Join(params, ","))
	out.WriteString(")")
	out.WriteString(fl.Body.String())

	return out.String()
}
func (fl *FunctionLiteral) expressionNode() {}

// CallExpression 関数呼び出し
type CallExpression struct {
	Token     token.Token
	Function  Expression
	Arguments []Expression
}

// TokenLiteral CallExpressionのTokenのLiteralを（"("）を返却する
func (ce *CallExpression) TokenLiteral() string { return ce.Token.Literal }

// String CallExpressionを文字列化して返却する
func (ce *CallExpression) String() string {
	var out bytes.Buffer

	args := []string{}
	for _, a := range ce.Arguments {
		args = append(args, a.String())
	}

	out.WriteString(ce.Function.String())
	out.WriteString("(")
	out.WriteString(strings.Join(args, ", "))
	out.WriteString(")")

	return out.String()
}
func (ce *CallExpression) expressionNode() {}
