## Sequential Logic

The *combinational* chips built so far depend solely on *combinations* of
their input values. Theses chip are useful in the ALU, but cannot
***maintain state***. To build memory elements, we need *sequential chips*.

The act of "remembering something" is inherently time-dependent. To build
chips that remember information, we must first model the progression of time.

***The Clock*** , most computers have a master clock that is usually based on
an oscillator that alternates continuously between two phases 0-1, low-high,
tick-tock. The time elapsed between the beginning of a "tick" and the end of
a subsequent "tok" is called a *cycle*. Each clock cycle is taken to model
one discrete time unit. The current clock phase (tick or tock) is represented
by a binary signal. Using the hardware's circuitry, this signal is 
simultaneously broadcast to every sequential chip throughout the computer.

***Flip-Flops*** are the most elementary sequential elements in the computer.
*Data flip-flop (DFF)* is one variant of flip-flop whose interface consists
of a single-bit data input and a single bit data output. In addition, the 
DFF has a clock input that continuously changes according to the master clock
signal. Taken together, the data and the clock inputs enable the DFF to 
implement the time based-behaviour ***out(t) = in(t-1)***.
This forms the basis of all hardware devices that computers use to maintain
state, from binary cells, to registers to arbitrarily large RAM units.

***Registers*** are storage devices that can remember a value over time,
implementing the classical storage ***out(t) = out(t-1)***. This means that a
register can be implemented from a DFF by simply feeding its output back
to its input. We can then extend this mechanism to construct arbitrarily
wide registers. This can be done by forming an array of many single-bit
registers as needed, creating a register that holds multi-bit values. The basic
design paramter is usually the *width* which is usually 32 or 64. The multi-bit
contents of such registers are typically refered to as *words*.

***Memories***, once we have the basic abiity to represent words, we can proceed
to build memory banks of arbitrary length. This can be done by stacking together
many registers to form a ***Random Access Memory (RAM)*** unit. The term *RAM*
derives from the requirement that read/write operations on a RAM should be able
to access randomly chosen words, with no restrictions on the order in which
they accessed. This means that any word in the memory - irrespetive of its 
physical location - should be able to be accessed directly in equal speed.
- We satisfy this requiremnt by first assigning each word in the n-register RAM a *unique addresss* (0 <= addresss < n), according to which it will be accessed.
- Second, we build a gate logic design that given an address *j*, is able to select the individaul register whose address is *j*

***Counters*** are sequential chips whose state is an int number that increments
every time unit, effecting the function ***out(t) = out(t - 1) + c***, where c
is typically 1. Counters play an important role in digital architectures. For 
instance, a typical CPU includes a program counter whose output is interpreted
as the address of the instruction that should be executed next in the current
program.

***Time Matters***, all chips described here up till now are *sequential*. 
Essentially, a *sequential* chip is one that embeds one or more *DFF* gates,
either directly or indirectly. 
- In combinational chips, where time is neither modelled nor recognized, the introduction of feeback loops is complicated as feeding the output would end up depending on itself.
- In sequential chips, this is not a problem because the *DFFs* introduce an inherent time delay, meaning that the output at time t does not depend on itself, but rather on the output at t - 1.
This "dicretization" of the sequential chips' outputs has an important side
effect; it can be used to synchronize the overall computer architecture. All
we have to ensure is that when we build the computer clock, the length of the
clock cycle will be slightly longer than the time it takes a bit to travel the 
longest distance from one chip in the architecture to another. This way, we are
guaranteed that by the time, the sequential chip updates its state (at the 
beginning of the next clock cycle), the input it receives from the ALU is valid.
This synchronizes a set of stand-alone hardware components into a well-
coordinated system.


### Hierarchy of Sequential Chips
- Data Filp-flops (DFFs)
- Registers (based on DFFs)
- Memory Banks (based on registers)
- Counter chips (based on register too)

#### DFF
They enter the computer architecture at a very low level, since all sequential
chips are based on numerous DFF gates. All the DFFs are connected to the same
master clock, forming a huge distributed "chorus line". At the beginning of each
clock cycle, the outputs of ***all*** the DFFs in the computer commit to their
inputs during the previous time unit. This conduction operation effects any one
of the millions of DFF gates that make up the system, about a billion times 
per second (depending on the computer's clock frequency). Hardware implementations
achieve this time dependency by simultaneously feeding the master clock to all
the DFF gates in the platform.
```
    Chip name: DFF
    Inputs   : In
    Outputs  : Out
    Function : out(t) = in(t - 1)
```

#### Registers
A single-bit register (Bit / binary cell) is designed to store a single bit of
information (0 or 1). 
```
    Chip name: Bit
    Inputs   : in, load
    Outputs  : out
    Function : If load(t-1) then out(t) = in(t-1)
                            else out(t) = out(t-1)
```
```
    Chip name: Register     // Multiple-bit values
    Inputs   : in[16], load
    Outputs  : out[16]
    Function : If load(t-1) then out(t) = in(t-1)
                            else out(t) = out(t-1)  // "=" is a 16-bit operation
```

#### Memory
A direct-access memory unit, called RAM, is an array of *n w*-bit registers, 
equipped with direct access circuitry, where *n* = memory's *size* and *w* =
memory's *width*. Hence, we have the hierarchy of RAM8, RAM64, RAM512, RAM4K,
RAM16K, ... and so on.
- Read: to read contents of register number *y*, we put y in the address input.
The RAM's direct access logic will select register *y*, which will then emit its
output value to the RAM's output pin. This is a combinatorial operation,
independent of the clock.
- Write: To write new data value *d* into the register *y*, we put *y* in the
address input, *d* in the input, and assert the load bit input bit. This causes
the RAM's direct-access memory to select register number *m* and the load bit
to enable it. This is a sequential operation, as in the next clock cycle, the
selected register will commit to the new value and the RAM's output will start
emitting it.
```
    Chip name: RAMn
    Inputs   : in[16], address[k], load
    Outputs  : out[16]
    Function : out(t) = RAM(address(t)](t)      // "=" is a 16-bit operation
               If load(t-1) then RAM[address(t-1)](t) = in(t-1)
```

#### Counter
The counter's interface is similar to that of a register, except it has two
additional control bits label *reset* and *inc*. (One possible use case might
be for the counter chip to contain the address of the instruction that the
computer should fetch and execute next).
- When inc=1, the counter increments its state in every clock cycle, emitting
the value *out(t) = out(t-1) + 1*
- The reset bit is used to *reset* the counter back to its start value, which
may be an arbitrary number n or 0.

```
    Chip name: PC       // 16-bit counter
    Inputs   : in[16], inc, load, reset
    Outputs  : out[16]
    Function : If reset(t-1) then out(t) = 0
               If  load(t-1) then out(t) = in(t-1)
               If   inc(t-1) then out(t) = out(t-1) + 1
                             else out(t) = out(t-1)
```


The abstraction present is quite incredible, we start from flip-flop gates, and
use them for istance to build registers, which are in turn used to build RAM8,
which is in turn used in RAM64, and so on...
