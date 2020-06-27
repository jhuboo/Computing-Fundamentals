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
