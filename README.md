<h1>Push_swap</h1>

<h2>Introduction</h2>

This project involves sorting a stack of integers named 'a' using various operations. The goal is to organize the numbers in stack 'a' in ascending order. To accomplish this, you have a set of operations available to manipulate the stacks and sort the elements.

<h2>Operations Available</h2>

- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss: Perform sa and sb simultaneously.
- pa (push a): Take the first element at the top of stack b and push it onto stack a.
- pb (push b): Take the first element at the top of stack a and push it onto stack b.
- ra (rotate a): Shift up all elements of stack a by 1.
- rb (rotate b): Shift up all elements of stack b by 1.
- rr: Perform ra and rb simultaneously.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
- rrr: Perform rra and rrb simultaneously.

<h2>Push_swap Program</h2>

The push_swap program sorts the stack 'a' with the fewest possible operations and displays the instructions required. Here are the specifications and requirements for the push_swap program:

Arguments: The stack 'a' formatted as a list of integers (first argument should be at the top of the stack).

Output: Display the smallest list of instructions possible to sort stack 'a'. Instructions should be separated by a '\n' character.

Evaluation Criteria: The goal is to sort the stack with the lowest possible number of operations. Your program's output will be compared against a maximum number of operations tolerated. If your program either displays a longer list of instructions or fails to sort the numbers properly, your grade will be 0.

Error Handling: In case of errors (e.g., non-integer arguments, duplicates, integer overflow), display "Error" followed by a '\n' on the standard error.

No Parameters: If no parameters are specified, the program should not display anything and return to the prompt.
