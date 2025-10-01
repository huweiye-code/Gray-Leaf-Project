# This is the Gray-Leaf's grammar.
## Gray-Leaf's basic types are int, float, double, string, char and so on.
## __Basic Type__
| type | size |
| :--- | ---: |
| bool | 1 |
| char | unknown |
| string | unknown |
| int | unknown |
| float | 4 |
| double | 8 |
| void | 0 |

## __Modifier__
| modifier | description | example |
| :--- | :---: | ---: |
| const | Represents a [constant](../Grammar/constant.md), its value can't be changed at any time. | const [int](#basic-type) a = 5; |
| volatile | It means the variable might get changed unexpectedly, so the compiler is told not to optimize it. | volatile int b = 5; |
| mutable | Shows that class members can be modified in const objects | mutable int c = 5; |
| static | Used to define a static variable, meaning this variable is only accessible within the current file or function and can't be accessed by other files or functions. | static int d = 5; |