// Function Prototypes
#ifndef UART_H
#define UART_H
#include "board.h"
#include <msp430.h>
void setupUART(void);
void printNumber(uint16_t num);
void print(char text[]);

#ifdef UART_A0
    #define UART_TX_BUF  UCA0TXBUF
    #define UART_IF_REG  UCA0IFG
#elif UART_A1
    #define UART_TX_BUF UCA1TXBUF
    #define UART_IF_REG UCA1IFG
#endif 
#endif
