# Milestone 2 – Completed 🟢

Welcome to my repository showcasing my progress in **Milestone 1** at School 42. Below, you’ll find a focused overview of each project, my precise results, and the technical highlights that distinguish my submissions.

## 🏅 My Scores

| Project | Final Score | Notable Features |
| :-- | :--: | :-- |
| push_swap | ✅ 100/100 | Optimized algorithms, handles edge cases |
| minitalk | 🌟 125/100 | Custom protocol via signals, robust messaging |
| so_long | 🌟 125/100 | Custom map parsing, real-time graphics, gameplay |

## 🔎 Project Details

### 🔄 push_swap – 100/100 ✅

- **Objective:** Sort a stack of integers with minimal stack operations (swap, push, rotate, reverse rotate).
- **Implementation:**
    - Efficient sorting algorithm for varying input sizes.
    - Considers edge cases and optimizes the move count.
    - Thoughtful error checking for invalid inputs and operations.
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


### 🕹️ so_long – 125/100 🌟

- **Objective:** Develop a 2D game using MiniLibX. Navigate through a map, collect items, and reach the exit.
- **Implementation:**
    - Loads and validates custom map files, handles player and enemy movement.
    - Real-time updates of graphics and smooth collision detection.
    - Win/lose conditions, resource management, and user feedback.
- **Bonus:**
    - The player lose when touched by an enemy patrol.
    - Sprite animation.
    - Move count displayed on screen.
- **Skills:** 2D graphics, event handling, memory management, modular code organization.


## 🏆 Personal Achievements

- **Perfect marks** and bonus features across all projects.
- Developed advanced algorithmic thinking, inter-process communication and graphics programming.
- Went beyond the requirements to ensure reliability, maintainability and extensibility.


## 📂 Repository Structure

Each project is self-contained in its own subdirectory, with complete source code and usage instructions:

```
42-cursus-level-2/
│
├── push_swap/
├── minitalk/
└── so_long/
```


## 🚀 How to Explore

1. Clone this repo:
`git clone https://github.com/viceda-s/42-cursus-level-2`
2. Visit each project folder for build/run details and documentation.

Feel free to review each directory for implementation insights, technical explanations, and a deeper dive into my milestone accomplishments!
