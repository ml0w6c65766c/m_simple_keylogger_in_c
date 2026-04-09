# M Simple Keylogger

A simple keylogger written in C for Linux.

## Description

This program reads input from Linux input devices (`/dev/input/eventX`) and logs keyboard input.

It only works on Linux systems.

## Requirements

- Linux operating system
- GCC compiler
- Root permissions (usually required to access input devices)

## Build

Compile the program using gcc:

```bash
gcc -o keylogger keylogger.c
```

## Usage

Run the program with the keyboard input device:
```bash
./keylogger /dev/input/eventX
```
Replace `eventX` with your actual keyboard device.

## Disclaimer

This project is for educational purposes only. Do not use it on systems you do not own or have permission to test.

## Notes

You are free to use this code as a learning base and modify it.
