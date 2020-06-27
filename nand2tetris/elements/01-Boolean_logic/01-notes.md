## Boolean Logic

Every digital device is based on a set of chips designed to store
and process information. Although the chips can be quite different
they are all made up of ***elementary logic gates***. A gate is a
physical device that implements a boolean function.

Boolean algebra deals with true/false, on/off, 1/0 and so on.
Every Boolean function, no matter how complex, can be expressed
using three Boolean operators only: And, Or, Not.

##### Boolean Expression
- "And" : xy or x.y means x And y
- "Or"  : x + y means x Or y
- "Not" : !x means Not x


#### The Nand Gate
"God gave us the Nand Gate, the rest is down to people..."

| a | b | Nand(a,b) |
|---|---|   :--:    |
| 0 | 0 |     1     |
| 0 | 1 |     1     |
| 1 | 0 |     1     |
| 1 | 1 |     0     |

```
    Chip name: Nand
    Inputs   : a, b
    Outputs  : out
    Function : If a=b=1 then out=0 else out=1
```

#### Basic Logic Gates

```
    Chip Name: Not
    Inputs   : in
    Outputs  : out
    Function : If in=0 then out=1 else out=0
```

```
    Chip Name: And
    Inputs   : a, b
    Outputs  : out
    Function : If a=b=1 then out=1 else out=0
```

```
    Chip Name: Or
    Inputs   : a, b
    Outputs  : out
    Function : If a=b=0 then out=0 else out=1
```

```
    Chip Name: Xor
    Inputs   : a, b
    Outputs  : out
    Function : If a!=b then out=1 else out=0
```

```
    Chip Name: Mux
    Inputs   : a, b, sel
    Outputs  : out
    Function : If sel=0 then out=a else out=b
```

```
    Chip Name: DMux
    Inputs   : in, sel
    Outputs  : a, b
    Function : If sel=0 then {a=in, b=0} else {a=0, b=in}
```

#### Multi-Bit Versions of Basic Gates

Computer Hardware is designed to normally operate on multi-bit arrays
called "buses". We refer to the individual bits in a 16-bit bus named
data as such data[0], data[1], ..., data[15]

```
    Chip Name: Not16
    Inputs   : in[16]       // a 16-bit pin 
    Outputs  : out[16]
    Function : For i=0..15 out[i] = Not(in[i]) 
```
```
    Chip Name: And16 
    Inputs   : a[16], b[16] 
    Outputs  : out[16] 
    Function : For i=0..15 out[i] = And(a[i],b[i])
```
```
    Chip Name: Or16 
    Inputs   : a[16], b[16]
    Outputs  : out[16] 
    Function : For i=0..15 out[i] = Or(a[i],b[i]) 
```
```
    Chip Name: Mux16 
    Inputs   : a[16], b[16], sel
    Outputs  : out[16] 
    Function : If sel=0 for  i=0..15 out[i] = a[i]
                    else for i=0..15 out[i] = b[i]
```

#### Multi-Way Versions of Basic Gates

An *n-way* Or gate outputs 1 when at least one of its n bit inputs is 1
```
    Chip Name: Or8way
    Inputs   : in[8] 
    Outputs  : out 
    Function : out = Or(in[0], in[1], ..., in[7]) 
```

An ***m-way n-bit*** multiplexor selects one of *m n-bit* input buses
and outputs it to a single *n*-bit output bus.
```
    Chip Name: Mux4Way16
    Inputs   : a[16], b[16], c[16], d[16], sel[2] 
    Outputs  : out[16] 
    Function : If sel = 00, for i=0..15 then out[i] = a[i]
                  sel = 01, for i=0..15 then out[i] = b[i]
                  sel = 10, for i=0..15 then out[i] = c[i]
                  sel = 11, for i=0..15 then out[i] = d[i]
                
```

An ***m-way n-bit*** demultiplexor channels a single *n*-bit to one of *m*
possible *n-bit* outputs.
```
    Chip Name: DMux4Way
    Inputs   : in, sel[2] 
    Outputs  : a, b, c, d 
    Function : If sel = 00 then {a=in, b=c=d=0}
                  sel = 01 then {b=in, a=c=d=0}
                  sel = 10 then {c=in, a=b=d=0}
                  sel = 11 then {d=in, a=b=c=0} 
```


