#!/bin/zsh

try() {
	expected="$1"
	input="$2"

	./9cc.o "$input" >| tmp.s
	gcc -o tmp tmp.s
	chmod a+x tmp
	./tmp
	actual="$?"

	if [ "$actual" != "$expected" ]; then
		echo "$input expected, but got $actual"
		exit 1
	fi
}

try 0 0
try 42 42
try 21 '5+20-4'
try 41 ' 12 + 34 - 5 '

echo OK	
