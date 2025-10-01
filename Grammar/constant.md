# This is the Gray-Leaf's grammar.
## Gray-Leaf's constant are different.It is defined on by keyword '[const](../Grammar/basic_type.md/#modifier)'.

## __Integer constant__
Integer constants can be binary, decimal, octal, or hexadecimal. The prefix shows the base: 0x or 0X is hex, 0 is octal, 0b or 0B is binary, and without a prefix, it’s decimal by default.
```c
int a = 0b11110011;
int b = 0173;
int c = 123;
int d = 0x7b;
```

## __Floating-point constant__
A floating-point constant is made up of an integer part, a decimal point, a fractional part, and an exponent part.Exponents with signs are introduced using e or E.
```c
float a = 3.14159; 
double b = 314159E-5L;
```

## __Boolean constants__
There are two Boolean constants in total.One is true and the other is false.
```cpp
bool a = true;
bool b = false;
```

## __Character constants__
Character constants are wrapped in single quotes.
```c
char a = 'abc';
char b = '123456874533132';
```

## __String constants__
String constants are just text wrapped in double quotes ("").
```cpp
string a = "abcd";
string b = "1231523132132131";
```
