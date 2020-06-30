## Virtual Machine 1: Stack Arithmetic

We will be describing the first steps toward building a *compiler* for a typical
high-level language. This task is divided into two stages: i) High-level programs
will be translated into an intermediate code, ii) the intermediate code will then
be translated inot machine language. The basic idea is as follows: Instead of
running on a real platform, the intermediate code is designed to run on a
*Virtual Machine (VM)*.

A virtual machine model typically has a language, in which one can write VM 
programs. The VM language that is presented here consists of 4 types of commands:
arithmetic, memory access, program flow, and subroutine calling commands. We
split the implementation of this language into two parts, 07 and 08. In this
chapter, 07, we will build a basic VM translator, capable of translating the 
VM's arithmetic and memory access commands into machine language. In chapter 08,
we extend the basic translator with program flow and subroutine calling
functionality. The result is a full-scale virtual machine that will server as the
backend of the compiler that we will build in chapter 10 and 11.

Build a VM illustrates several important CS ideas:
- 1. The notion of having one computer emulating another is a fundamental idea in the field, dating back to Turing in the 1930s. It has many practical implications, for example using an emulator of an old generation computer running on a new platform in order to achieve upward code compatibility.
- 2. More recently, the VM model became the centerpiece of two competing mainstreams - the Java architecture and the .NET infrastructure. Build a simple version of a VM gives us an inside view of their underlying structure.
- 3. We will also explore *stack processing* as part of this chapter. The *stack* is a fundamental and elegant data stucture that comes to play in may computer systems and algorithms. Since the VM prsented in this chapter is stack-based, it provides a working example of this remarkably versatile data structure.


### Background

#### The Virtual Machine Paradigm
Before a high-level program can run on a target computer, it must be translated into the computer's machine language. This translation -known as *compilation*- is a rather complex process. Normally a separate compiler is wirtten specifically for any given pair of high-level language and target machine language. This leads to the proliferation of many different compilers, each depending on every detail of both its source and destination languages. One way to decouple this dependency is to break the overall compilation process into two nearly separate stages. In the first stage, the high-level program is parsed and its commands are translated inot intermediate processing steps - neither 'high' nor 'low'. In the second stage, the intermediate steps are translated further into the machine language of the target hardware.

This decomposition process is very appealing from a software engineering perspective:
- the first stage depends only on the specifics of the source high-level language
- the second stage depends only on the specifics of the target machine language

The compiler, instead of being a single monolithic program is now split into two separate programs. This two-stage compilation model has been used in many compiler construction projects.

The notion of an explict and formal VM language has several pratical advantages.
- First compilers for different target platforms can be obtained with relative ease by replacing only the virtual machine implemetation (also called *compiler's backend*). This in turn, allows the VM code to be transportable across different hardware platforms, permitting a range of implementation trade-offs among code efficiency, hardware cost and programming effort.
- Second, compilers for many languages can share the same VM backend, allowing code sharing and language interoperability.
- Third, a VM approach also offers modularity. Every improvement in the efficiency of the VM implementations is immediately inherited by all the compilers above it. Likewise, every new device or appliance that is equipped with a VM implementation can immediately benefit from a huge base of available software.

#### The Stack Machine Model
Like most programming languages, the VM language consists of arithmetic, memory access, program flow and subroutine calling operations. One key question is *where will the operands and the results of the VM operations reside?* The cleanest solution, it seems, would be to put them on a *stack* data structure.

In a *stack machine* model, arithmetic commands pop their operands from the top of the stack and push their results back onto the top of the stack. Other commands transfer data items from the top of the stack to designated memory locations, and vice-versa. It is should be appreciated that any program, written in any programming language, can be translated into an equivalent stack machine.

- ***Elementary Stack Operations***: A stack is an abstract data structure that supports two basic operations: push and pop. Thus a stack implements a LIFO storage model.
    - One possible way to implement such a data structure is to keep an array, called *stack*, and a *stack pointer* variable, say *sp* that points to the available location just above the topmost element.
    - Push command: ``` stack[sp]=x; sp=sp+1 ```
    - Pop  command: ``` sp=sp-1; return stack[sp] ```
- ***Stack Aritmetic***: The operands are  popped from the stack, and the required operation is performed on them, and the result is pushed back onto the stack. Anyarithmetic and Boolean expression, not matter how complex, can be systematically converted into and evaluated by a sequence of simple operations on a stack. Thus one can write a *compiler* that translates high-level arithmetic and Boolean expressions into sequences of stack commands, as done in chapters 10 and 11.


### VM Specification, Part 1

A virtual machine is *stack-based*: all operations are done on a stack. It is also *function-based*: a complete Vm program is oragnized in program units called *functions*, written in the VM language. Each function has its own stand-alone code and is separately handled. The VM languae a single 16, 32 or 64, here 16-bit data type that can be used as an integer, a Boolean, or a pointer. The language consists of four types of commands:
- *Arithmetic commands* (perform arithmetic and logical operations on the stack)
- *Memory access commands* (transfer data between stack and Virtual memory segments)
- *Program flow commands* (facilitate conditional and unconditional branching operations)
- *Function calling commands* (call functions and return from them)

```
    // d = (2-x)*(y+5)
    push 2
    push x
    sub
    push y
    push 5
    add
    mult
    pop d
```

```
    // if (x<7) or (y=8)
    push x
    push 7
    lt
    push y
    push 8
    eq
    or
```
