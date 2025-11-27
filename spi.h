
#include <stdint.h>
#include <math.h>

uint8_t spiReadByte(uint8_t);
void spiWriteByte(uint8_t);
void setupSPI(void);
uint8_t spiTransfer(uint8_t);