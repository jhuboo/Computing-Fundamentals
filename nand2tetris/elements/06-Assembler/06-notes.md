## Assembler

The first and most basic module in a software hierarchy is the *assembler*.
We will explore how the assembler can systematically translate programs written
in their assembly representations to their binary ones.

### Background

Machine languages are typically specified in two flavors: *symbolic* and *binary*.
The binary codes 11000010100000011000000000000011 represent actual machine
instructionss, as understood by the underlying hardware. For example, the 
instruction's leftmost 8 bits can represent an operaton code, say LOAD, the next
8 bits a register, say R7, and the remaining 16 bits an address, say 3. The 
overall 32-bit pattern can thus cause the hardware to effect the operation
*"load the content of Memory[3] into register R7"*. 

Since dealing with millions of such elementary tasks can be quite tedious, we
can use a symbolic notation that maps to the underlying binary code. The program
that translates this symbolic language, also called *assembly*, to binary code
is called the *assembler*. Hence, the assembler parses each assembly command into
its underlying fields, translates each field into its equivalent binary code, and
assembles the generated codes into a binary instruction that can actually be
executed by the underlying hardware.

#### Symbols
Binary instructions are represented in binary code. By definiton, they refer to
memory addresses using actual numbers. Suppose for instance, we have a program
that has a variable *var* which has been mapped on location *3* of the memory.
At the binary code level, instructions that manipulate weight must refer to it
using the explicit address *3*. The power of assembly starts shining as when we
write a command as *LOAD R5,var* instead of writing the more tedious *LOAD R5,3*.
In both cases, the underlying operation will be the same; "set register R5 to
the contents of Memory[3]". In a similar fashion, rather than using comamnds
*goto 180*, assembly languages allow command like *goto loop*, assuming that
somewhere in the program, the symbol *loop* is made to refer to address 180.
Symbols are introduced into assembly programs from two sources:
- *Variables* - symbolic names that the translator will "automatically" assign to a memory address.
- *Labels* - various locations in the program can be marked with symbols, ie loop, end, etc... Other commands an then *goto loop*, either conditionally or unconditionally.

#### Symbol Resolution
The mapping of user-defined variable names, and symbolic lables on actual memory
addresses is not trivial. Let's consider a program in a low-level language that
adds 1 to 100.

To begin, we will make two arbitrary rules:
- the translated code will be stored in the computer address starting at address 0
- variables will be allocated to memory locations starting at address 1024
- Next, we build a *symbol table*. For each new symbol *xxx* encountered in the source code, we add a line (xxx, n) to the symbol table, where *n* is the memory address associated with the symbol according to the game rules.

| Code with Symbols | Symbol Table | Code with symbols resolved |
| --- | --- | --- |
| i = 1 | i  1024 | 00 - M[1024]=1  // M=memory |
| sum = 0 | sum  1025 | 01 - M[1025]=0 |
| loop: | | |
| if i=101 gotoend | loop  2 | 02 - if M[1024]=101 goto 6 |
| sum = sum + i |  | 03 - M[1025]=M[1025] 
| i = i + 1 | | 04 - M[1024] = M[1024] + 1 |
| goto loop | | 05 - goto 2 |
| end: | | |
| goto end | end 6 | 06 - goto 6 |

#### The Assembler
The assembler takes as input a stream of assembly commands and generates as output
a stream of equivalent binary instructions. The resulting code is loaded as is 
into the computer's memory and executed by the hardware. The assemlber is basially
a text-processing program, designed to provide translation services. Using the
*machine language specification*, we can write a program that:
- Parses the symbolic command into its underlying fields
- For each field, generate the corresponding bits in the machine language
- Replace all symbolic references (if any) with numeric addresses of memory locations
- Assemble the binary codes into a complete machine instruction

| Assembly code (Prog.asm) | Binary code (Prog.hack) |
| --- | --- |
| // Adds 1 + ... + 100 | (this line should be erased) |
| @i  | 0000 0000 0001 0000 |
| M=1     // i=1 | 1110 1111 1100 1000 |
| @sum | 0000 0000 0001 0001 |
| M=0     // sum=0 | 1110 1010 1000 1000 |
| ***(LOOP)*** | (this line should be erased) |
| @i | 0000 0000 0001 0000 |
| D=M     // D=i | 1111 1100 0001 0000 |
| @100 | 0000 0000 0110 0100 |
| D=D-A   // D=i-100 | 1110 0100 1101 0000 |
| @END | 0000 0000 0001 0010 |
| D;JGT   // if (i-100)>0 goto END | 1110 0011 0000 0001 |
| @i  | 0000 0000 0001 0000 |
| D=M     // D=i  | 1111 1100 0001 0000 |
| @sum | 0000 0000 0001 0001 |
| M=D+M   // sum=sum+i | 1111  0000 1000 1000 |
| @i  | 0000 0000 0001 0000 |
| M=M+1   // i=i+1 | 1111 1101 1100 1000 |
| @LOOP | 0000 0000 0000 01000 |
| 0;JMP   // goto LOOP | 11110 1010 1000 0111 |
| ***(END)*** | (this line should be erased) |
| @END | 0000 0000 0001 0010 |
| 0;JMP   // infinte loop | 1110 1010 1000 0111 |


