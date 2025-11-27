#include "msp430fr2355.h"
#include <stdint.h>
#include "board.h"

void setupSPI(void)
{
    #ifdef SPI_A0
        P1SEL0 |= BIT7; // Select P1.7 -> SIMO (Data) SENDING OUT DATA
        P1SEL1 &= ~BIT7;

        P1SEL0 |= BIT6; // Select P1.6 -> SOMI (Data) GETTING DATA
        P1SEL1 &= ~BIT6;

        P1SEL0 |= BIT5; // Select P1.5 -> CLK (Clock)
        P1SEL1 &= ~BIT5;

        // STE (Chip Select) on P1.4

        UCA0CTLW0 |= UCSWRST;                         // Hold USCI in reset state
        UCA0CTLW0 |= UCMSB | UCSYNC | UCMST | UCCKPL; // MSB First, Synchronous, Master, Clock inactive state high

        UCA0CTLW0 |= UCSSEL__SMCLK;                   // Clock -> SMCLK
        UCA0BRW = 8;                                 // SPI CLK -> SMCLK/8
        UCA0CTLW0 &= ~UCSWRST;                        // Initialise USCI module
    #elif SPI_A1
        P4SEL0 |= BIT3; // Select P1.7 -> SIMO (Data) SENDING OUT DATA
        P4SEL1 &= ~BIT3;

        P4SEL0 |= BIT2; // Select P1.6 -> SOMI (Data) GETTING DATA
        P4SEL1 &= ~BIT2;

        P4SEL0 |= BIT1; // Select P1.5 -> CLK (Clock)
        P4SEL1 &= ~BIT1;

        // STE (Chip Select) on 4.0

        UCA1CTLW0 |= UCSWRST;                         // Hold USCI in reset state
        UCA1CTLW0 |= UCMSB | UCSYNC | UCMST | UCCKPL; // MSB First, Synchronous, Master, Clock inactive state high

        UCA1CTLW0 |= UCSSEL__SMCLK;                   // Clock -> SMCLK
        UCA1BRW = 8;                                 // SPI CLK -> SMCLK/8
        UCA1CTLW0 &= ~UCSWRST;                        // Initialise USCI module
    #elif SPI_B0
        P1SEL0 |= BIT2; // Select P4.6 -> SIMO (Data) SENDING OUT DATA
        P1SEL1 &= ~BIT2;

        P1SEL0 |= BIT3; // Select P4.7 -> SOMI (Data) GETTING DATA
        P1SEL1 &= ~BIT3;

        P1SEL0 |= BIT1; // Select P4.5 -> CLK (Clock)
        P1SEL1 &= ~BIT1;

        //STE (Chip Select) on P1.0

        UCB0CTLW0 |= UCSWRST;                         // Hold USCI in reset state
        UCB0CTLW0 |= UCMSB | UCSYNC | UCMST | UCCKPL; // MSB First, Synchronous, Master, Clock inactive state high

        UCB0CTLW0 |= UCSSEL__SMCLK;                   // Clock -> SMCLK
        UCB0BRW = 8;                                 // SPI CLK -> SMCLK/8
        UCB0CTLW0 &= ~UCSWRST;                        // Initialise USCI module
    #elif SPI_B1
        P4SEL0 |= BIT6; // Select P4.6 -> SIMO (Data) SENDING OUT DATA
        P4SEL1 &= ~BIT6;

        P4SEL0 |= BIT7; // Select P4.7 -> SOMI (Data) GETTING DATA
        P4SEL1 &= ~BIT7;

        P4SEL0 |= BIT5; // Select P4.5 -> CLK (Clock)
        P4SEL1 &= ~BIT5;

        //STE (Chip Select) on P4.4

        UCB1CTLW0 |= UCSWRST;                         // Hold USCI in reset state
        UCB1CTLW0 |= UCMSB | UCSYNC | UCMST | UCCKPL; // MSB First, Synchronous, Master, Clock inactive state high

        UCB1CTLW0 |= UCSSEL__SMCLK;                   // Clock -> SMCLK
        UCB1BRW = 8;                                 // SPI CLK -> SMCLK/8
        UCB1CTLW0 &= ~UCSWRST;                        // Initialise USCI module
    #else 
        #error "Select an SPI line!"
    #endif

}

uint8_t spiTransfer(uint8_t byte)
{
    #ifdef SPI_A0
        while (!(UCA0IFG & UCTXIFG)); // Wait for TX buffer
        UCA0TXBUF = byte;
        while (!(UCA0IFG & UCRXIFG)); // Wait for data to be received
        return UCA0RXBUF; 
    #elif SPI_A1
        while (!(UCA1IFG & UCTXIFG)); // Wait for TX buffer
        UCA1TXBUF = byte;
        while (!(UCA1IFG & UCRXIFG)); // Wait for data to be received
        return UCA1RXBUF; 
    #elif SPI_B0
        while (!(UCB0IFG & UCTXIFG)); // Wait for TX buffer
        UCB0TXBUF = byte;
        while (!(UCB0IFG & UCRXIFG)); // Wait for data to be received
        return UCB0RXBUF; 
    #elif SPI_B1
        while (!(UCB1IFG & UCTXIFG)); // Wait for TX buffer
        UCB1TXBUF = byte;
        while (!(UCB1IFG & UCRXIFG)); // Wait for data to be received
        return UCB1RXBUF; 
    #else
        #error "Select an SPI line!"
    #endif
}


