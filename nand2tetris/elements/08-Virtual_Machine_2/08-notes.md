## Virtual Machine II: Program Control

We will continue to develop the VM abstraction, language, and implementation. In particular, we design stack-based mechanisms for handling nested subroutine calls (procedures, functions, methods) of procedural or object-oriented languages. As we progess, we extend the previously built basic VM implementation, ending up with a full-scale VM translator.

***Stack Processing*** is a remarkably simple data structure which can support remarkably complex tasks liks nested subroutine calling, parameter passing, recursion, and associated memory allocation techniques.

### Background

The more abstract the high level, the more work we have to do at the low level.
In particular, the low level must manage the delicate interplay between the calling subroutine (the *caller*) and the *called* subroutines - the program units that implement system and user-defined operations.

For each subroutine call during runtime, the low level must handle the following details behind the scene:
- Passing parameters from the caller to the called subroutine
- Saving the state of the caller before switching to execute the called subroutine
- Allocating space for the local variables of the called subroutine
- Jumping to execute the called subroutine
- Returnng values from the called subroutine back to the caller
- Recycling the memory space occupied by the called subroutine, when it returns
- Reinstating the state of the caller
- Jumping to execute the code of the caller immediately following the spot where we left it

### Program Flow

The default execution of computer programs is linear, one command after the other.This sequential flow is occasionally broken by branching command. These are accomplished using the low-level implementations of the VM command:
- *label*
- *goto label*
- *if-goto label*

#### Subroutine calling

Each programming language is characterized by a fixed set of built-in commands. The key abstraction mechanism provided by modern languages is the freedom to extend this basic repertoire with high-level, programmer-defined operations. In procedural languages, the high-level operations are called *subroutines, procedures*, or *functions*, and in object-oriented languages, they are usually called *methods*. We will refer all of them as *subroutines*.

Stack refers to global stack. 
