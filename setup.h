#ifndef SETUP_H
#define SETUP_H

using namespace std;

void setWindow();                                            // create a new window
void rule();                                                 // print out the rules for play
void draw2(int start_x, int start_y, int speed);             // draw number 2 on the screen
void draw0(int start_x, int start_y, int speed);             // draw number 0 on the screen
void draw4(int start_x, int start_y, int speed);             // draw number 4 on the screen
void draw8(int start_x, int start_y, int speed);             // draw number 8 on the screen
void drawFrame();                                            // draw the 4x4 frame with score and largest number

#endif // SETUP_H
