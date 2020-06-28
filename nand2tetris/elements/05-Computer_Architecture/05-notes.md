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
        - Control Unit  // Decode computer instructions & figure out next steps
- Memory
- Registers
- Input and Output

