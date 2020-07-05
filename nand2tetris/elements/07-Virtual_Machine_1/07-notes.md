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

#### Arithmetic and Logical Commands

The VM languae features 9 stack-oriented arithemtic and logical commands. Seven of these commands are binary. Two of them are unary.

| Command | Return Value | Comment |
| --- | --- | --- |
| add | x + y | Integer addition (2's complement) |
| sub | x - y | Integer subtraction " |
| neg | -y | Arithmetic negation " |
| eq  | true if x = y, else false | Equality |
| gt  | true if x > y, else false | Greater than |
| lt  | true if x < y, else false | Less than |
| and | x And y | Bit-wise |
| or  | x Or y | Bit-wise |
| not | Not y | Bit-wise |

#### Memory Access Commands

So far in the chapter, memory access commands were illustrated using the pseudo commands *pop* or *push x*, where x refered to an individual location in some global memory. Yet formally, our VM manipulates eight separate *virtual memory segments*. All the memory segments are accessed by the same two commands:
- push *segment index*  Push the value of segment[index] onto the stack
- pop *segment index* Pop the top stack value and store it in segment[index]

| Segment | Purpose | Comments |
| --- | --- | --- |
| argument | Stores the function's arguments | Allocated dynamically by the VM implementation when the function is entered |
| local | Stores the function's local varialbes | Allocated dynamically by the VM implementation and initialized to 0's when the function is entered |
| static | Stores staic varialbes shared by all functions in the same .vm file | Allocated by the VM imp. for each .vm file; shared by all functions in the .vm file |
| constant | Pseudo-segment that holds all the constants in the range 0...32767 | Emulated by the VM implementation; Seen by all the functions in the program |
| this, that | General-purpose segments. Can be made to correspond to different areas in the heap. Serve various programming needs | Any VM function can use these segments to manipulate selected areas on the heap |
| pointer | A two-entry segment that holds the base address of the *this* and *that* segments | Any VM function can set *pointer 0 (or 1)* to some address; this has the effect of aligning the *this (or that)* segment to the heap area beginning in that address |
| temp | Fixed eight-entry segment that holds temporary varialbles for general use | May be used by any VM function for any purpose. Shared by all functions in the program |

In addition to the eight memory segments, which are managed explicitly by VM push
and pop commands, the VM implementation manages two implicit data strutures called
*stack* and *heap*. These data structures are never mentioned directly, but their
states change in the background, as a side-effect of VM commands.
- ***Stack*** - consider the commands sequence *push argument 2* and *pop local 1*. The working memory of such VM operations is the *stack*.
- ***Heap*** - the *heap* is the name of the RAM area dedicated for storing objets and arrays data.

### Program Flow and Function Calling Commands
The VM features six additional commands:
- ***Program Flow Commands***
    - label *symbol* // label declaration
    - goto *symbol*  // unconditional branching
    - if-goto *symbol* // conditional branching
- ***Function Calling Commands*** (*functionName* is a symbol)
    - function *functionName nLocals*   // Function declaration, specifying the number of function's local variables
    - call *functionName nArgs*         // Function invocation, specifying the number of the function's arguments
    - return                            // Transfer control back to the calling function

### VM Programming Examples
We will illustrate how the compiler developed in 10 and 11 will use the VM
abstarction to translate high-level programs into VM code.

When a VM function stars running, it assumes that
- the stack is empty
- the argument values on which it is supposed to operate are located in the *argument* segment.
- the local variables that it is supposed to use are initialized to 0 and located in the *local* segment.

- ***A Typical Arithmetic Task***
    - Since VM commands cannot use symbolic argument and variable names, they are limited to making <*segment index*> references only. However, the translation of the former to the latter is simple. All we have to do is to map *x, y, sum* and *j* on *argument 0, argument 1, local 0, and local 1*, respectively and replace their symbolic occurences in the pseudo code with corresponding <*segment index*> refs.
    - ```
        int mult(int x, int y) {
            int sum;
            sum = 0;
            for (int j = y; j != 0; j--)
                sum += x;       // Repetitive addition
            return sum;
        }
    - ```
        function mult
            args x, y
            vars sum, j
            sum = 0
            j = y
        loop:
            if j = 0 goto end
            sum = sum + x
            j = j - 1
            goto loop
        end:
            return sum    
    - ```
        function mult(x, y)     |   function mult 2    // 2 local variables
            push 0              |       push constant 0
            pop sum             |       pop local 0     // sum = 0
            push y              |       push argument 1
            pop j               |       pop local 1     // j = y
        label loop              |   label loop
            push 0              |       push constant 0
            push j              |       push local 1
            eq                  |       Eq
            if-goto end         |       if-goto end     // if j = 0 goto end
            push sum            |       push local 0
            push x              |       push argument 0
            add                 |       Add
            pop sum             |       pop local 0     // sum = sum + x
            push j              |       push local 1
            push 1              |       push constant 1
            sub                 |       Sub
            pop j               |       pop local 1     // j = j - 1
            goto loop           |       goto loop
        label end               |   label end
            push sum            |       push local 0
            return              |       return          // return sum

- ***Array Handling***
   - An array in an index collection of objects. Suppose that a high-level program has created an array of ten integers called *bar* and filled it with some ten numbers.. Let's assume that the array's base has been mapped (behind the scene) on RAM address 4728. Suppose now that the high level program wants to execute the command *bar[2] = 19*. How can this operation be implemented at the VM level?
    - In the C language, such an operation can be done as */*(bar+2)=19*
    - This means *set the RAM location whose address is (bar+2) to 19.* 
    - ```
        /* Assume that the bar array is the first local variable declared in the high-level program. The follow VM code implements the operation bar[2] = 19, ie. *(bar+2)=19. */
        push local 0        // Get bar's base address
        push constant 2
        add
        pop pointer 1       // Set that's base to (bar+2)
        push constant 19
        pop that 0          // *(bar+2)=19
        ...`

- ***Object Handling***
    - High-level programmers view objects as entities that encapsulate data (organized as *fields*, or *properties*) and relevant code (organized as *methods*). Yet physically speaking, the data of each object instance is serialized on the RAM as a list of numbers representing the object's field values. Thus the low-level handling of objects is quite similar to that of arrays.
        
    

