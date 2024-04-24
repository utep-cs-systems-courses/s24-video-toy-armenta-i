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
  //clearScreen(COLOR_WHITE);
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
  else{
    drawClosedEyes();
    eyes_state = 1;
  }
}


void drawSleepSymbols(){
  drawString5x7(90,15, "Z", BLACK, COLOR_WHITE);
  drawString5x7(100,10, "Z", BLACK, COLOR_WHITE);
  drawString5x7(110,5, "Z", BLACK, COLOR_WHITE);
}
