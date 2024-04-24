#include <msp430.h>
#include <stdio.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachine.h"
#include "happyFace.h"
#include "lcdutils.h"
#include "lcddraw.h"

extern int eyes_state;

void state_advance(int state){

  switch(state){
  case 1:
    drawOpenEyes();
    fillRectangle(10, 140, screenWidth, 10, COLOR_WHITE);
    fillRectangle(10, 0, screenWidth, 23, COLOR_WHITE);
    /*-------------------------*/
    turn_green();
    __delay_cycles(50000);
    red_on();
    __delay_cycles(5000);
    //ode_to_joy();
    turn_both_off();
    __delay_cycles(5000);
    break;
  case 2:
    // flashes both leds
    //flash_both(30);
    
    jingle_bells();
    turn_both_off();
    __delay_cycles(5000);
    break;
  case 3:
    //flashes red led
    turn_red();
    row_your_boat();
    turn_both_off();
    __delay_cycles(5000);
    break;
  case 4:
    // no leds
    runaway();
    __delay_cycles(5000);
    break;
  case 5:
    // flashes green then red then no leds
    flash_green_red();
    twinkle_twinkle();
    __delay_cycles(5000);
    break;
  default:
    green_on();
    break;
  }
}
