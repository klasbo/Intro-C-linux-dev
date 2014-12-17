Exercise 1 : Hello World
========================

Your terminal and you
---------------------

Opening a terminal window
    mkdir, cd, ls, cp, rm, mv
    wildcards `*`
    copy-paste
        Ctrl is used for "signals"
Compilers for C
    gcc, clang
        -Wall, -o
Running programs
    `./`


Goodbye world
-------------

1: The standard hello world
    main function
        returns int
        optionally takes command line arguments (reading args later)
    printf
        newline
        included from standard library
        
2: With no #include
    [!] preprocessor
        [?] use -E
    implicit declaration is bad!
    default function is `int fcn(...)`
        which printf satisfies (fmt'ing later)
    [?] Add a forward declaration of printf
        
3: With no return value
    [!] language standards: c89, c99 (gnu99), c11
        in c89, return statement was mandatory
    using gcc c89:
        get return value with `echo $?`
        [?] what does it return?
            hint: what does printf return?
            [!] explanation of stack
            
4: The smallest C program?
    Same as before: default function is `int fcn(...)`
    

#5: The empty file
#    [!] Linker: Undefined reference
#    [!] Separate compile and link phase
#        [?] use -c
#        [?] link with ld, and define `--entry main`
#
    
    
Exercise 2 : Syntax
===================

1: Basic types
    int, double, char, void (more?)
1a: Modifiers
    *, static, const
    
2: printf
    format string, comma-separated arg list
     
3: Operators
    Arithmetic:
        Binary: + - * / % 
        Unary: ++ -- 
    Logical: < > && || ! 
    Bitwise: ~ & | ^ << >>
    Compound: op=
    
4: Functions
    [?] create a function that takes an integer and returns its square
    
5: Loops
    while, for, (do-while)
    [?] create a function that returns the n-th fibonacci number
    
6: If, modulo and printf formatting
    [?] Create a function that prints the Collatz sequence for a positive number
        Formatting: single line, columns 3 wide, left justify

7: User-defined types
    typedef
    structs
    [?] Create a struct
    [?] write a fake magic trick that modifies the struct content / creates a new struct
        [!] pointers, addrof (&), indirection/dereference (*)
    
8: Fixed-size arrays and basic pointer arithmetic
    [?] write a helper fcn that prints the array
        use array[indexing]
    [?] use sum += *p++ to foldl an array
    [?] call sort to sort an array
        [!] memory layout, object sizes, higher-order functions
    

Exercise 3 : Modules and Makefiles
==================================

1: {temp} Move some previous exercise to another file

2: {temp} Create a makefile (?)
    
