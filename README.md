# dynamic_type_checking
Starter code to help with dynamic type checking assignment for Compiler Security course


## File Description

### Makefile
This is the makefile to make everything build. Just type make to get the two
executables below. You likely will want to use this as an example for building
your example programs.

In particular this deals with the fact that we are calling C++ functions from
within a C program. It handles all the proper compilation steps for you.


### Shadowlib
Contains the files

shadowlib.cpp
shadowlib.h

A very simple hash table in C++ to be called from within C programs.


### test_shadow_lib.c

A very simple demonstration of using the shadowlib.


### demo_dynamic_type_check.c

An example program with some casting that could potentially be dangerous.

The `#ifdef` throughout show you how one would use the shadowlib manually to
do the required dynamic type checking. Your compiler pass will essentially need
to automatically instrument a program in a manner very similar to what was done
here.



## What you should do 

Play around with the example a little. Gain some understanding of how this
works.

Once you feel comfortable with it, then move on to implementing a compiler pass
to instrument the code appropriately. 
