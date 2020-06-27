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
        2 + -3 = 0010 + 1101 = 1111 == -1
        ...
        7 + -8 = 0111 + 1000 = 1111 == -1 
```
