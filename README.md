# Milestone 2 – Completed 🟢

Welcome to my repository showcasing my progress in **Milestone 1** at School 42. Below, you’ll find a focused overview of each project, my precise results, and the technical highlights that distinguish my submissions.

## 🏅 My Scores

| Project | Final Score | Notable Features |
| :-- | :--: | :-- |
| push_swap | 🌟 125/100 | Optimized algorithms, bonus checker |
| minitalk | 🌟 125/100 | Custom protocol via signals, robust messaging |
| pipex | 🌟 125/100 | UNIX pipes, process control, here_doc |
| so_long | 🌟 125/100 | Custom map parsing, real-time graphics, gameplay |

## 🔎 Project Details

### 🔄 push_swap – 125/100 🌟

- **Objective:** Sort a stack of integers with minimal stack operations (swap, push, rotate, reverse rotate).
- **Implementation:**
    - Efficient and scalable sorting strategies for small and large input sizes.
    - Strong optimization of operation count.
    - Comprehensive validation and error handling for invalid inputs.
- **Bonus:**
    - Custom **checker** program to validate sorting instructions.
    - Supports reading operations from standard input.
- **Skills:** Data structures (stacks), sorting algorithms, algorithmic optimization, C programming.


### 💬 minitalk – 125/100 🌟

- **Objective:** Implement a client-server message system using UNIX signals for inter-process communication.
- **Implementation:**
    - Transmits messages bit-by-bit with `SIGUSR1` and `SIGUSR2`.
    - Handles integrity checks and error scenarios.
    - Clean separation between server and client logic.
- **Bonus:**
    - The server must acknowledge each received message by sending a signal to the client.
    - Unicode characters support.
- **Skills:** Signal handling, low-level C programming, custom communication protocols.


### 🔗 pipex – 125/100 🌟


- **Objective:** Reproduce shell pipe behavior by chaining commands using UNIX pipes and process control.
- **Implementation:**
    - Executes multiple commands connected via pipes (`|`) using `fork`, `pipe`, and `execve`.
    - Correct handling of file redirections and environment variables.
    - Robust error management and clean process termination.
- **Bonus:**
    - Supports multiple commands (`cmd1 | cmd2 | ... | cmdN`).
    - Implements `here_doc` functionality with proper input handling.
- **Skills:** 2D graphics, event handling, memory management, modular code organization.


### 🕹️ so_long – 125/100 🌟

- **Objective:** Develop a 2D game using MiniLibX. Navigate through a map, collect items, and reach the exit.
- **Implementation:**
    - Loads and validates custom map files, handles player and enemy movement.
    - Real-time updates of graphics and smooth collision detection.
    - Win/lose conditions, resource management, and user feedback.
- **Bonus:**
    - The player loses when touched by an enemy patrol.
    - Sprite animation.
    - Move count displayed on screen.
- **Skills:** UNIX system calls, process management, file descriptors, inter-process communication.


## 🏆 Personal Achievements

- **Perfect marks** and bonus features across all projects.
- Strong mastery of algorithmic optimization, UNIX internals, IPC, and graphics programming.
- Went beyond the requirements to ensure reliability, maintainability, and extensibility.


## 📂 Repository Structure

Each project is self-contained in its own subdirectory, with complete source code and usage instructions:

```
42-cursus-level-2/
│
├── push_swap/
├── minitalk/
├── pipex/
└── so_long/
```


## 🚀 How to Explore

1. Clone this repo:
`git clone https://github.com/viceda-s/42-cursus-level-2`
2. Visit each project folder for build/run details and documentation.

Feel free to review each directory for implementation insights, technical explanations, and a deeper dive into my milestone accomplishments!
