# Project HAWKING

Created a bare-metal Morse code interpreter developed on the STM32F446RE.

The project is written in C and interacts directly with the STM32 peripherals through memory-mapped registers rather than using a hardware abstraction layer.

## Project Goals

The goal of HAWKING is to build a complete embedded system while developing a deeper understanding of:

- ARM Cortex-M microcontrollers
- Memory-mapped peripherals
- GPIO
- Timers
- USART
- I2C __in_development__
- LCD communication __in_development__
- Embedded C
- Modular firmware architecture

## Current Features

- GPIO input/output
- Push-button input
- Button debouncing
- TIM2 polling-based delays
- TIM3 polling-based timing
- USART2 communication
- Morse code input
- Morse code binary-tree decoder
- Modular `.c` / `.h` driver structure

## Hardware

- STM32 Nucleo-F446RE
- 16x2 LCD
- PCF8574T I2C backpack
- Push button
- USB connection to PC

## Software

- C
- STM32F446RE
- ARM Cortex-M4
- STM32CubeIDE
- Register-level peripheral programming

## Project Structure

```text
HAWKING/
├── Inc/
│   ├── stm32f446xx.h
│   ├── TIMx.h
│   ├── GPIOAx.h
│   ├── USART.h
│   └── morse_decode.h
│
├── Src/
│   ├── main.c
│   ├── TIMx.c
│   ├── GPIOAx.c
│   ├── USART.c
│   └── morse_decode.c
│
├── Startup/
├── STM32F446RETX_FLASH.ld
└── README.md

