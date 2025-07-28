# 💬 minitalk

![Score Badge](https://img.shields.io/badge/Score-125%2F100-brightgreen)

## Overview

**minitalk** is a 42 project focused on interprocess communication. The goal is to build a small messaging system using only UNIX signals, with a client program that sends messages (strings) to a server program. The core learning objectives include process signaling, bitwise operations, and clean C programming.

## Installation / Usage

1. Clone the repository:

```bash
git clone https://github.com/viceda-s/42-cursus-level-2.git
cd minitalk
```

2. Compile:

```bash
make
```

3. Start the server (in one terminal):

```bash
./server
```

This will display the server's PID.
4. Send a message from the client (in another terminal):

```bash
./client [server_PID] [your_message]
```

Example:

```bash
./client 4242 "Hello, world!"
```


## How It Works

minitalk consists of two programs:

- **server:** Waits for messages, receives them via UNIX signals (SIGUSR1, SIGUSR2), reconstructs characters from the signals, and prints the message.
- **client:** Sends a message to the server, encoding each character into bits and sending them as signals (SIGUSR1 for 1, SIGUSR2 for 0).

**Workflow:**

- The server displays its PID. The client uses this PID to target its message.
- The client encodes each character of the message into binary.
- Each bit is sent as a signal: `SIGUSR1` (1), `SIGUSR2` (0).
- The server reconstructs each bit into characters and displays the complete message.


## Extras / Bonus

- Acknowledgment mechanism implemented: the server confirms successful message receipt by sending signals back to the client.
- Enhanced communication reliability and synchronization.
- Robust error handling and prevention of memory leaks.
- Ability to handle larger, longer or Unicode messages reliably.
- Full compliance with 42 coding standards (Norme).


## Testing

Open two terminals:

**Start the server:**

```bash
./server
```

*Note the PID (e.g., `4242`).*

**Send a message:**

```bash
./client 4242 "Your message here!"
```

The server should print: `Your message here!`

The client will receive confirmation signals from the server after successful reception if the bonus is implemented.

## Notes

- Developed in C using only UNIX signals for communication.
- Example authorized functions: `write`, `signal`, `sigaction`, `kill`, `getpid`, `malloc`, `free`, `pause`, `usleep`, `exit`.
- Allowed to use only 1 global variables per file.
