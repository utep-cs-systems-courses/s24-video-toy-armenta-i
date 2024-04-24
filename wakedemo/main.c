#include <msp430.h>
#include <stdio.h>
#include <libTimer.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachine.h"
#include "switches.h"
#include "musical_notes.h"
#include "buzzer.h"
#include "happyFace.h"


extern int redrawScreen;
int redrawScreen = 1;
int eyes_state;
int eyes_open;

void main(void) 
{
  configureClocks();
  lcd_init();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();        /**< enable periodic interrupt */
  flash_both(2);
  or_sr(0x8);                  /**< GIE (enable interrupts) */
  clearScreen(COLOR_BLACK);
  clearScreen(COLOR_WHITE);
  happyFace();                    // put everything after hapyyface
  drawString5x7(16,140, "Waiting for input", BLACK, COLOR_WHITE);
  drawSleepSymbols();
  eyes_state = 1;
  eyes_open = 1;
  while (1) {			/* forever */
    if (redrawScreen) {
      redrawScreen = 0;
      update_face_eyes(eyes_state);
    }
    or_sr(0x10);               /**< CPU OFF*/
  }  
}

void wdt_c_handler()
{
  static int eyes_time = 0;
  if(eyes_open){
    if(eyes_time++ >= 1000) {
      eyes_time = 0;
      eyes_state = 0;
      redrawScreen = 1;
    }
  }
  else{
    if(eyes_time++ >= 2000) {
      eyes_time = 0;
      eyes_open = 1;
      redrawScreen = 1;
    }
  }
}
