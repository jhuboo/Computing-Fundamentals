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


