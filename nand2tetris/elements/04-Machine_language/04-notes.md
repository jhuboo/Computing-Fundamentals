## Machine Language

A machine language is an agreed-upon formalism, designed to code low-level
programs as series of machine instructions. It is the most profound interface
in the overall computer as it is the fine line where hardware and software
meet.

Using these instructions, we can command the processor to perform arithmetic
and logic operations, fetch and store values from and to the memory, move
values from one register to another, test Boolean conditions, etc... In
contrast to higher level languages' generality and power of expression, 
machine language is designed to directly execute and fully control the given
underlying hardware. Understanding machine language is essential for a complete
understanding of computer architectures. It is quite incredible how most of
the sophisticated software systems are at their very core just long series of
elementary instructions, each specifying a very simple and primitive operation
in the underlying hardware.

### Machines

A machine language can be viewed an agreed-upon formalism, designed to manipulate
a *memory* using a *processor* and a set of *registers*.

***Memory*** refers to the collection of hardware devices that store data
and instructions in a computer. From the programmer viewpoint, all memories
share essentially the same structure, they are a continuous array of cells of
some fixed width also called *words* or *locations*, each having a *unique
address*. Hence, each individual word (representing either an instruction or
data item) is supplied by specifying its addresss. We refer to such individual
words using the notation Memory[address], RAM[address] or M[address].

***Processor*** also called the *Central Processing Unit (CPU)* is a device
capable of performing a fixed set of elementary operations. These typically
include arithmetic and logic operations, memory access operations, and control
(also called *branching*) operations. The operand of these operations are binary
values that come from registers and selected memory locations. Likewise, the 
results of the operations (the processor's output) can be stored either in
registers or in selected memory locations.

***Registers***, since accessing memory is a relatively slow operation, most
processors are equipped with several registers, each capable of holding a
single value. Locating with the processor's proximity, the registers serve as
a high-speed local memory, allowing the processor to manipulate data and 
instructions quickly. This setting enables the programmer to minimize use of
memory access commands, thus speeding up the program's execution.


### Languages

A machine Language is a series of coded instructions. For instance, in a 16-bit
computer, an instruction might be 1010001101100011. To know what this means, we
have to know the rules of the game, namely the instruction set of the underlying
hardware platform. Say for instance, the language is such that each instruction
contains four 4-bit fields. The Left most field (1010) codes the CPU operation,
and the remaining three fields (0011)(0110)(0011) represent the operation's 
operands. It might be *addto R3 <- R6 + R3*.

Since binary code is not very human-readable, machine languages are normally
specified using binary codes and symbolic mnemonics. For instance, the operation
code (1010) might be represented by ***add*** and the registers can be 
represented using R0, R1, ..., RN. These conventions make it much easier to
specify machine language instructions.

A assembler takes assembly assembly language and translates it to its equivalent
binary machine instructions.


### Commands

#### Arithmetic and Logic Operations
Every comptuer is required to perform basic arithmetic operations such as
addition, subtraction as well as basic Boolean operations like bit-wise negation,
bit shifting, and so forth.
```
    ADD R2,R1,R3     // R2 <- R1 + R3 where R1,R2,R3 are registers
    ADD R2,R1,foo    // R2 <- R1 + foo where foo is the value of memory location
    ADD R1,R1,R2     // R1 <- bit wise And of R1 and R2
```

#### Memory Access
Memory access commands fall into two categories:
- First as we have seen, arithmeitc and logical commands are allowed to
opearte not only on registers but also on selected memory locations
- Second, all computers feature explicit *load* and *store* commands designed to
move data between registers and memory. These memory access commands may use
several types of *addressing modes* - ways of specifying the address of the
required memory word.
    - ***Direct addressing***, The most common way to address the memory is to express a specific address or use a symbol that refers to a specific address:
``` 
    LOAD R1,67      // R1 <- Memory[67]
    LOAD R1,bar     // R1 <- Memory[67], assuming bar refers to memory address 67
```
    - ***Intermediate addressing***, This form of addressing is used to load constants - namely, load values that apper in the instruction code: Instead of treating numeric field that appears in the instruction as an address, we simply load the value of the field into the register:
```
    LOADI R1,67     // R1 <- 67
```
    - ***Indirect addressing***, the instruction here specifies a memory location that holds the required address. This is used to handle *pointers*.
```
    // Translation of x=foo[j] or x=*(foo+j):
    ADD R1,foo,j    // R1 <- foo + j
    LOAD* R2,R1     // R2 <- Memory[R1]
    STR R2,x        // x <- R2
```

#### Flow of Control

