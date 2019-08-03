//# include "iGraphics.h"

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int option =  1;
extern char point_string[5];
extern int point;

double xg[] = { 85, 75, 65, 75};
double yg[] = { 245, 225, 245, 265 };

double xg2[] = { 85, 75, 75};
double yg2[] = { 245, 225, 240};

double xg3[] = { 75, 75, 65};
double yg3[] = { 240, 225, 245};

int restart = 0;

void generate_diamond_go() {

    iSetColor(255, 0, 0);
    iFilledPolygon( xg, yg, 4 );

    iSetColor(150, 0, 0);
    iFilledPolygon(xg2, yg2, 3);
    iFilledPolygon(xg3, yg3, 3);
}


void iDraw_gameover()
{
    //place your drawing codes here
    iClear();

    if (yg[0] < 200)
        option = 2;
    else
        option = 1;

    // Background
    iShowBMP(0, 0, "images/image/gameover.bmp");

    iSetColor(255, 255, 255);
    iFilledRectangle(45, 95, 310, 360);
    iSetColor(0, 0, 0);
    iFilledRectangle(50, 100, 300, 350);

    iShowBMP(50, 350, "images/banner/gameover.bmp");
    iSetColor(255, 255, 255);

    generate_diamond_go();

    iSetColor(255, 255, 255);
    iFilledRectangle(100, 220, 200, 50);
    iSetColor(0, 0, 0);
    iFilledRectangle(102, 222, 196, 46);

    iSetColor(255, 255, 255);
    iFilledRectangle(100, 140, 200, 50);
    iSetColor(0, 0, 0);
    iFilledRectangle(102, 142, 196, 46);

    iSetColor(255, 255, 255);
    iText(80, 300, "Your Score: ", GLUT_BITMAP_HELVETICA_18);
    itoa(point,point_string,10);
     iText(200, 300, point_string, GLUT_BITMAP_HELVETICA_18);

    iText(125, 240, "P L A Y  A G A I N", GLUT_BITMAP_HELVETICA_18);
    iText(160, 160, "Q U I T", GLUT_BITMAP_HELVETICA_18);
}

/*
    function iMouseMove() is called when the user presses and drags the mouse.
    (mx, my) is the position where the mouse pointer is.
*/

/*
    function iMouse() is called when the user presses/releases the mouse.
    (mx, my) is the position where the mouse pointer is.
*/


/*
    function iKeyboard() is called whenever the user hits a key in keyboard.
    key- holds the ASCII value of the key pressed.
*/
void iKeyboard_gameover(unsigned char key) {
    //place your codes for other keys here
    if (key == '\r' && option == 2) {
        exit(0);
    }
    else if (key == '\r' && option == 1) {
        screen = 'g';
        restart = 1;
    }

}

/*
    function iSpecialKeyboard() is called whenver user hits special keys like-
    function keys, home, end, pg up, pg down, arraows etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard_gameover(unsigned char key)
{

    if(key == GLUT_KEY_DOWN) {

        if (yg[0] < 200) {

            for (int i=0; i<3; i++) {
                yg[i] += 80;
                yg2[i] += 80;
                yg3[i] += 80;
            }
            yg[3] += 80;

        } else {

            for (int i=0; i<3; i++) {
                yg[i] -= 80;
                yg2[i] -= 80;
                yg3[i] -= 80;
            }
            yg[3] -= 80;
        }

    } else if(key == GLUT_KEY_UP) {

        if (yg[0] > 200) {

            for (int i=0; i<3; i++) {
                yg[i] -= 80;
                yg2[i] -= 80;
                yg3[i] -= 80;
            }
            yg[3] -= 80;

        } else {

            for (int i=0; i<3; i++) {
                yg[i] += 80;
                yg2[i] += 80;
                yg3[i] += 80;
            }
            yg[3] += 80;

        }
    } else if (key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT ) {

    }
    //place your codes for other keys here
}

