/************************************************************************//** *
 * \file main.c
 *
 * \addtogroup main
 * \{
 *
 * \brief
 *
 * \note
 *
 * \author
 * \date
 *
 ****************************************************************************/

/****************************************************************************
 *                              INCLUDE FILES                               *
 ****************************************************************************/
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "seven_segment_display.h"

/****************************************************************************
 *                     PRIVATE FUNCTION DECLARATIONS                        *
 ****************************************************************************/

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
int core(void);
/****************************************************************************
 *                              PRIVATE DATA                                *
 ****************************************************************************/

/****************************************************************************
 *                     PRIVATE FUNCTION DEFINITIONS                         *
 ****************************************************************************/

#ifdef __AVR__
int main(void)
{
  core();
}
#endif


uint8_t get_bits_for(uint8_t number) {
  switch(number) {
    case 0: return 0b00111111;
    case 1: return 0b00000110;
    case 2: return 0b01011011;
    case 3: return 0b01001111;
    case 4: return 0b01100110;
    case 5: return 0b01101101;
    case 6: return 0b01111101;
    case 7: return 0b00000111;
    case 8: return 0b01111111;
    case 9: return 0b01100111;
    default: return 0;
  }
}

int core(void)
{
    CPU_PRESCALE(0x01);

    SSD_Init();

    uint8_t count = 0;

    while(1) {
      SSD_SetDisplay(get_bits_for(count % 10));
      SSD_Tick();
      _delay_ms(999);
      count++;
    }
    return 0;
}
