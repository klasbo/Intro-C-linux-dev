Intro to C and Linux
====================

Part 1: Your terminal and you
-----------------------------

### Opening a terminal window

There are several ways to open a new terminal window:
 - From the menu in the top-left corner (start typing "terminal")
 - The terminal icon on the left sidebar
 - By pressing `Ctrl + Alt + T`

From the terminal we can much more than with the graphical interface, but we will start with some basic and familiar functions. First, we should make a new folder that we will use as our "workbench" of sorts.

 - [ ] To make this folder on the desktop, we must first change directory in the terminal. Do this by typing `cd ~/Desktop` ("cd" means "change directory"). Use the Tab key to autocomplete the directory name.
 - [ ] Make a new directory using `mkdir directoryName`. Give this some appropriate name.

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



    
Part 3: C syntax and some simple programs
-----------------------------------------

Now that we know how the basics of using the terminal and invoking compilers, we can finally get started with some code.

This is not a test, and it is not a competition. The goal is to learn the basics of the C language and toolchain so that you can start making useful programs on your own. If you are stuck, you should ask for help. Remember that your fellow students and the internet are also valuable resources!

###0: Hello world
 - [ ] Copy or type the standard "[hello world](https://github.com/klasbo/Intro-C-linux-dev/blob/master/hello_world.c)" program. Compile it and run it, and verify that it works as expected.

###1: The `main` function

A function is declared as follows:
```C
return_type function_name(argument_type argument_name){
    // function body
}
```
Note that C use braces (`{``}`) to signify the start and end of a scope, unlike - say - Python, which uses colon (`:`) and significant whitespace (indentation). **Familiar with scope concept?**

 - The `main` function is where execution starts.
   - `main` must return an `int` (integer). Returning `0` is commonly used to signify that the program has run successfully.
   - `main` can take either no arguments (here signified by `void`), or two arguments: `int main(int argc, char** argv)`. The latter two-argument version is used when the program should take arguments from the command line.
 - `printf` is used to "print formatted" to the standard output (here the terminal). We will come back to the "formatted" part of printing later.
   - The `\n` at the end of the string is used to print a newline. Try removing it to see what happens.
   - `printf` is a function, so we need to give the compiler some information about what this function looks like. We find this information in `stdio.h`, which is why we use `#include <stdio.h>`.

   
###2: Basic types

C is a statically typed language, which means that all variables must be assigned a type, and this type cannot change. The built-in types are:
 - `int`: Standard signed integer, usually 32 bit.
   - `short`, `long`: short (usually 16 bit) and long (usually 64 bit) integers
 - `char`: A single character (used for strings), 8 bit
 - `float` and `double`: 32 bit and 64 bit floating-point numbers
 - `void`: "Untyped", usually used in conjunction with pointers (memory locations) and typecasting (telling the compiler to reinterpret one type as another)
 
Notice the lack of booleans and strings.
 - `int` is usually used as a substitute for booleans.
 - `char *` ("pointer to char" (think "memory location of char")) is used for strings. We will come back to how this works later.

**Modifiers? `extern, static, const, unsigned`**
    
###3: `printf`

`printf` takes one or more arguments, and the first argument is always a string (or rather, a `char *`). In this string we can embed several *conversion specifiers* that will be replaced by the additional arguments. A conversion specifier starts with the character `%`:
```C
printf("An integer: %d, a string: %s\n", 5, "hello!");
```

