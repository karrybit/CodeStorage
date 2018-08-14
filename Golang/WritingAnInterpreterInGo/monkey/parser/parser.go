package parser

import (
	"../ast"
	"../lexer"
	"../token"
)

// Parser 実体
type Parser struct {
	l *lexer.Lexer

	curToken  token.Token
	peekToken token.Token
}

// New Parserの初期化
func New(l *lexer.Lexer) *Parser {
	p := &Parser{l: l}

	// 2つトークンを読みこむ。curTokenとpeekTokenの両方がセットされる。
	p.nextToken()
	p.nextToken()

	return p
}

func (p *Parser) nextToken() {
	p.curToken = p.peekToken
	p.peekToken = p.l.NextToken()
}

// ParseProgram .
func (p *Parser) ParseProgram() *ast.Program {
	return nil
}
