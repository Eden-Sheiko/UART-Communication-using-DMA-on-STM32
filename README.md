# UART Communication using DMA on STM32

This project is an example of UART communication using Direct Memory Access (DMA) on an STM32 microcontroller. Specifically, it uses UART 4 (PC10 TX, PC11 RX) and USART 6 (PC6 TX, PC7 RX) for the Master and Slave UARTs, respectively.

## Key Features

- Uses Direct Memory Access (DMA) for efficient UART communication
- Contains a function `compare_pockets` to compare data structures and check for data integrity
- Prints the content of the data structures being transmitted

## Files

- `RTG.h` - Header file defining the data structure `pocket_t` and UART handle configurations
- `main.c` - Main program demonstrating UART communication with DMA. It includes initialization of data structures, sending and receiving data, and comparing the sent and received data for integrity.

## How to Use

1. Compile the program using your favorite STM32 development environment (Keil, System Workbench, etc.)
2. Flash the compiled program onto your STM32 microcontroller
3. Connect your UART devices to the respective pins (UART 4 - PC10 TX, PC11 RX; USART 6 - PC6 TX, PC7 RX)
4. Power up the microcontroller and observe the UART communication

## Note

Please ensure that the connected UART devices and the STM32 microcontroller share the same ground, else the communication might not work properly.
