# About

This project implements an interactive flashcards system running on an STM32 microcontroller.
The content is stored in the STM32's internal memory, and the flashcards are displayed on an SPI-connected screen.

The project is still only on Nucleo Development Board.

Browsing flashcards:

https://www.youtube.com/watch?v=-U9YpmkEfCg

Uploading them from the computer and transmitting them via UART to the device:
https://www.youtube.com/watch?v=sGX6gEc-5WE

Flashcards are configured using the FlashcardsApp desktop program. It is located here:
https://github.com/MieszkoP/FlashcardsApp

Hardware is available in repo:
https://github.com/MieszkoP/FlashcardsKicad

![20250407_123743](https://github.com/user-attachments/assets/1d1cade0-bffd-4e73-aef1-ea69fa1db431)

Electronic connection diagram:

![image](https://github.com/user-attachments/assets/a4326c76-e327-4108-b1f8-f0286bd30c28)

## Deployment Diagram



![wdrozenia](https://github.com/user-attachments/assets/cc8e07b8-92fe-48a2-846c-ffa0fe2e3088)

## UML modules diagram in Firmware

In the C language, there are no classes, but certain object-oriented features can be achieved by dividing the program into `.c` and `.h` files. It is also possible to use `struct`. This turned out to be sufficient to design a diagram of modules, structures, and enums, which is shown in figure below.

Structures supporting the state machine are variables in the "states" module.
![UML_C](https://github.com/user-attachments/assets/dc1e2067-f988-43ca-9b47-8a56cea0ccec)

The states themselves are presented in the diagram below:

![Diagram_stanow_C](https://github.com/user-attachments/assets/875f8931-e083-4a85-9594-52ab2edfa8da)

The program's operation from the user's perspective is described in the use case diagram (browsing flashcards on the left, uploading new one on the right):
<p float="left">
  <img src="https://github.com/user-attachments/assets/c8f71d6d-f9a6-4172-bec4-554eeb987032" width="45%" />
  <img src="https://github.com/user-attachments/assets/221f8d8f-687b-4885-a3b7-b1cbea994ee1" width="45%" />
</p>

## Memory usage:

Memory is key in microcontroller programming. The table below shows how much memory is used depending on the compilation mode:

| Mode    | Flash memory used by program (`.text`) | Initialized data memory (`.data`) | Uninitialized data memory (`.bss`) |
|---------|----------------------------------------|-----------------------------------|-------------------------------------|
| Debug   | 18140                                  | 1616                              | 3032                                |
| Release | 12860                                  | 96                                | 3032                                |
| Test    | 15660                                  | 1616                              | 3008                                |


