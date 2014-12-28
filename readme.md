Intro to C and Linux
====================

Part 1: Your terminal and you
-----------------------------

### Opening a terminal window

There are several ways to open a new terminal window:
 - [check Ubuntu menu]
 - Press `Ctrl + Alt + T`

From the terminal we can much more than with the graphical interface, but we will start with some basic and familiar functions. First, we should make a new folder that we will use as our "workbench" of sorts.

  - :question: To make this folder on the desktop, we must first change directory in the terminal. Do this by typing `cd ~/Desktop` ("cd" means "change directory"). Use the Tab key to autocomplete the directory name.
  - :question: Make a new directory using `mkdir directoryName`. Give this some appropriate name.

We can create new files using `touch fileName`, and edit them using - for example - `nano` or `vi`. There are of course other non-terminal text editors, and these may be more (or less) comfortable to work with. Create a file.

 - [ ] We can list the files in the current directory by using `ls` ("ls" means "list").
   - If you call `ls -a`, you will see two extra entries: `.` and `..`. These are the "names" of the current directory and the parent directory, respectively. You can `cd` a level "up" by calling `cd ..`.
 - [ ] We can move a file using `mv moveThisFile toHere`. Move the file you created one level up, by calling `mv fileYouCreated ../fileName`, or the shorter version `mv fileYouCreated ../` if you want to keep the same fileName.
   - Call `ls ..` to check that the file is moved.
 - Similarly to `mv`, we also have `cp` for copying.
 - [ ] We can remove files using `rm`. Remove the file you created, moved (and any copies you created if you also copied it).

`mv`, `cp` and `rm` all have their own set of options. You can see what these are by calling eg `rm --help`. For `cp` and `rm`, we see that we need to use the option `-r` or `--recursive` to copy or remove folders.

