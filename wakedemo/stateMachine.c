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
extern int boat;
extern int piano;
extern int album;
extern int christmas;
extern int mc;


void state_advance(int state){

  switch(state){
  case 1:
    clearMain();
    piano = 1;
    drawOpenEyes();
    drawPiano();
    /*-------------------------*/
    turn_green();
    __delay_cycles(50000);
    red_on();
    __delay_cycles(5000);
    ode_to_joy();
    turn_both_off();
    __delay_cycles(5000);
    clearMain();
    restoreMain();
    piano = 0;
    break;
  case 2:
    // flashes both leds
    clearMain();
    boat = 1;
    drawOpenEyes();
    drawString5x7(16,10, "Row your boat!!!", BLACK, COLOR_WHITE);
    drawBoat();
    turn_green();
    __delay_cycles(50000);
    red_on();
    __delay_cycles(5000);
    row_your_boat();
    turn_both_off();
    __delay_cycles(5000);
    boat = 0;
    break;
  case 3:
    clearMain();
    mc = 1;
    drawOpenEyes();
    drawMc();
    turn_red();
    __delay_cycles(5000);
    red_on();
    __delay_cycles(5000);
    old_mc_donald();
    turn_both_off();
    __delay_cycles(5000);
    clearMain();
    restoreMain();
    mc = 0;
    break;
  case 4:
    clearMain();
    run = 1;
    drawOpenEyes();
    drawRunaway();
    turn_green();
    __delay_cycles(5000);
    red_on();
    __delay_cycles(5000);
    runaway();
    turn_both_off();
    __delay_cycles(5000);
    clearMain();
    restoreMain();
    run = 0;
    break;
  case 5:
    clearMain();
    christmas = 1;
    drawOpenEyes();
    twinkle();
    turn_green();
    __delay_cycles(50000);
    red_on();
    __delay_cycles(5000);
    row_your_boat();
    turn_both_off();
    __delay_cycles(5000);
    clearMain();
    restoreMain();
    christmas = 0;
    break;
  default:
    green_on();
    break;
  }
}
