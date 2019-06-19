//# include "iGraphics.h"

#include<stdio.h>
#include<stdlib.h>

int sel_x=0;

// double y[4] = { 425, 405, 425, 445 };
// double y[4] = { 325, 305, 325, 345 };
// double y[4] = { 225, 205, 225, 245 };

double xd[] = { 520, 510, 500, 510};
double yd[] = { 625, 605, 625, 645 };

double x2[] = { 520, 510, 510};
double y2[] = { 625, 605, 620};

double x3[] = { 510, 510, 500};
double y3[] = { 620, 605, 625};

double box1 [3] = {234, 196, 53} ;
double box2 [3] = {92, 184, 92} ;
double box3 [3] = {230, 57, 70} ;
double box4 [3] = {38, 109, 211} ;
// Text color
double txt1 [3] = {255, 255, 255} ;
double txt2 [3] = {255, 255, 255} ;
double txt3 [3] = {255, 255, 255} ;
double txt4 [3] = {255, 255, 255} ;
double txt5 [3] = {255, 255, 255} ;




void generate_diamond() {

    iSetColor(255, 0, 0);
    iFilledPolygon( xd, yd, 4 );

    iSetColor(150, 0, 0);
    iFilledPolygon(x2, y2, 3);
    iFilledPolygon(x3, y3, 3);
}

void select_effect(int sel_x) {
       if ( sel_x==1){
            txt1[0] = box1[0], txt1[1] = box1[1], txt1[2] = box1[2] ;            box1[0] = 255, box1[1] = 255, box1[2] = 255;
        } else {
            box1[0] = 234, box1[1] = 196, box1[2] = 53 ;
            txt1[0] = 255, txt1[1] = 255, txt1[2] = 255;
        }

        if ( sel_x ==2 ){
            txt2[0] = box2[0], txt2[1] = box2[1], txt2[2] = box2[2] ;
            box2[0] = 255, box2[1] = 255, box2[2] = 255;
        }  else {
            box2[0] = 92 , box2[1] = 184, box2[2] = 92 ;
            txt2[0] = 255, txt2[1] = 255, txt2[2] = 255;
        }

        if ( sel_x==3 ){
            txt3[0] = box3[0], txt3[1] = box3[1], txt3[2] = box3[2] ;
            box3[0] = 255, box3[1] = 255, box3[2] = 255;
        }  else {
            box3[0] = 230, box3[1] = 57, box3[2] = 70 ;
            txt3[0] = 255, txt3[1] = 255, txt3[2] = 255;
        }


        if ( sel_x == 4 ){
            txt4[0] = box4[0], txt4[1] = box4[1], txt4[2] = box4[2] ;
            box4[0] = 255, box4[1] = 255, box4[2] = 255;
        }  else {
            box4[0] = 38, box4[1] = 109, box4[2] = 211 ;
            txt4[0] = 255, txt4[1] = 255, txt4[2] = 255;
        }
    }

void iDraw_mainmenu()
{
    //place your drawing codes here
    iClear();

    iSetColor(186, 193, 184);
    iFilledRectangle(0, 0, 800, 600);

    // iShowBMP(0, 0, "images/image/gameover.bmp");
    iShowBMP(0, 450, "images/banner/feedthepython.bmp");
    iShowBMP(70, 50, "images/image/pythocat.bmp");


    generate_diamond();

    iSetColor(234, 196, 53);
    iFilledRectangle(550, 100, 200, 50);
    iSetColor(box1[0], box1[1], box1[2]);
    iFilledRectangle(552, 102, 196, 46);


    iSetColor(92, 184, 92);    iFilledRectangle(550, 200, 200, 50);
    iSetColor(box2[0], box2[1], box2[2]);
    iFilledRectangle(552, 202, 196, 46);

    iSetColor(230, 57, 70);
    iFilledRectangle(550, 300, 200, 50);
    iSetColor(box3[0], box3[1], box3[2]);
    iFilledRectangle(552, 302, 196, 46);

    iSetColor(38, 109, 211);
    iFilledRectangle(550, 400, 200, 50);
    iSetColor(box4[0], box4[1], box4[2]);
    iFilledRectangle(552, 402, 196, 46);

    iSetColor(txt1[0], txt1[1], txt1[2]);
    iText(615, 118,"Q U I T", GLUT_BITMAP_HELVETICA_18);
    iSetColor(txt2[0], txt2[1], txt2[2]);
    iText(615, 218,"H E L P", GLUT_BITMAP_HELVETICA_18);
    iSetColor(txt3[0], txt3[1], txt3[2]);
    iText(560, 318, "L E A D E R B O A R D", GLUT_BITMAP_HELVETICA_18);
    iSetColor(txt4[0], txt4[1], txt4[2]);
    iText(585, 418, "N E W G A M E", GLUT_BITMAP_HELVETICA_18);


    // iShowBMP(5, 5, "Edify.bmp");
    // int arr[3] = {204, 204, 204};
    // iShowBMP2(300, 300, "Edify.bmp", 0);
}

