# push_swap

![Final Score](https://i.ibb.co/SnQMV0m/image.png)

## Project Description

The `push_swap` project is a sorting algorithm implementation designed to sort a stack of integers using a limited set of operations. Developed as part of the 42 School curriculum, this project emphasizes algorithmic efficiency, data structure manipulation, and the implementation of sorting algorithms in C.

## Journey

This project was a significant challenge for me, requiring multiple iterations to achieve a working solution. My initial attempts were marred by inefficiencies and incorrect handling of edge cases. However, through perseverance and extensive testing, I was able to refine my approach and successfully implement a robust sorting algorithm.

## Key Learnings

- Understanding and implementing sorting algorithms (e.g., bubble sort, quicksort, turk algorithm)
- Efficient stack manipulation using push and swap operations
- Handling edge cases and optimizing performance
- Memory management and dynamic memory allocation in C
- Debugging complex algorithms

## Technical Details

- The project implements a sorting algorithm using two stacks: `stack_a` and `stack_b`.
- The main operations include:
  - `sa`: Swap the first two elements of `stack_a`.
  - `sb`: Swap the first two elements of `stack_b`.
  - `pa`: Push the top element of `stack_b` to `stack_a`.
  - `pb`: Push the top element of `stack_a` to `stack_b`.
  - `ra`: Rotate `stack_a` upwards.
  - `rra`: Rotate `stack_a` downwards.
- The algorithm aims to sort the integers in ascending order with minimal operations.

## Project Status

- **First Attempt**: Failed (Inefficient Algorithm)
- **Second Attempt**: Success (Optimized Solution)
- **Completion Time**: ~5 days

## Challenges Faced

The most challenging aspects of this project included:

- Developing an efficient sorting algorithm that minimizes the number of operations
- Managing the two stacks effectively to ensure correct sorting
- Debugging complex interactions between stack operations
- Optimizing the algorithm for larger datasets

## Reflection

While this project was one of the more difficult ones at 42, it greatly enhanced my understanding of sorting algorithms and data structures. The iterative process of refining my approach taught me the importance of algorithmic efficiency and the need for thorough testing to handle edge cases.

## Skills Developed

- Algorithm design and implementation
- Stack data structure manipulation
- Memory management
- Debugging complex algorithms
- Performance optimization
