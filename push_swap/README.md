# 🔄 push_swap

![Score Badge](https://img.shields.io/badge/Score-100%2F100-brightgreen)

## Overview

**push_swap** is a project from the 42 curriculum that consists of sorting a stack of integers using the minimum number of operations, with only a restricted set of operations allowed to manipulate two stacks (`a` and `b`). The goal is to learn algorithmic concepts, data structures, and write efficient and clean C code.

## Installation / Usage

1. Clone the repository:

```bash
git clone https://github.com/viceda-s/42-cursus-level-2.git
cd push_swap
```

2. Compile:

```bash
make
```

3. Run the program:

```bash
./push_swap [list of numbers]
```

Example:

```bash
./push_swap 3 2 1
```


## How It Works

The program takes a list of integers and outputs a sequence of operations to sort stack `a`. Only the following operations are allowed:


| Operation | Description |
| :-- | :-- |
| sa / sb | Swap the first two elements of stack a or b |
| ss | Perform sa and sb at the same time |
| pa / pb | Push the top element from stack b to a or vice versa |
| ra / rb | Rotate stack a or b upwards by one element |
| rr | Perform ra and rb at the same time |
| rra / rrb | Rotate stack a or b downwards by one element |
| rrr | Perform rra and rrb at the same time |

Example output for:

```bash
./push_swap 2 1 3
```

might be:

```
sa
```


## Notes

- `checker` program that validates sequences of operations.
- Optimized algorithms for large stacks (e.g., 500 numbers).
- Implementation of techniques such as chunk sorting and adapted quicksort.
- Full compliance with the 42 coding standard (Norme) and memory leak prevention.


## Testing

To verify correctness, use:

```bash
./push_swap 5 2 1 3 4 | ./checker 5 2 1 3 4
```

It should return `OK` if the operations are correct.

## Benchmarks

- Operation constraints:
    - ≤ 700 operations for 100 numbers
    - ≤ 5,500 operations for 500 numbers
