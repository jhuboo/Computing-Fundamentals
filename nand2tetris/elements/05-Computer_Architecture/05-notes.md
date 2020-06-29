## Computer Architecture

This is the "pinnacle" of the hardware part of our journey. We are now ready
to take all the chips that were built so far, and integrate them into a general-
purpose computer capable of running stored programs written in the machine
language in 04-notes. We will be exploring the *von Neumann architecture* - a
central dogma in computer science underlyin the design of almost all modern
computers.

### Background

#### The Stored Program Concept
The most unique feature of the digital computer is its incredible versatility.
This remarkable versatility comes from the groundbreaking idea called the 
***stored program*** concept. This concept is considered by many to be the most
profound invention, if not the very foundation of, modern computer science.

The underlying idea in itself is quite simple. The computer is based on a fixed
hardware platform, capable of executing a fixed repertoire of instructions. At
the same time, these instructions can be used and combined to give way to quite
sophisticated programs. Since the logic of these programs is not embedded in the
hardware, and is instead stored and manipulated in the computer's memory, *just
like data*, we can leverage this to use the same hardware platform to behave
completely differently each time it is loaded with a different program.

#### The von Neumann Architecture
The stored program concept is a key element of many abstract and physical
computer models, most notably the *universal Turing Machine (1936)* and the
*von Neumann machine (1945)*. The Turing machine - an abstract artifact describing
a deceptively simple computer - is used mainly to analyse the logical foundations
of computer systems. In contrast, the von Neumann machine is a practical
architecture and the conceptual blueprint of almost all computer platforms today.

The von Neumann architecture is based on a *central processing unit (CPU)*, 
interacting with a *memory* device, receiving data from some *input* device, and
sending data to some *output* device. At the heart of this architecture lies
the stored program concept. The computer's memory stores not only the data that
the computer manipulates, but also the very instructions that tell the computer
what to do. As mentioned, the main central components are:
- CPU
    - the centerpiece of the computer's architecture is in charge of executing the instructions in the currently loaded porgram. These instructions tell the CPU to carry out various calculations, to read and write values from or into the memory, and to conditionally jump to execute other instructions in the program. The CPU can be described as a repeated loop: fetch an instruction (word) from memory; decode it; execute it, fetch the next instruction, and so on. The CPU executes these tasks using three main hardware elements:
        - ALU   // Built to perform all low-level arithmetic & logical operations
        - Registers // high-speed registers to store results locally for rapidity
        - Control Unit  // Decode computer instructions & figure out which instruction to fetch and execute next
- Memory
    - the memory hold two types of information: *data items* and *programming instructions*. Both types of information are represented as binary numbers that are stored in the same generic random-access structure: a continuous array of cells of some fixed width, also called *words* or *locations*, each having a *unique address*. Hence an individual word (representing either a data item or an instruction) is
specified by supplying its address.
        - Data Memory // High level programs manipulate abstract artifacts like variables, arrays, and objects. When translated into machine langauge, these data abstractions become a series of binary numbers, stored in the computer's data memory. Once an individual word has been selected from the data memory by specifying its address, it can either be *read* or *written* to. 
        - Instruction Memory // When translated into machine language, each high-level command becomes a series of binary words, representing machine language instructions. These instructions are stored in the computer's *instruction memory*. In each step of the computer's operation, the CPU *fetches (reads)* a word from the instruction memory, decodes it, executes the specified instruction, and figures outwhich instruction to execute next. These instruction are written in an agreed-upon formalism called *machine language*.
- Registers
    - Memory access is a slow affair. When the CPU is instructed to retrieve the contents of address *j* of the memory, the following process ensures: a) j travels from the CPU to the RAM, b) the RAM's direct access logic selects the memory register whose address is j, c) the contents of RAM[j] travel back to the CPU. Registers provide the same service -data retrieval and storage - without the round-trip travel and serach expenses. First the registers reside physically inside the CPU chip, so accessing them is almost instantenous. Second there are only a handful of registers compared to millions of memory cells. Therefore, machine language instructions can specify which registers they want to manipulate using just a few bits, resulting in thinner instruction formats.
- Input and Output
    - Computers interact with their external environments using a diverse array of input and output (I/O) devices. Since each of these devices are different and unique pieces of engineering, computer scientists have devised various schemes to make all these devices look exactly the same to the computer. One such trick is ***memory-mapped I/O***.
    - The basic idea is to create a binary emulation of the I/O device, making it look to the CPU like a normal memory segment. As such, each I/O device is allocated an exclusive area of memory, becoming its "memory map". In the case of an *inputdevice* (keyboard, mouse), the memory map is made to continuously *reflect* the physical state of the device; in the case of an *output device*, the memory map is made to continously *drive* the physical state of the device. From a hardware point of view, this scheme requires each I/O device to provide an interface similar to that of a memory unit. While from a software perspective, each I/O device is requried to define an interactive contract, so that programs can access it directly.
    - The practical implications of a memory-mapped I/O architecture are significant. The design of the CPU and the overall platform can be totally independent of the number, nature, or make of the I/O devices that interact or will interact with the computer. When we want to connect a new I/O device, all we have to do is allocate to it a new memory map, and take note of its base address. From this point onward, any program that wants to manipulate this I/O device can do so by manipulating bits in memory.


#### CPU of the Hack Platform
```
    Chip name: CPU              // Central Processing Unit
    Inputs   : inM[16],         // M value inputs (M = contents of RAM[A])
               instructions[16],// Instructions for execution
               reset            // Resets current program (reset=1) or continue execuiton (reset=0)
    Outputs  : outM[16],        // M value output
               writeM,          // Write to M?
               addressM[15],    // Address of M in data memory
               pc[15],          // Address of next instruction
```

#### ROM of the Hack Platform
```
    Chip name: ROM32K           // 16-bit read-only 32K memory
    Input    : address[15]      // Address in the ROM
    Output   : out[16]          // Value of ROM[address]
    Function : out=ROM[address] // 16-bit assignment
```

#### I/O Basics devices of Hack Platform
```
    Chip name: Screen           // Memory map of the physical screen
    Inputs   : in[16],          // What to write
               load,            // Write-enable bit
               address[13]      // Where to write
    Output   : out[16]          // Screen value at the given address
    Function : out(t) = Screen[address(t)](t)
               if load(t-1) then Screen[address(t-1)](t) = in(t-1)
               // It effectively functions exactly like a 16-bit 8K RAM
               // Has side effect of continously refreshing the screen
```

```
    Chip name: Keyboard         // Memory map of the physical keyboard
                                // Outputs the code of the currently pressed key
    Output   : out[16]          // ASCII code of pressed key
    Function : Outputs the code of the key presently pressed on the keyboard
               // This chip is continously refreshed from a physical keyboard unit
```

#### Implementation
```
    Chip name: Memory           // Complete memory address space
    Inputs   : in[16],          // What to write
               load,            // Write-enable bit
               address[15]      // Where to write
    Output   : out[16]          // Memory value at the given address
    Function : out(t) = Memory[address(t)](t)
               If load(t-1) then Memory[address(t-1)](t) = in(t-1) 
```

```
    Chip name: Computer         // Topmost chip of the Hack platform
    Input    : reset            
    Funtion  : When reset is 0, the program stored in the computer's ROM executes.
               When reset is 1, the execution of the program restarts.
               Thus to start a program execution, reset must be up(1) and then down(0).
```
