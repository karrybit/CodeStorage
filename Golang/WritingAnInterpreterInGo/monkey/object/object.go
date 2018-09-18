package object

import "fmt"

const (
	// IntegerObject .
	IntegerObject = "INTEGER"
	// BooleanObj .
	BooleanObj = "BOOLEAN"
	// NullObj .
	NullObj = "NULL"
)

// ObjectType .
type ObjectType string

// Object .
type Object interface {
	Type() ObjectType
	Inspect() string
}

// Integer .
type Integer struct {
	Value int64
}

// Type .
func (i *Integer) Type() ObjectType { return IntegerObject }

// Inspect .
func (i *Integer) Inspect() string { return fmt.Sprintf("%d", i.Value) }

// Boolean .
type Boolean struct {
	Value bool
}

// Type .
func (b *Boolean) Type() ObjectType { return BooleanObj }

// Inspect .
func (b *Boolean) Inspect() string { return fmt.Sprintf("%t", b.Value) }

// Null .
type Null struct{}

// Type .
func (n *Null) Type() ObjectType { return NullObj }

// Inspect .
func (n *Null) Inspect() string { return "null" }
