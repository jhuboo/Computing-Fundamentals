## Boolean Arithmetic

We will build gate logic designs that represent numbers and perform
arithmetic operations on them. We start with the basic logic gates
from 01-notes, and go all the way up to a fully functional ALU.

The ALU is the centerpiece chip/gate that executes all the arithmetic
and logical operations performed by the computer.

It is quite remarkable that most operations performed by digital computers
can be reduced to elementary additions of binary numbers.


#### Binary Numbers

The binary system is founded on base 2.
- The binary code for the number 21 is 10101
- In a 32-bit machine, it is stored as 00000000000000000000000000010101

#### Binary Addition

A pair of binary numbers can be added digit by digit from right to left,
according to the same elementary addition method used in decimal addition.
We start with the Least Significant Bits (LSB) of the two binary numbers,
and work our way all the way up the significance ladder; that is, until
the two most significant bits (MSB) are added. (There is deep appreciation
of the NAND Gate at work here!)

#### Signed Binary Numbers

A binary system with *n* digits can generate a set of 2^n different bit
patterns. To represent signed numbers in binary code, we split this space
into two equal subsets; one for positive , and one for negative numbers.

Almost all computers used the *2's complement* method (aka *radix complement*)
to represent signed numbers in binary code. ('-x' is x-complement)

``` -x = 2^n - x  if x != 0 else 0 ```

While ```n + (-n) = 0``` for the above method,
A quick trick is to leverage the power of -1:
```
     n + (-n - 1) = -1      // n is positive 
     In base 4:
        0 + -1 = 0000 + 1111 = 1111 == -1
        1 + -2 = 0001 + 1110 = 1111 == -1
        ...
        7 + -8 = 0111 + 1000 = 1111 == -1 
```

This reduces hardware complexity significantly:
- Subtraction can be performed as x - y = x + (-y)

Aha! We can see that a single chip, the ALU, can be used to encapsulate all
the basic arithmetic and logical operators performed in hardware.


### Specificaton

#### Adders
- Half-adder: designed to add two bits
- Full-adder: designed to add three bits
- Adder     : designed to add two *n-bit* numbers

```
    Chip name: HalfAdder        // designed to add two bits
    Inputs   : a, b
    Outputs  : sum, carry
    Function : sum   = LSB of a + b
               carry = MSB of a + b
```

```
    Chip name: FullAdder
    Inputs   : a, b, c
    Outputs  : sum, carry
    Function : sum   = LSB of a + b + c
               carry = MSB of a + b + c
```

```
    Chip name: Add16        // 16-bit adder
    Inputs   : a[16], b[16]
    Outputs  : out[16]
    Function : out = a + b  // Overflow is neither detected nor handled
```

```
    Chip name: Inc16        // Convenient to have incremeter chip to add 1
    Inputs   : in[16]
    Outputs  : out[16]
    Function : out = in + 1 // Overflow is neither detected nor handled
```

### The Arithmetic Logic Unit (ALU)

```
    Chip name: ALU
    Inputs   : x[16], y[16]     // Two 16-bit data inputs
               zx,              // Zero the x input
               nx,              // Negate the x input
               zy,              // Zero the y input
               ny,              // Negate the y input
               f,               // Function code: 1 for Add, 0 for And
               no               // Negate the out output
    Outputs  : out[16],         // 16-bit output
               zr,              // True iff out=0
               ng               // True iff out<0
    Function : if zx then x = 0     // 16-bit zero constant
               if nx then x = !x    // Bit-wise negation
               if zy then y = 0     // 16-bit zero constant
               if ny then y = !y    // Bit-wise negation
               if f then out = x + y    // Integer 2's complement addition
                    else out = x & y    // Bit-wise And
               if no then out = !out    // Bit-wise negation
               if out=0 then zr = 1 else zr = 0     // 16-bit eq. comparison
               if out<0 then ng = 1 else ng = 0     // 16-bit eq. comparison
```

#### ALU Truth Table

| zx | nx | zy | ny | f | no | out= |
| -- | -- | -- | -- | --| -- | :--: |
| 1  | 0  | 1  | 0  | 1 | 0  |  0   |
| 1  | 1  | 1  | 1  | 1 | 1  |  1   |
| 1  | 1  | 1  | 1  | 1 | 1  | -1   |
| 0  | 0  | 1  | 1  | 0 | 0  |  x   |
| 1  | 1  | 0  | 0  | 0 | 0  |  y   |
| 0  | 0  | 1  | 1  | 0 | 1  | !x   |
| 1  | 1  | 0  | 0  | 0 | 1  | !y   |
| 0  | 0  | 1  | 1  | 1 | 1  | -x   |
| 1  | 1  | 0  | 0  | 1 | 1  | -y   |
| 0  | 1  | 1  | 1  | 1 | 1  | x+1  |
| 1  | 1  | 0  | 1  | 1 | 1  | y+1  |
| 0  | 0  | 1  | 1  | 1 | 1  | x-1  |
| 1  | 1  | 0  | 0  | 1 | 1  | y-1  |
| 0  | 0  | 0  | 0  | 1 | 0  | x+y  |
| 0  | 1  | 0  | 0  | 1 | 1  | x-y  |
| 0  | 0  | 0  | 1  | 1 | 1  | y-x  |
| 0  | 0  | 0  | 0  | 0 | 0  | x&y  |
| 0  | 1  | 0  | 1  | 0 | 1  | x|y  |

We here used the basic concepts of the gates (primitive operations) to
design the ALU to be simple, and elegant.
