#include <msp430.h>
#include <math.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "update.h"
#include "happyFace.h"

short drawPos[2] = {1,10}, controlPos[2] = {1, 11};
short colVelocity = 1, colLimits[2] = {1, screenWidth/2};

void happyFace()
{
  // Draw face outline
  // Define circle parameters
    int centerX = screenWidth/2; // X-coordinate of circle center
    int centerY = screenHeight/2; // Y-coordinate of circle center
    int radius = 50;  // Radius of the circle
   
    // Draw face outline (circle approximation)
    for (int x = centerX - radius; x <= centerX + radius; x++) {
        for (int y = centerY - radius; y <= centerY + radius; y++) {
            // Calculate squared distance from the center
            int distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
            // Check if the squared distance is less than or equal to the squared radius
            if (distanceSquared <= radius * radius) {
                // Inside the circle, draw a pixel
	      drawPixel(x, y, COLOR_YELLOW); // Yellow face
	    }
	}
    }
  // Draw mouth
  fillRectangle(screenWidth/4 + 7, screenHeight/2 + 15, 53, 10, COLOR_BLACK); // Black mouth
}

void drawOpenEyes(){
  fillRectangle(screenWidth/4 + 6, screenHeight/4 + 10, 20, 20, COLOR_BLACK); // Left eye                                                                    
  fillRectangle(screenWidth/4 + 40, screenHeight/4 + 10, 20, 20, COLOR_BLACK); // Right eye  
}

void drawClosedEyes(){
  fillRectangle(screenWidth/4 + 40, screenHeight/4 + 10, 20, 30, COLOR_YELLOW); // Right eye clearing color
  fillRectangle(screenWidth/4 + 6, screenHeight/4 + 10, 20, 30, COLOR_YELLOW); // Left eye clearing color
  fillRectangle(screenWidth/4 + 6, screenHeight/4 + 18, 20, 5, COLOR_BLACK); // Left eye
  fillRectangle(screenWidth/4 + 40, screenHeight/4 + 18, 20, 5, COLOR_BLACK); // Right eye
}

void update_face_eyes(int eyes_state){
  if(eyes_state){
    eyes_open = 1;
    drawOpenEyes();
  }
  if(!eyes_state){
    drawClosedEyes();
    eyes_state = 1;    
  }
  if(boat){
    drawBoat();
  }
  if(!boat){
    clearMain();
    restoreMain();
  }
  if(piano){
    drawPiano();
  }
  if(!piano){
    clearMain();
    restoreMain();
  }
  if(christmas){
    twinkle();
  }
  if(!christmas){
    clearMain();
    restoreMain();
  }
  if(mc){
    drawMc();
  }
  if(!mc){
    clearMain();
    restoreMain();
  }
}


void drawSleepSymbols(){
  drawString5x7(90,15, "Z", BLACK, COLOR_WHITE);
  drawString5x7(100,10, "Z", BLACK, COLOR_WHITE);
  drawString5x7(110,5, "Z", BLACK, COLOR_WHITE);
}

void restoreMain(){
  drawSleepSymbols();
  drawString5x7(16,140, "Waiting for input", BLACK, COLOR_WHITE);
}

void clearMain(){
  fillRectangle(0, 130, screenWidth, 40, COLOR_WHITE);
  fillRectangle(0, 0, screenWidth, 30, COLOR_WHITE);
}

void drawBoat(){
  fillRectangle(16, 130, 100, 10, COLOR_BROWN);
  fillRectangle(21, 134, 90, 15, COLOR_BROWN);
}

void drawPiano(){
  drawRectOutline(16, 130, 100, 25, COLOR_BLACK);
  // used to draw the lines to create piano keys
  for(int i = 15; i < 116; i++){
    if ((i % 10) == 0){
      for(int j = 130; j < 155; j++){
	drawPixel(i, j, COLOR_BLACK);
      }
    }
  }

  fillRectangle(19, 130, 4, 15, COLOR_BLACK);
  fillRectangle(29, 130, 4, 15, COLOR_BLACK);
  fillRectangle(39, 130, 4, 15, COLOR_BLACK);
  fillRectangle(59, 130, 4, 15, COLOR_BLACK);
  fillRectangle(69, 130, 4, 15, COLOR_BLACK);
  fillRectangle(89, 130, 4, 15, COLOR_BLACK);
  fillRectangle(99, 130, 4, 15, COLOR_BLACK);
  fillRectangle(109, 130, 4, 15, COLOR_BLACK);
  fillRectangle(120, 130, 4, 15, COLOR_WHITE);
}

void drawTriangle(u_int start_i, u_int limit_x, u_int colorBGR){
  for(int i = start_i; i < limit_x; i++){
    for(int j = start_i; j < i; j++){
      drawPixel(j, i, colorBGR);
    }
  }
}

void twinkle(){
  for(int j = 0; j < 29; j++){
    if(j % 2 == 0){
      for(int i = 0; i < screenWidth; i++){
	if(i % 4 == 0){
	  drawPixel(i, j, COLOR_BLUE);
	}
	if(i % 10 == 0){
	  drawPixel(i, j, COLOR_RED);
	}
	if(i % 20 == 0){
	  drawPixel(i, j, COLOR_GREEN);
	}
      }
    }
    if(j % 4 == 0){
      for(int i = 0; i < screenWidth; i++){
        if(i % 4 == 0){
          drawPixel(i, j, COLOR_RED);
        }
        if(i % 10 == 0){
          drawPixel(i, j, COLOR_GREEN);
        }
        if(i % 20 == 0){
          drawPixel(i, j, COLOR_BLUE);
        }
      }
    }
    if(j % 6 == 0){
      for(int i = 0; i < screenWidth; i++){
        if(i % 4 == 0){
          drawPixel(i, j, COLOR_BLUE);
        }
        if(i % 10 == 0){
          drawPixel(i, j, COLOR_GREEN);
        }
        if(i % 20 == 0){
          drawPixel(i, j, COLOR_RED);
        }
      }
    }
  }
  fillRectangle(0, 130, screenWidth, 40, COLOR_DARK_GREEN);
  drawString5x7(16,140, "Happy Holidays!!!", COLOR_RED, COLOR_DARK_GREEN);
}

void drawRunaway(){
  fillRectangle(50, 133, 30, 30, COLOR_RED);
  fillRectangle(57, 140, 15, 15, COLOR_YELLOW);
  fillRectangle(58, 151, 6, 3, COLOR_BLUE);
  fillRectangle(65, 141, 6, 6, COLOR_GRAY);
  fillRectangle(58, 141, 7, 4, COLOR_RED);
  fillRectangle(58, 144, 7, 9, COLOR_BROWN);
  fillRectangle(65, 151, 5, 3, COLOR_DARK_GREEN);
  fillRectangle(63, 147, 6, 5, COLOR_BLUE);
  fillRectangle(75, 157, 4, 3, COLOR_BLACK);
  fillRectangle(0,0,0,0, COLOR_WHITE);
}

/*void drawMc(){
  fillRectangle(50, 133, 30, 30, COLOR_RED);
}
*/
