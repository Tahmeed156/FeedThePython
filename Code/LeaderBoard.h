//# include "iGraphics.h"
#include<string.h>


char name[5][50] = {'--','--','--','--','--'};
 char score[5][5] = {'0','0','0','0','0'};


extern int high_score_index ;
extern int total_players;
//struct player{
//
//char name[50];
//int score;
//
//};





void  file_works()
{
    struct player p2;
    FILE *f2;
    f2 = fopen("Leaderboard.txt", "ab+");

    for(high_score_index=1; high_score_index<=total_players; high_score_index++)
    {

        if (!feof(f2))
        {
            fread(&p2,sizeof(struct player),1,f2);
           //printf("%s is %d\n", p2.name,p2.score);
        }
       strcpy( &name[high_score_index-1] [50], p2.name);
        itoa( p2.score, &score [high_score_index-1][5] ,10);
        //printf("%s is high score with hsi %d \n" , &score[high_score_index-1][5],high_score_index);
        if (high_score_index>=5)
        {
            break;
        }



    }



    fclose(f2);

//        for (i=0; i<5; i++) {
//      //  iText(600, 400 - i*50, &score[i][5], GLUT_BITMAP_HELVETICA_18);
//        printf("IN FILE  %s is high score \n" , &score[i][5]);
//        }


}




void iDraw_leaderboard()
{
    //place your drawing codes here
    iClear();

    file_works();


    iSetColor(186, 193, 184);
    iFilledRectangle(0, 0, 800, 600);

    iShowBMP(10,150, "images/image/jetpacktocat.bmp");
    iShowBMP(320,450, "images/banner/leaderboard.bmp");

    iSetColor(0, 0, 0);
    iLine(530, 190, 530, 410);
    for (i=0; i<5; i++) {
        iText(400, 400 - i*50, &name[i][50], GLUT_BITMAP_HELVETICA_18);
    }
    for (i=0; i<5; i++) {
        iText(600, 400 - i*50, &score[i][5], GLUT_BITMAP_HELVETICA_18);
    }

    iText(200, 50, "P r e s s   B a c k s p a c e   t o   g o   b a c k", GLUT_BITMAP_HELVETICA_12);

}

/*
    function iMouseMove() is called when the user presses and drags the mouse.
    (mx, my) is the position where the mouse pointer is.
*/


void iKeyboard_leaderboard(unsigned char key) {
    //place your codes for other keys here
    if (key==8||key=='/r')
    {
        screen = 'm';

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



