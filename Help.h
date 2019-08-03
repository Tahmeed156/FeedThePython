//# include "iGraphics.h"





void iDraw_help()
{
    //place your drawing codes here
    iClear();

      iShowBMP(0, 0, "images/image/python.bmp");

   iSetColor(0,0,0);
   iText(300, 520, "I N S T R U C T I O N S ", GLUT_BITMAP_HELVETICA_18);
   iLine(300, 515,500,515 );

      iSetColor(235,0,0);
      iFilledCircle(100,400,30,100);
      iSetColor(0,0,0);
      iLine(100,420,100,440);



   iSetColor(0,20,120);
   iText(180,400, "      -     NORMAL FOOD.EATING THIS ADDS 10 POINTS ~ ", GLUT_BITMAP_HELVETICA_18);

   iSetColor(255,223,0);
   iFilledCircle(100,300,35,100);
   iSetColor(0,0,0);
   iLine(100,322,100,344);


      iSetColor(0,0,0);
        iText(180,300, "      -     SPECIAL FOOD.EATING THIS ADDS 50 POINTS ~ ", GLUT_BITMAP_HELVETICA_18);

         iSetColor(150,0,255);
   iFilledCircle(100,200,35,100);
    iSetColor(0,0,0);
   iLine(100,222,100,244);


        iSetColor(0,0,0);
        iText(180,200, "      -     POISONOUS FOOD~50 POINTS LOSS ~ ", GLUT_BITMAP_HELVETICA_18);

        iSetColor(0,20,120);
        iText(80,120,"THE PLAYER HAS 3 LIVES.LIVES ARE LOST IF - ", GLUT_BITMAP_HELVETICA_18);
        iText(80,90,"1. THE PLAYER HITS A TETRIS  ", GLUT_BITMAP_HELVETICA_18);
        iText(80,60,"2. THE SNAKE  BODY HITS ITSELF ", GLUT_BITMAP_HELVETICA_18);

        iSetColor(0,0,0);
        iText(300,12,"HIT BACKSPACE TO GO BACK ", GLUT_BITMAP_HELVETICA_12);




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
void iKeyboard_help(unsigned char key) {
    //place your codes for other keys here
        if (key==8||key=='/r')
    {
        screen = 'm';

    }

}


