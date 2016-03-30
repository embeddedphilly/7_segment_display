/************************************************************************//** *
 * \file seven_segment_display.c
 *
 * \addtogroup seven_segment_display
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
#include "seven_segment_display.h"
#include "GPIOHAL.h"
#include "types.h"

/****************************************************************************
 *                     PRIVATE FUNCTION DECLARATIONS                        *
 ****************************************************************************/
void set_segment(uint8_t seg, uint8_t state);
uint8_t get_bit(uint8_t integer, uint8_t bit);

/****************************************************************************
 *                              PRIVATE DATA                                *
 ****************************************************************************/
uint8_t segment_state = 0;

/****************************************************************************
 *                             EXTERNAL DATA                                *
 ****************************************************************************/

GPIO_HANDLE SEGA = {GPIO_PORTD, GPIO_PIN0};
GPIO_HANDLE SEGB = {GPIO_PORTD, GPIO_PIN7};
GPIO_HANDLE SEGC = {GPIO_PORTD, GPIO_PIN5};
GPIO_HANDLE SEGD = {GPIO_PORTD, GPIO_PIN4};
GPIO_HANDLE SEGE = {GPIO_PORTD, GPIO_PIN3};
GPIO_HANDLE SEGF = {GPIO_PORTD, GPIO_PIN1};
GPIO_HANDLE SEGG = {GPIO_PORTD, GPIO_PIN2};
GPIO_HANDLE SEGDP = {GPIO_PORTD, GPIO_PIN6};

/****************************************************************************
 *                            EXPORTED FUNCTION DEFINITIONS                 *
 ****************************************************************************/

/************************************************************************//**
 * \brief Init Function - Initializes the module for use in the project.
 *        Sets up all variables, initializes all hardware peripherals necessary,
 *        etc.
 * \param none
 * \return none
 ****************************************************************************/

void SSD_Init(void)
{
  GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &SEGA);
  GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &SEGB);
  GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &SEGC);
  GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &SEGD);
  GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &SEGE);
  GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &SEGF);
  GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &SEGG);
  GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &SEGDP);
}

/************************************************************************//**
 * \brief 'ticks' the module through its internal state machine. This
 *        function should be called in the main loop of the program.
 * \param none
 * \return none
 ****************************************************************************/
void SSD_Tick(void)
{
  int i = 0,
  segment_bit;
  for (; i < 8; i++) {
    segment_bit = get_bit(segment_state, i);
    set_segment(i, segment_bit);
  }
}

/************************************************************************//**
 * \brief Set the display to of the given number of the display to the correct output
 * \param id - the ID of the display character (for displays with multiple characters)
 *        data - bitfield of the data to be displayed on the device
 * \return
 ****************************************************************************/

void SSD_SetDisplay(uint8_t data)
{
  segment_state = data;
}


/****************************************************************************
 *                     PRIVATE FUNCTION DEFINITIONS                         *
 ****************************************************************************/

uint8_t get_bit(uint8_t integer, uint8_t bit)
{
  return (integer >> bit) & 1;
}

void set_segment(uint8_t seg, uint8_t state)
{
  GPIO_HANDLE* handle = 0;
  switch(seg) {
    case 0: handle = &SEGA; break;
    case 1: handle = &SEGB; break;
    case 2: handle = &SEGC; break;
    case 3: handle = &SEGD; break;
    case 4: handle = &SEGE; break;
    case 5: handle = &SEGF; break;
    case 6: handle = &SEGG; break;
    case 7: handle = &SEGDP; break;
    default:
      return;
  }
  if (state == 0)
    GPIO_SetOutput(GPIO_HIGH, handle);
  else if (state == 1)
    GPIO_SetOutput(GPIO_LOW, handle);
}

/************************************************************************//**
 * \brief
 * \param
 * \return
 ****************************************************************************/

/** \}*/