If we want to select multiple files that match a certain pattern, we can use the wildcard `*`. For example, if we want to remove all files that end in `.txt`, we can call rm `*.txt`.
    
    
In the terminal, Ctrl-C and Ctrl-V do not perform copy/paste, and you can find a brief history as to why [here](http://superuser.com/a/421468). Instead, use `Ctrl + Shift + [C/V/X]`



Part 2: Ready, set, C
---------------------

Before we create our first program in C, we must first look into exactly how we create it, how we run it, and finally - if it doesn't do this on its own - how we make it stop.

###Compilers for C

To create an executable program from C-code, we must compile it. There are several C-compilers out there, and by far the most common is the Gnu Compiler Collection, [gcc](https://gcc.gnu.org/). [Clang](http://clang.llvm.org/) is a newer compiler, which means it has learned several lessons from gcc. One of the most noticeable improvements are the significantly superior warnings and error messages.

Compilers are complicated beasts, and have a [huge number of options](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html). Here's a summary of the ones we will need:
 - `-o executableName`: By default, the name of the executable is `a.out`. `-o` gives it a different name.
 - `-E`: This outputs the source code after preprocessing, and does not perform compilation or linking.
 - `-c`: The compiler produces an object-file (.o) for each c-file, instead of a single executable.
   - This is used to prevent compiling all of the code over and over, when only a few files have been changed.
   - To create an executable from object files, use gcc or clang again, or call the linker directly using `ld`.
 - `-Wall`: There are lots of `-Wxx` options for controlling warnings. `-Wall` enables all of them.
   - In general, do not ignore compiler warnings because they're "just warnings"!
 - `-g`: Produces debugging information that will be useful if (also known as "when") your programs crash.
 - `-fsanitize=address`: This option will crash your program the moment Something Bad happens with the memory the program is using, and print out a large amount of information about exactly what went wrong and - when used in combination with `-g` - where it happened.

We invoke the compiler using `compiler -options filename.c`, eg `gcc -Wall hello_world.c`.
 
 
###Running programs

To tell the terminal that we want to run a program, we must prefix the name of the executable with `./`, eg `./totallyRadProgram`. You can find an explanation of why [here](http://askubuntu.com/a/320657).

###Stopping programs

As you may recall if you read the explanation for why copy/paste is done with Ctrl-Shift-C/V, Ctrl-C is used to cancel the current program.

Part 3: Hello World
-------------------

Now that we know how the basics of using the terminal and invoking compilers, we can finally get started with some code. We will be doing something rather unconventional here: Instead of working our way "up" towards a program that does something "useful", we will instead work our way "down". By looking at the standard "hello world" program line by line, we will break down (in more ways than one) a C program and the toolchain used for building an executable.

###1: The standard "hello world" program
 - [ ] Copy or type the standard "[hello world](https://github.com/klasbo/Intro-C-linux-dev/blob/master/hello_world.c)" program. Compile it and run it, and verify that it works as expected.

A function is declared as follows:
```C
return_type function_name(argument_type argument_name){
    // function body
}
```
Note that C use braces (`{``}`) to signify the start and end of a scope, unlike - say- Python, which uses colon (`:`) and significant whitespace (indentation). [Familiar with scope concept?]

 - The `main` function is where execution starts. (*This is a lie, We will come back to this later*)
   - `main` must return an `int` (integer). Returning `0` is commonly used to signify that the program has run successfully.
   - `main` can take either no arguments (here signified by `void`), or two arguments: `int main(int argc, char** argv)`. The latter two-argument version is used when the program should take arguments from the command line.
 - `printf` is used to "print formatted" to the standard output (here the terminal). We will come back to the "formatted" part of printing later.
   - The `\n` at the end of the string is used to print a newline. Try removing it to see what happens.
   - `printf` is a function, so we need to give the compiler some information about what this function looks like. We find this information in `stdio.h`, which is why we use `#include <stdio.h>`.
 
   
###2: Without #include

Let us now see what happens when we remove `#include <stdio.h>`:
 - [ ] Remove the #include, and compile both with gcc and clang
   - You will surely see a difference in the quality of the compiler output!
 - [ ] Since the compiler gave us "just a warning", we can still run the program. Try running it.

All lines that start with `#` are so-called "preprocessor directives". The preprocessor performs text manipulation before the compiler does its work, and has no understanding of what constitutes valid C-code. The `#include`-directive tells the preprocessor to scan the specified file before continuing with the rest of the file; it is essentially a copy/paste operation. Other directives include `#define a b`, which replaces any instance of `a` with `b`. This may be useful for defining constants, eg `#define NUM_FLOORS 4`.

To see what our source code looks like after the preprocessor has done its work, we use the compiler option `-E`.
 - [ ] Put the #include-directive back, and invoke the compiler with `-E`.
   - Yikes! That's a lot of stuff. `-E` is mostly useful when you need to see what your preprocessor directives output. [Some people](http://jhnet.co.uk/articles/cpp_magic) do truly ~~awful~~ magical things with the preprocessor, and `-E` is an invaluable tool for creating ~~such abominations~~ rainbows and sunshine.
 

Back to what happens when we remove the #include-directive: The problem is that the compiler has no way of knowing what the function `printf` looks like. We can help the compiler out by providing this definition ourselves.
 - [ ] Provide a definition of `printf`:
   - A function definition looks similar to a function declaration, but without the function body, eg: `return_type function_name(arg1_type, arg2_type);`. Note the semicolon. Giving names to the arguments is optional in a function definition.
   - The output from clang is helpful enough to give us the return type and argument types. `...` is also a valid argument: It means that the function takes any number of *additional* arguments, and that their types are unknown.
        
So why did the program compile and run even if the compiler didn't know what `printf` looks like? As it turns out, in C the "default" type of a function (one that is not defined) is `int function()`: A function that takes any number of arguments and returns an integer. Since `printf` happens to be such a function, this technically "works fine".


###3: With no return value

C is an old language, and so there exists several standards: c89, c99, and the most recent: c11. In c89, the return statement at the end of `main` was mandatory, but this was lifted in c99, where a program returns 0 unless specified otherwise.

 - [ ] We can get the return value of the program that last ran by typing `echo $?` in the terminal. Change the return value of the program, run it, and verify that you get the correct value from `echo $?`.
 - [ ] Remove the `return` statement, and ~~go back in time to 1989~~ compile with the option `-std=c89` using gcc (clang has poor support for old versions of C). Run the program and check the return value. What do you get?
   - Do you see any place in the code that corresponds to the return value of the program?
   - Hint (Spoilers): Try modifying the printed message to something else, like "Penguins!".

[Explanation of stack from Sverre?]
[Trailing zeros in strings from Sverre?]

###4: The smallest C program?

Let's keep removing things! The first to go is `printf`.

Remember the "default" function type? This also goes for `main`: It takes an unknown number of arguments, and returns an integer. This means we can remove the `void` argument, and also the return type.
 - [ ] Compile this "program" and run it. Wasn't that exciting?

###5: Definitely the smallest C program.

You would think a program couldn't get smaller and more useless than this, but it can.

 - [ ] Delete everything in the entire file, and try compiling it.

The error message tells us that there is a problem in function `_start`: An undefined reference to `main`. As alluded to earlier, `main` isn't really where execution starts. There are several functions that are called before `main` (and we can even define our own), but `_start` is king of all functions.

The problem is that the automatically generated `_start` function tries to call `main`, but the compiler hasn't given the linker a function with that name. So to create an executable without main, we need to prevent the C compiler from creating a standard `_start` function. To do this, we will compile and link in two separate phases.

 - [ ] First, we must generate a file to give to the linker. Since the linker works with object files, we will compile our empty file with the compiler option `-c`.
 - [ ] Invoke the linker with `ld`, and pass the object file. You can give a name to the executable using `-o` as before.
 - [ ] Run the worlds shortest C program!

The words "Segmentation Fault" means that the operating system prevented you from accessing memory that your program doesn't own. In this case, the value of `_start` was not defined, so `ld` gave it a default value, one that happened to he outside the valid memory region of the program. Without an operating system, this program would have interpreted whatever happened to lie in this memory as valid machine code, and all hell would break loose.

    
Part 4: C syntax and some simple programs
-----------------------------------------

###1: Basic types

[Basic types & modifiers from Sverre?]

    int, double, char, void (more?)
    [], *, static, extern, const
    
###2: `printf`

`printf` takes one or more arguments, and the first argument is always a string (more specifically, a `char *`). In this string we can embed several *conversion specifiers* that will be replaced by the additional arguments. A conversion specifier starts with the character `%`:
```C
printf("An integer: %d, a string: %s\n", 5, "hello!");
```

You can find full documentation of printf by typing `man fprintf` in the terminal. However, going [here](http://www.cplusplus.com/reference/cstdio/printf/) provides a more concise overview with better examples.

###3: Operators

[From Sverre? Resources on the web?]

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
    
