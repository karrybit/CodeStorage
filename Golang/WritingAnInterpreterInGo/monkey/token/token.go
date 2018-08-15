package token

// TokenType トークン種別
type TokenType string

// Token トークンの実体
type Token struct {
	Type    TokenType
	Literal string
}

const (
	// ILLEGAL 不正値
	ILLEGAL = "ILLEGAL"
	// EOF End Of File
	EOF = "EOF"

	// IDENT 識別子
	IDENT = "IDENT" // add, foobar, x, y, ...
	// INT リテラル
	INT = "INT" // 1343456

	// ASSIGN 代入
	ASSIGN = "="
	// PLUS 加算
	PLUS = "+"
	// MINUS 減算
	MINUS = "-"
	// BANG 否定
	BANG = "!"
	// ASTERISK 積算
	ASTERISK = "*"
	// SLASH 除算
	SLASH = "/"

	// LT Less Than
	LT = "<"
	// GT Greater Than
	GT = ">"
	// EQ Equal
	EQ = "=="
	// NOTEQ Not Equal
	NOTEQ = "!="

	// COMMA カンマ
	COMMA = ","
	// SEMICOLON セミコロン
	SEMICOLON = ";"

	// LPAREN 左丸括弧
	LPAREN = "("
	// RPAREN 右丸括弧
	RPAREN = ")"
	// LBRACE 左波括弧
	LBRACE = "{"
	// RBRACE 右波括弧
	RBRACE = "}"

	// FUNCTION 関数
	FUNCTION = "FUNCTION"
	// LET 束縛
	LET = "LET"
	// TRUE 真
	TRUE = "TRUE"
	// FALSE 偽
	FALSE = "FALSE"
	// IF 仮定
	IF = "IF"
	// ELSE 仮定
	ELSE = "ELSE"
	// RETURN 返却
	RETURN = "RETURN"
)

var keywords = map[string]TokenType{
	"fn":     FUNCTION,
	"let":    LET,
	"true":   TRUE,
	"false":  FALSE,
	"if":     IF,
	"else":   ELSE,
	"return": RETURN,
}

// LookupIdent 文字列を受け取り、予約後であればそのTokenTypeを返し、そうでなければIDENTを返す
func LookupIdent(ident string) TokenType {
	if tok, ok := keywords[ident]; ok {
		return tok
	}
	return IDENT
}
