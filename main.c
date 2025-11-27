#include <msp430fr2355.h>
#include <stdint.h>
#include "uart.h"
#include "spi.h"
void main(void)
{
	// Stop the watchdog timer. 
	WDTCTL = WDTPW | WDTHOLD;

    setupUART();
    setupSPI();

	uint16_t count = 0;
    while (1)
    {
        printNumber(count);
        print("\r\n");
        count++;
        __delay_cycles(10000);
    }
}
