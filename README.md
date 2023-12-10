# Push_swap

## Table of Contents
- [Results](#results)
- [Introduction](#introduction)
- [Operations available](#operations-available)
- [Push_swap program](#push_swap-program)
- [Push-swap program usage](#push-swap-program-usage)
- [Checker program (bonus part)](#checker-program-bonus-part)
- [Description](#description)
- [Checker program usage](#checker-program-usage)

## Results

### Passed with 122/100 ✅

## Introduction

This Hive Helsinki (School 42) project involves sorting a stack of integers named 'a' using stack "b" and various operations. The goal is to organize the numbers in stack 'a' in ascending order. To accomplish this, you have a set of operations available to manipulate the stacks and sort the elements.

## Operations available

- ```sa``` (swap a): Swap the first 2 elements at the top of stack a.
- ```sb``` (swap b): Swap the first 2 elements at the top of stack b.
- ```ss```: Perform sa and sb simultaneously.
- ```pa``` (push a): Take the first element at the top of stack b and push it onto stack a.
- ```pb``` (push b): Take the first element at the top of stack a and push it onto stack b.
- ```ra``` (rotate a): Shift up all elements of stack a by 1.
- ```rb``` (rotate b): Shift up all elements of stack b by 1.
- ```rr```: Perform ra and rb simultaneously.
- ```rra``` (reverse rotate a): Shift down all elements of stack a by 1.
- ```rrb``` (reverse rotate b): Shift down all elements of stack b by 1.
- ```rrr```: Perform rra and rrb simultaneously.

## Push_swap program

The push_swap program sorts the stack 'a' with the fewest possible operations and displays the instructions required. Here are the specifications and requirements for the push_swap program:

Arguments: The stack 'a' formatted as a list of integers (first argument should be at the top of the stack).

Output: Display the smallest list of instructions possible to sort stack 'a'. Instructions should be separated by a '\n' character.

Evaluation Criteria: The goal is to sort the stack with the lowest possible number of operations. Your program's output will be compared against a maximum number of operations tolerated. If your program either displays a longer list of instructions or fails to sort the numbers properly, your grade will be 0.

Error Handling: In case of errors (e.g., non-integer arguments, duplicates, integer overflow), display "Error" followed by a '\n' on the standard error.

No Parameters: If no parameters are specified, the program should not display anything and return to the prompt.

## Push-swap program usage

To the code use "make" command to compile an executable and then run it like this:

```shell
./push_swap <numbers>
```

The numbers provided can be positive or negative integers. There must not be any duplicates.

```shell
./push_swap 9 0 -217 2147483647 -2147483648
```

If the arguments are valid, the program will output list of actions to sort the list according to the algorithm.

The program can be checked with the provided checker, like this :

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```

## Checker program (bonus part)

## Description:
The "checker" program is a crucial component for validating the sorting process of a stack of integers. This program works in conjunction with the 'push_swap' program and serves as a verification tool. It takes in a list of integers and executes a series of instructions provided via standard input. The primary objective is to confirm if the given instructions successfully sort the stack.

### Execution guidelines and validation criteria:

- The first argument represents the top of the stack 'a'.
- If no argument is provided, the program halts and displays nothing.
- Reads and executes instructions from standard input (each followed by '\n').
- Executes these instructions on the given stack.
- If after executing the instructions, stack 'a' is sorted, and stack 'b' is empty, it displays "OK" on the standard output followed by '\n'.
- For any other scenario, it displays "KO" on the standard output followed by '\n'.
- Errors are handled and displayed as "Error" on the standard error. These errors encompass non-integer arguments, integers exceeding limits, duplicates, invalid or incorrectly formatted instructions.

## Checker program usage

```shell
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

---
Made by dnikifor: dnikifor@student.hive.fi | LinkedIn: [dnikifor](https://www.linkedin.com/in/dmitriinikiforov/) | Tableau: [dmitriinikiforov](https://public.tableau.com/app/profile/nikiforov.dmitrii/vizzes)
