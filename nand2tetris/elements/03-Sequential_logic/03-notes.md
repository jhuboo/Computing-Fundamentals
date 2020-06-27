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
We satisfy this requiremnt by assigning each word in the n-register RAM a 
*unique addresss* (0 <= addresss < n), according to which it will be accessed.