/*
    function iMouseMove() is called when the user presses and drags the mouse.
    (mx, my) is the position where the mouse pointer is.
*/
void iMouseMove_mainmenu(int mx, int my)
{
    //place your codes here


}

/*
    function iMouse() is called when the user presses/releases the mouse.
    (mx, my) is the position where the mouse pointer is.
*/
void iMouse_mainmenu(int button, int state, int mx, int my) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {
        if ( mx >300 && mx<500 && my>100 && my<150){

            txt1[0] = box1[0], txt1[1] = box1[1], txt1[2] = box1[2] ;            box1[0] = 255, box1[1] = 255, box1[2] = 255;

        } else {

            box1[0] = 234, box1[1] = 196, box1[2] = 53 ;
            txt1[0] = 255, txt1[1] = 255, txt1[2] = 255;
        }

        if ( mx >300 && mx<500 && my>200 && my<250){

            txt2[0] = box2[0], txt2[1] = box2[1], txt2[2] = box2[2] ;
            box2[0] = 255, box2[1] = 255, box2[2] = 255;
        }  else {

            box2[0] = 92 , box2[1] = 184, box2[2] = 92 ;
            txt2[0] = 255, txt2[1] = 255, txt2[2] = 255;
        }

        if ( mx >300 && mx<500 && my>300 && my<350){

            txt3[0] = box3[0], txt3[1] = box3[1], txt3[2] = box3[2] ;
            box3[0] = 255, box3[1] = 255, box3[2] = 255;
        }  else {

            box3[0] = 230, box3[1] = 57, box3[2] = 70 ;
            txt3[0] = 255, txt3[1] = 255, txt3[2] = 255;
        }


        if ( mx >300 && mx<500 && my>400 && my<450){

            txt4[0] = box4[0], txt4[1] = box4[1], txt4[2] = box4[2] ;
            box4[0] = 255, box4[1] = 255, box4[2] = 255;

        }  else {

            box4[0] = 38, box4[1] = 109, box4[2] = 211 ;
            txt4[0] = 255, txt4[1] = 255, txt4[2] = 255;
        }

        if (mx > 550 && mx<750 && my>400 && my<450 )
        {
            screen = 'g';
        }

        if (mx > 550 && mx<750 && my>300 && my<350 )
        {
            screen = 'h';
        }
        if (mx > 550 && mx<750 && my>200 && my<250 )
        {
            screen = 'i';
        }
        if (mx > 550 && mx<750 && my>100 && my<150 )
        {
            exit(0);
        }


    }

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}


void iKeyboard_mainmenu(unsigned char key) {

    if ( key == '\n' || key == '\r') {

       if ( sel_x == 4) {
            //printf("%d", sel_x);
            screen = 'g';
            PlaySound("newgame.wav",NULL,SND_ASYNC);
       } else if (sel_x == 3) {
            screen = 'h';
            //printf("%d", sel_x);       } else if (sel_x == 2) {
            screen = 'i';}
            else if (sel_x == 1) {

            //printf("%d", sel_x);
            exit(0);
       }

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
void iSpecialKeyboard_mainmenu(unsigned char key)
{
    if(key == GLUT_KEY_DOWN) {

         if ( yd[0] < 200 || yd[0] > 600 ) {
                yd[0] = 425,yd[1] = 405,yd[2] = 425,yd[3] = 445;
                y2[0] = 425, y2[1] = 405, y2[2] = 420;
                y3[0] = 420, y3[1] = 405, y3[2] = 425;
                sel_x=4;
                select_effect(4);
        } else {
            for (int i=0; i<3; i++) {
                yd[i] -= 100;
                y2[i] -= 100;
                y3[i] -= 100;
            }
            yd[3] -= 100;
            sel_x--;
            select_effect(sel_x);
        }

    } else if(key == GLUT_KEY_UP) {

        if (yd[0] > 400) {
                yd[0] = 125,yd[1] = 105,yd[2] = 125,yd[3] = 145;
                y2[0] = 125, y2[1] = 105, y2[2] = 120;
                y3[0] = 120, y3[1] = 105, y3[2] = 125;
                sel_x=1;
                select_effect(1);
        } else {
            for (int i=0; i<3; i++) {
                yd[i] += 100;
                y2[i] += 100;
                y3[i] += 100;
            }
            yd[3] += 100;
            sel_x++;
            select_effect(sel_x);
        }
    } else if (key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT ) {
            sel_x = 0;
            select_effect(0);
            yd[0] = 625,yd[1] = 605,yd[2] = 625,yd[3] = 645;
            y2[0] = 625, y2[1] = 605, y2[2] = 620;
            y3[0] = 620, y3[1] = 605, y3[2] = 625;
    }
    //place your codes for other keys here
}


