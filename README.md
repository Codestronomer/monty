# Monty
An interpreter for `Monty Bytecode files`, which a scripting language just like Python

### About The Monty language
Monty is a scripting language that is first compiled into Monty byte codes, It relies on a unique stack, with specific instructions to manipulate it.

### Monty byte code files
Files containing Monty byte codes that usually have the .m extension. Example: `file.m`
Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
$ cat file.m
# Pushing element to the stack
push 0
push 1
push 2
# Printing all elements
pall
push 3
push 4
pop
# Rotating the stack to the bottom
rotr
pall
rotl
# Setting FIFO
queue
push 5
# Setting LIFO
stack
push 5
$
```
## Technologies
- Interpreter was written with the `C language`
- C files compiled using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
- Tested on Ubuntu 20.04 LTS
---
## Usage
To compile all files:
```
$ gcc -Wall -Wextra -Werror -pedantic *.c -o monty
$
```
Syntax of interpreter:
```
$ monty [filename]
$
```
