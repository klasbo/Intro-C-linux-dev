Exercise 1 : Hello World
========================

Your terminal and you
---------------------

### Opening a terminal window
There are seveal ways to open a new terminal window:
 - [check Ubuntu menu]
 - Press `Ctrl + Alt + T`

From the terminal we can much more than with the graphical interface, but we will start with some basic and familiar functions. First, we should make a new folder that we will use as our "workbench" of sorts.

 - To make this folder on the desktop, we must first change directory in the terminal. Do this by typing `cd ~/Desktop` ("cd" means "change directory"). Use the Tab key to autocomplete the directory name.
 - Make a new directory using `mkdir directoryName`. Give this some appropriate name.

We can create new files using `touch fileName`, and edit them using - for example - `nano` or `vi`. There are of course other non-terminal text editors, and these may be more (or less) comfortable to work with. Create a file.

 - We can list the files in the current directory by using `ls` ("ls" means "list").
   - If you call `ls -a`, you will see two extra entries: `.` and `..`. These are the "names" of the current directory and the parent directory, respectively. You can `cd` a level "up" by calling `cd ..`.
 - We can move a file using `mv moveThisFile toHere`. Move the file you created one level up, by calling `mv fileYouCreated ../fileName`, or the shorter version `mv fileYouCreated ../` if you want to keep the same fileName.
   - Call `ls ..` to check that the file is moved.
 - Similarly to `mv`, we also have `cp` for copying.
 - We can remove files using `rm`. Remove the file you created, moved (and any copies you created if you also copied it).

`mv`, `cp` and `rm` all have their own set of options. You can see what these are by calling eg `rm --help`. For `cp` and `rm`, we see that we need to use the option `-r` or `--recursive` to copy or remove folders.

If we want to select multiple files that match a certain pattern, we can use the wildcard `*`. For example, if we want to remove all files that end in `.txt`, we can call rm `*.txt`.
    
    
In the terminal, Ctrl-C and Ctrl-V do not perform copy/paste, and you can find a brief history as to why [here](http://superuser.com/a/421468). Instead, use `Ctrl + Shift + [C/V/X]`


###Compilers for C
    gcc, clang
        -Wall, -o
###Running programs
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
    