You can find full documentation of printf by typing `man fprintf` in the terminal. However, going [here](http://www.cplusplus.com/reference/cstdio/printf/) provides a more concise overview with better examples.

 - [ ] Declare and initialize variables for each of the types `int`, `char`, `float` and `char *`, then print them.
   - You can either declare and initialize in two statements (`type variable_name; variable_name = ...;`), or in a single statement (`type variable_name = ...;`)
 - [ ] Try removing the initialization (where you assign a value to the variable), and print the values now.

###4: Operators

**From Sverre? Resources on the web?**

C uses these symbols for binary (two-argument) arithmetic operators:
 - `*` (multiply), `/` (divide), `%` (modulo)
 - `+` (add), `-` (subtract)

Since C does not have booleans, a value of `0` means false, and any other value means true.
C uses these symbols for logical operators:
 - `&&` (and), `||` (or), `!` (not)
 - `<` (less than), `>` (greater than)
 
 - [ ] Find the rules for operator precedence for the above operators
 
C also has the unary (one-argument) increment and decrement operators:
 - `value++` and `++value` increase `value` by `1`
 - Similarly for `value--` and `--value`
 
 - [ ] Try the post- and pre-increment to see how they behave differently (eg `printf("%d\n", x++);`)
 
The binary arithmetic operators can also be combined with assignment (`=`), to avoid writing `value = value + 2`:
 - `+=  -=  *=  /=  %=`
 
There are also bitwise operators (`~  &  |  ^  <<  >>`) for working with single bits. We will not be using them.

    
###5: Functions
    - [ ] Create a function that takes an integer and returns its square.
      - The function must be declared "before" it is used, in other words above the point where it is called.
      - C does not allow you to declare a function inside another function
    
###6: Loops

C has several loop statements:
 - `for(initialize; test; increment){}`: Runs `initialize`, then runs `test` *before* and `increment` *after* the loop body.
   - eg `for(int i = 0; i < 10; i++){}` will give `i` the values 0 to 9
 - `while(condition){}`: Runs the loop body while `condition` is true.
   - Equivalent to `for(; condition; ){}`
   - `while(1){}` will run forever.
 - `do {} while(condition)`: Similar to `while`, but checks the condition *after* it has run through the loop.

 - [ ] Use a loop to create a function that returns the n-th Fibonacci number.
   - The function should take `int n` as its only parameter, and return an `int`.
   - Do not spend time reinventing the wheel. Search [Rosetta Code](http://rosettacode.org) for inspiration.
    
###7: If, modulo and `printf` formatting

An if-statement in C looks like this:
```C
if(condition){
    //...
} else if(other condition){
    //...
} else {
    //...
}
```
`else if` and `else` are optional. Any number of `else if`s can be added.

 - [ ] Create a function that prints the [Hailstone sequence](http://en.wikipedia.org/wiki/Collatz_conjecture) for positive numbers. The numbers should be printed on a single line, in columns 4 wide, left justify.
   - Example output for `3`: `3   10  5   16  8   4   2   `
     - Use `printf` format specifiers to achieve this.
   - Use modulo (`%`) to check if a value is even or odd.

###8: User-defined types
    typedef
    structs
    [?] Create a struct
    [?] write a fake magic trick that modifies the struct content / creates a new struct
        [!] pointers, addrof (&), indirection/dereference (*)
    
9: Fixed-size arrays and basic pointer arithmetic
    [?] write a helper fcn that prints the array
        use array[indexing]
    [?] use sum += *p++ to foldl an array
    [?] call sort to sort an array
        [!] memory layout, object sizes, higher-order functions
    

Exercise 3 : Modules and Makefiles
==================================

1: {temp} Move some previous exercise to another file

2: {temp} Create a makefile (?)
    
    
    
Part 6: Goodbye World (Advanced/For fun/Optional)
-------------------------------------------------

We will be doing something rather unconventional here: By looking at each little piece in the standard "hello world" program in detail, and then removing that piece, we will break down (in more ways than one) a C program and the toolchain used for building an executable.

###1: The standard "hello world" program

 - [ ] Start with the standard "hello world" program, as before
   
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

The error message tells us that there is a problem in function `_start`: An undefined reference to `main`. The problem is that the automatically generated `_start` function tries to call `main`, but the compiler hasn't given the linker a function with that name. As it turns out, `main` isn't really where execution starts! In fact there are several functions that are called before `main` (and we can even define our own), but `_start` is king of all functions.

So to create an executable without `main`, we need to prevent *the C compiler* from creating a standard `_start` function. To do this, we will compile and link in two separate phases.

 - [ ] First, we must generate a file to give to the linker. Since the linker works with object files, we will compile our empty file with the compiler option `-c`.
 - [ ] Invoke the linker with `ld`, and pass the object file. You can give a name to the executable using `-o` as before.
 - [ ] Run the worlds shortest C program!
 
As an added bonus, this is also the shortest program that produces its own source code as output...

The words "Segmentation Fault" means that the operating system prevented you from accessing memory that your program doesn't own. In this case, the value of `_start` was not defined, so `ld` gave it a default value, one that happened to be outside the valid memory region of the program. Without an operating system, this program would have interpreted whatever happened to lie in this memory as valid machine code, and all hell would break loose.