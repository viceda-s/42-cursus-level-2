# 🔄 Push_Swap

*This project has been created as part of the 42 curriculum by viceda-s.*

## Description

**Push_Swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The program uses two stacks (stack A and stack B) and a specific set of operations to sort the numbers in ascending order.

The goal is to implement an efficient sorting algorithm that minimizes the number of operations needed to sort any given set of integers. The project includes:
- The main `push_swap` program that outputs the sequence of operations needed to sort the stack
- A `checker` bonus program that validates whether a given sequence of operations correctly sorts a stack

This project teaches algorithmic optimization, data structure manipulation, and efficient problem-solving strategies.

## Instructions

### Compilation

To compile the project, use the provided Makefile:

```bash
# Compile the push_swap program
make

# Compile the bonus checker program
make bonus

# Clean object files
make clean

# Clean object files and binaries
make fclean

# Recompile everything
make re
```

### Execution

#### Push Swap Program

The `push_swap` program takes a list of integers as arguments and outputs the operations needed to sort them:

```bash
# Pass numbers as separate arguments
./push_swap 3 2 1 0

# Or pass numbers as a single string
./push_swap "3 2 1 0"
```

The program will output a sequence of operations (one per line) such as:
```
sa
rra
pb
...
```

#### Checker Program (Bonus)

The `checker` program reads a list of integers and then waits for operations on stdin. It verifies if the operations correctly sort the stack:

```bash
# Interactive usage
./checker 3 2 1 0
sa
rra
^D

# Using push_swap output
./push_swap 3 2 1 0 | ./checker 3 2 1 0
```

The checker will output:
- `OK` if the stack is sorted
- `KO` if the stack is not sorted
- `Error` if invalid operations are provided

### Available Operations

- `sa` : swap the first 2 elements at the top of stack A
- `sb` : swap the first 2 elements at the top of stack B
- `ss` : sa and sb at the same time
- `pa` : push the top element from stack B to stack A
- `pb` : push the top element from stack A to stack B
- `ra` : rotate stack A (shift all elements up by 1)
- `rb` : rotate stack B (shift all elements up by 1)
- `rr` : ra and rb at the same time
- `rra` : reverse rotate stack A (shift all elements down by 1)
- `rrb` : reverse rotate stack B (shift all elements down by 1)
- `rrr` : rra and rrb at the same time

### Error Handling

The program handles the following error cases:
- Non-integer arguments
- Integers outside the int range
- Duplicate numbers
- Invalid syntax

In case of error, the program writes `Error` to stderr and exits.

## Algorithm Overview

The sorting algorithm uses different strategies based on the input size:

### Small Stacks (2-5 elements)
- **2 elements**: Simple swap if needed
- **3 elements**: Optimized hard-coded solution
- **5 elements**: Push smallest elements to stack B, sort remaining 3, then push back

### Large Stacks (6+ elements)
The algorithm uses a **Turk Algorithm** approach with cost analysis:

1. **Push to B**: Push all elements except 3 to stack B, strategically placing them
2. **Sort Three**: Sort the remaining 3 elements in stack A
3. **Push Back**: For each element in B, calculate the cost of pushing it back to A and choose the cheapest move
4. **Final Rotation**: Rotate stack A to put the minimum element on top

The cost calculation considers:
- Position indices (above or below median)
- Target node calculation
- Combined rotation opportunities (rr/rrr)
- Total push cost for optimization

## Project Structure

```
push_swap/
├── Makefile              # Build configuration
├── README.md             # This file
├── inc/
│   └── push_swap.h       # Main header file
├── libft/                # Custom C library
│   ├── include/
│   └── src/
├── srcs/
│   ├── commands/         # Stack operations (sa, pa, ra, etc.)
│   └── push_swap/        # Core algorithm and initialization
└── bonus/
    ├── checker.c         # Bonus checker program
    ├── checker.h         # Checker header
    ├── checker_exec.c    # Command execution
    └── checker_utils.c   # Utility functions
```

## Resources

### Documentation & Tutorials
- [Push Swap Tutorial - 42 Docs](https://harm-smits.github.io/42docs/projects/push_swap)
- [Sorting Algorithms Visualization](https://visualgo.net/en/sorting)
- [Understanding the Turk Algorithm](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [42 Push Swap Guide](https://github.com/ayogun/push_swap)

### AI Usage
AI assistance (GitHub Copilot / Claude) was used for:
- **Documentation**: Generating this README.md file structure and formatting
- **Code Review**: Analyzing algorithm efficiency and suggesting optimizations
- **Debugging**: Identifying edge cases and memory leak issues
- **Refactoring**: Improving code readability and structure

All core algorithm logic, implementation, and problem-solving were done independently. AI was used as a productivity tool rather than for generating algorithmic solutions.

## Performance

The algorithm aims to achieve:
- **3 numbers**: Max 3 operations
- **5 numbers**: Max 12 operations
- **100 numbers**: < 700 operations (5 points), < 900 operations (4 points), < 1100 operations (3 points)
- **500 numbers**: < 5500 operations (5 points), < 7000 operations (4 points), < 8500 operations (3 points)

## Testing

You can test the program with various inputs:

```bash
# Test with random numbers
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Count operations
./push_swap 3 2 1 0 | wc -l

# Generate random numbers for testing
ARG=$(shuf -i 0-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

## Author

**viceda-s** - 42 Luxembourg

---

*For more information about 42 projects, visit [42.fr](https://www.42.fr)*
