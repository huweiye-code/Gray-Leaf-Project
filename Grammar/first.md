# This is the Gray-Leaf's grammar.

## __This language is very similar to c/c++. So it's easy to learn this language.__


## 1. You could try to know the [basic type](../Grammar/basic_type.md/#basic-type).
Gray-Leaf's basic types are int, float, double, string, char and so on.
You can use them by this way

```c
    int a = 123;
    float b = 0.123;
    string abc = "123456789";
    char d = '123';

    // We have a easy way to solve the problem that you may not know the type.
    auto e = 0x123; // ( It's just like the 'int e = 0x123;' )
```

## 2. You could try the pointer and reference.
Gray-Leaf has pointer and reference.
You can use them by this way.The 
```c
    // Pointer
    int a = 123;
    int* ptr1 = &a;
    string abc = "abcd"
    string* ptr3 = &abc;
    string** pptr = &ptr3; // (It's just like C/C++'s pointer)

    // Reference
    int b = 5;
    int& c = b;
    c = 10; // (b = 10)

    //NOTICE
    int *d, *e; // (d is int* and e is int*)
    int* f, g; // (f is int* but g is int)
```