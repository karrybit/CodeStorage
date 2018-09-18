package object

// ObjectType .
type ObjectType string

// Object .
type Object interface {
	Type() ObjectType
	Inspect() string
}
