
//# include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int boxColor[3] = {186, 193, 184};
int mode=0, i=0;
char arr1[35];
char str[100];
char str1[100];
char str2[100];
char hs[4];
char name_input[35];
int index=-1;
int total_players=0;
int player_score=0;
extern char screen;//for screen in console
extern int high_score_index;

struct player
{
    char name[50];
    int score;
};


void check_file()
{
    //file code for log-in
    index = -1;
    struct player p1;

    FILE *f1;
    f1 = fopen("Scores.txt","ab+");

    strcpy(name_input,arr1);


    while( fread(&p1,sizeof(struct player),1,f1))
    {

        total_players ++;


        if(strcmp(name_input, p1.name)==0)
        {
            player_score=p1.score;
            index = total_players;
        }
    }



    if (index == -1)
    {
        char *temp = "New user created";
        strcpy(str, temp);
        strcpy(p1.name,name_input);
        p1.score = 0;
        player_score = 0;

        index = total_players+1;
        fwrite(&p1,sizeof(struct player),1,f1);
    }
    else
    {
        char *temp = "Welcome back";
        strcpy(str, temp);


    }


    fclose(f1);


    // to get high_score_index value

    FILE *f2;
    f2 = fopen("Leaderboard.txt", "ab+");



    for(high_score_index=1; high_score_index<=total_players; high_score_index++)
    {

        if (!feof(f2))
        {
            fread(&p1,sizeof(struct player),1,f2);
        }
        //printf("%s with score %d\n", p1.name,p1.score);
        if (high_score_index>=5)
        {
            break;
        }

    }

fclose(f2);



}




void login_user() {
    check_file();

    itoa(player_score,  hs,10);
  //  char *temp = "We are so happy to see you!";
    char *temp1 = "Your Highscore : ";
    char *temp2 = "Press Enter to play the game!";
    strcpy(str1, temp1);
    strcpy(str2, temp2);
    mode = 2;
}




void iDraw_login()
{
    //place your drawing codes here
    iClear();

    iSetColor(186, 193, 184);
    iFilledRectangle(0, 0, 800, 600);

    // iShowBMP(0, 0, "images/image/gameover.bmp");
    iShowBMP(100, 350, "images/banner/login.bmp");
    iShowBMP(400,150, "images/image/inspectocat.bmp");

    iSetColor(0, 0, 0);
    iRectangle(120, 300, 200, 30);

    iSetColor(boxColor[0], boxColor[1], boxColor[2]);
    iFilledRectangle(121, 301, 198, 28);

    iSetColor(0, 0, 0);
    iLine(210, 270,227, 270);
    iLine(222, 275,227, 270);
    iLine(222, 265,227, 270);
    iCircle(220, 270, 15, 100);

    iSetColor(0, 0, 0);
    iText(125, 310, arr1, GLUT_BITMAP_HELVETICA_18);

    iText(125, 210, str, GLUT_BITMAP_HELVETICA_18);
    iText(125, 180, str1, GLUT_BITMAP_HELVETICA_18);
    iText(280, 179, hs, GLUT_BITMAP_HELVETICA_18);
    iText(125, 150, str2, GLUT_BITMAP_HELVETICA_18);

}


void iMouse_login(int button, int state, int mx, int my) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {
            if (mx>=120 && mx<=320 && my >=300 && my<=330) {
            mode = 1;
            boxColor[0] = 230;
            boxColor[1] = 230;
            boxColor[2] = 230;
            int j;

           } else if (mx>=205 && mx<=235 && my >=255 && my<=285) {
            printf("%s\n", arr1);
            login_user();

            // Emptying the sting
            for (int j=0; j<i; j++) {
                arr1[j] = '\0';
            }

            i=0;
            boxColor[0] = 186;
            boxColor[1] = 193;
            boxColor[2] = 184;


        } else {
            mode = 0;
            boxColor[0] = 186;
            boxColor[1] = 193;
            boxColor[2] = 184;
        }
    }

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

/*
    function iKeyboard() is called whenever the user hits a key in keyboard.
    key- holds the ASCII value of the key pressed.
*/
void iKeyboard_login(unsigned char key) {
    //place your codes for other keys here
        if (i < 100 && mode == 1) {
            if ( key == 8) {
                arr1[i-1] = ' ' ;
                if (i>0) {
                    i = i-1 ;
                }

            } else if ( key == '\r' && arr1[0] != '\0' ) {
                login_user();

                // Emptying the sting
                for (int j=0; j<i; j++) {
                    arr1[j] = '\0';
                }

                i=0;
                boxColor[0] = 186;
                boxColor[1] = 193;
                boxColor[2] = 184;
            } else {
                arr1[i] = key ;
                i = i+1 ;
            }
        } else if ( key == '\r' && mode == 2 ) {
            screen  = 'm';
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

