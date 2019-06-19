#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include "Login.h"
#include "Main_menu.h"
#include "LeaderBoard.h"
#include "Gameover.h"
#include "Help.h"
#include<string.h>
#include <mmsystem.h>


int x=260, y=260; // Co-ordinates of food
int len=8; // Length of the snake
char direction = 'l'; // Direction of head movement
int point=0; // Points stored
char point_string[5]  = {'0'}; // Points displayed in string
int x_add, y_add;


int r = 85,g = 145,b = 0;

char screen = 'l'; //shows login page first


int high_score_index=1; //for high score checking


int life = 3; //life of snake
char life_string[5] = {'3'};//life displayed in string


//special food variables
int xSp = 320,ySp = 420;
int timer_s = 1;
int time_limit, Foodtimer = 0,foodflag = 0;

//poison food variables
int Ptime_limit, PFoodtimer = 0,Pfoodflag = 0;
int PoisX = 360, PoisY = 480;


int time_limit_tongue=0; //for random tongue generation

char restart_dir='l';






// Statically positioned snake
int arr[2][100] =
{
    {200, 220, 240, 260, 280, 300, 320, 340},
    {200, 200, 200, 200, 200, 200, 200, 200}
};


int tetarr[2][8] =
{
    { 300,300,320,340,340,340,320,320},
    { 600,620,620,620,640,660,660,660}

};




//handling high_score and FILE works for user
void high_score()
{
    struct player p3;
    struct player p4;
    FILE *fp;

    //printf("%d and hsi  is %d",index,high_score_index);
    fp = fopen("Scores.txt","rb+");
    index--;
    fseek(fp,sizeof(struct player)*index,SEEK_SET);
    fread(&p3,sizeof(struct player),1,fp);
    if(p3.score<point)
    {
        p3.score=point;
    }
    fseek(fp,sizeof(struct player)*index,SEEK_SET);
    fwrite(&p3,sizeof(struct player),1,fp);
    //printf("\n high score is %d and index is %d",p3.score,index);
    fclose(fp);


    //handling input to leaderboard
    FILE *fhs;
    fhs=fopen("Leaderboard.txt","rb+");



    //go to the -2 index
    fseek(fhs,sizeof(struct player)*(high_score_index-1), SEEK_SET);
    int k = fread(&p4,sizeof(struct player),1,fhs);
    //if no input means empty file so add on 0th index
    if (k==0)
    {
        fseek (fhs,0,SEEK_SET);
        fwrite(&p3,sizeof(struct player),1,fhs);
    }
    else
    {
        //will add person to complete 5 people even if score is lower than -1 index
        p3.score=point;
        if(total_players<5 && p4.score>point)
        {

            fseek(fhs,sizeof(struct player)*(total_players),SEEK_END);
            fread(&p3,sizeof(struct player),1,fhs);
        }

        //will check constantly whether score is  higher than the previous index and will swap places if it is
        while (p4.score<point&&high_score_index>0)
        {

            fseek(fhs,sizeof(struct player)*(high_score_index-1), SEEK_SET);
            fwrite(&p3,sizeof(struct player),1,fhs);
            if (high_score_index!=5)
            {
                fseek(fhs,sizeof(struct player)*(high_score_index),SEEK_SET);
                fwrite(&p4,sizeof(struct player),1,fhs);
            }

            high_score_index-=1;
            fseek(fhs,sizeof(struct player)*(high_score_index-1),SEEK_SET);
            fread(&p4,sizeof(struct player),1,fhs);
        }



    }




    fclose(fhs);


}






//make tetris blocks
void generate_tetris()
{

    int y = 600;
    int x = (rand()*20%600)+40;
    int a, b=rand()%2;
    x_add =0, y_add =0;

    //printf("\n\nThe new Tetris Co-ordinates: \n");

    for(int i = 0; i<8; i++)
    {
        tetarr[0][i] = x;
        tetarr[1][i] = y;

        a = rand()%3;

        if (a==0)
        {
            x_add =  0;
            y_add = 20;
        }
        else if (a==1 && b==0)
        {
            x_add =  20;
            y_add = 0;
        }
        else if (a==1 && b==1)
        {
            x_add =  -20;
            y_add = 0;
        }

        // printf("x[%d] is %d, y[%d] is %d\n    x_p is %d and y_p is %d and a is %d, b is %d\n", i, tetarr[0][i], i, tetarr[1][i], x_add, y_add, a, b);

        x += x_add;
        y += y_add;
        x_add = 0;
        y_add = 0;
    }

}

// Game over if hits tetris
void tetris_hit()
{

    // checks head co-ordinate to food co-ordinate
    for (int i=0; i<len; i++)
    {
        for (int j=0; j<8; j++)
        {
            if ( arr[0][i] == tetarr[0][j] && arr[1][i] == tetarr[1][j] )
            {
                // printf("\nx,y of head %d %d\nx, y of tet %d %d ", arr[0][0], arr[1][0], tetarr[0][j], tetarr[1][j]);



                for(int i = 0; i<8; i++)
                {
                    tetarr[0][i] = 0;
                    tetarr[1][i] = -100;
                }
                life--;
                PlaySound("tetris_hit.wav",NULL,SND_ASYNC);

                itoa(life,life_string,10);
                if(i>=2)
                {
                    len = i;

                }
                if (life<=0)
                {

                    high_score();
                    PlaySound("GameOver.wav",NULL,SND_ASYNC);
                    screen = 'o';
                }
            }
        }
    }
}



//draw tetris
void drawtetris()
{


    int j = tetarr[0][4] % 3;
    int col[3] = {0, 0, 0};
    if (j==0)
        col[0] = 255;
    else if (j==1)
        col[1] = 255;
    else
        col[2] = 255;

    for(int i = 0; i<8; i++)
    {
        iSetColor(col[0], col[1], col[2] );
        iFilledRectangle(tetarr[0][i], tetarr[1][i],18,18);
        iSetColor(col[0]-100, col[1]-100, col[2] -100);
        iFilledRectangle(tetarr[0][i]+4, tetarr[1][i]+4,10,10);
    }
}


//move tetris down
void movetetris()
{

    for(int i=0; i<8; i++)
    {
        tetarr[1][i] -= 20;
    }

}

// Assigns new co-ordinate of snake body every timeout
void snake_body()
{

    // printf("The new co-ordinates are : \n");

    for (int i=len-1; i>0; i--)
    {
        // Obtains x, y values from previous segment of the snake
        // printf("x[%d] is %d, y[%d] is %d\n", i, arr[0][i], i, arr[1][i]);
        arr[0][i] = arr[0][i-1];
        arr[1][i] = arr[1][i-1];
    }
    // printf("x[0] is %d, y[0] is %d\n\n", arr[0][0], arr[1][0]);
    // printf("\Len is %d\n", len);
}

void move_snake()
{

    // moves body
    if (direction != 't')
    {
        snake_body();
    }
//    for (int i=len-1; i>0; i--)
//    {
//        // Obtains x, y values from previous segment of the snake
//        printf("x[%d] is %d, y[%d] is %d\n", i, arr[0][i], i, arr[1][i]);
//    }

    // Moves head/ Changes head direction
    if ( direction == 'r' )
    {
        // Border case
        if (arr[0][0] == 780)
        {
            arr[0][0] = 0;
            // Regular case
        }
        else
        {
            arr[0][0] += 20;
        }
    }
    else if ( direction == 'l' )
    {
        if (arr[0][0] == 0)
        {
            arr[0][0] = 780;
        }
        else
        {
            arr[0][0] -= 20;
        }
    }
    else if ( direction == 'd' )
    {
        if (arr[1][0] == 0)
        {
            arr[1][0] = 580;
        }
        else
        {
            arr[1][0] -= 20;
        }
    }
    else if ( direction == 'u' )
    {
        if (arr[1][0] == 580)
        {
            arr[1][0] = 0;
        }
        else
        {
            arr[1][0] += 20;
        }
    }



}


void grid()
{
    iSetColor(255, 255, 255);
    // Vertical lines from x = 0 to x = 800
    for(int i = 0; i<=800; i+=20)
    {
        iLine(i,0, i,600);
    }
    // Horizontal lines from y= 0 to y = 600
    for(int i = 0; i<=600; i+=20)
    {
        iLine(0, i, 800, i);
    }

}


// Controls the feeding process
void feed_the_python()
{

    // checks head co-ordinate to food co-ordinate
    if ( arr[0][0] == x && arr[1][0] == y )
    {

        // generate new food
        x = ((x*rand())+ 20)%800;
        y = ( (y* rand() )+ 20 )%560;
        // assign point
        PlaySound("AppleEat.wav",NULL,SND_ASYNC);

        //PlaySound("Opening.wav",NULL,SND_LOOP|SND_ASYNC);
        point += 10;

        itoa(point, point_string, 10);

        // Increase length of snake. The part of array that matters.
        len ++;

//		for (int k=0; k<len; k++) {
//			printf("The co-ordinates are x[%d] %d , y[%d] %d\n", k, arr[0][k], k, arr[1][k]);
//		}

        // Assigns last value in array to new co-ordinate
        arr[0][len-1] = arr[0][len-2];
        arr[0][len-1] = arr[1][len-2];
        move_snake();

    }
}


void specialFood()
{

    timer_s++;
    Foodtimer++;
    PFoodtimer++;
}


void SpFoodEat()
{

    if ( arr[0][0] == xSp && arr[1][0] == ySp)
    {

        foodflag = 1;
        Foodtimer = 0;
        PlaySound("AppleEat.wav",NULL,SND_ASYNC);

        // generate new food
        xSp = ((xSp*rand())+ 20)%800;
        ySp = ( (ySp* rand() )+ 20 )%560;
        // assign point
        point += 50;
        itoa(point, point_string, 10);

        // Increase length of snake. The part of array that matters.
        if(len>3)
            len = len - 2;
        move_snake();

    }

}

void Generate_spfood()
{

    if(timer_s%20 == 0)
    {

        time_limit = timer_s;
        // printf("%d   %d\n",timer_s,time_limit);

    }

    if(foodflag == 0 && timer_s >=20 && timer_s <= time_limit + 8)
    {

        // printf("%d   %d\n",timer_s,time_limit);
        iSetColor(255,223,0);
        iFilledCircle(xSp+10,ySp+10,10,200);
        iSetColor(0,0,0);
        iLine(xSp + 10,ySp + 15,xSp + 10,ySp + 22 );

        SpFoodEat();

    }


    else if(foodflag == 1 && Foodtimer == 20)
    {

        //printf("Khaile timer eita - %d\n",khailetimer);
        iSetColor(255,223,0);
        iFilledCircle(xSp + 10,ySp + 10,10,200);
        iSetColor(0,0,0);
        iLine(xSp + 10,ySp + 15,xSp + 10,ySp + 22 );

        SpFoodEat();

        foodflag = 0;
        Foodtimer = 0;


    }

}



void PoisonedFood()
{

    if ( arr[0][0] == PoisX && arr[1][0] == PoisY)
    {

        Pfoodflag = 1;
        PFoodtimer = 0;
        PlaySound("AppleEat.wav",NULL,SND_ASYNC);


        // generate new food
        PoisX = ((PoisX*rand())+ 20)%800;
        PoisY = ( (PoisY* rand() )+ 20 )%560;
        // assign point
        point -= 50;
        itoa(point, point_string, 10);

        // Increase length of snake. The part of array that matters.
        len ++;
        arr[0][len-1] = arr[0][len-2];
        arr[1][len-1] = arr[1][len-2];

        move_snake();



    }
}

void Gen_PoisonedFood()
{

    if(timer_s%30 == 0)
    {

        Ptime_limit = timer_s;
        // printf("%d   %d\n",timer_s,time_limit);

    }

    if(Pfoodflag == 0 && timer_s >=30 && timer_s<= Ptime_limit + 15)
    {

        iSetColor(150,0,255);
        iFilledCircle(PoisX + 10,PoisY + 10,10,200);
        iSetColor(0,0,0);
        iLine(PoisX + 10,PoisY + 15,PoisX + 10,PoisY + 22 );

        PoisonedFood();

    }


    else if(Pfoodflag == 1 && PFoodtimer == 30)
    {

        iSetColor(150,0,255);
        iFilledCircle(PoisX + 10,PoisY + 10,10,200);
        iSetColor(0,0,0);
        iLine(PoisX + 10,PoisY + 15,PoisX + 10,PoisY + 22 );

        PoisonedFood();

        Pfoodflag = 0;
        PFoodtimer = 0;

    }

}



// Movement of the snake

//for snake tongue generation
int snake_tongue()
{
    if(timer_s%8== 0)
    {

        time_limit_tongue = timer_s;
    }

    if(timer_s <= time_limit_tongue+4)
    {

        return 1;
    }

    else
    {
        return 0;
    }


}

void snake()
{
    // Forms body from the co-ordinates from array, and then an eye
    iSetColor(r, g,b) ;
//    if (direction == 'r')
//        iFilledEllipse(arr[0][0], arr[1][0] + 10, 20, 10, 100) ;
//    else if (direction == 'l')
//        iFilledEllipse(arr[0][0]+20, arr[1][0]+10, 20, 10, 100) ;
//    else if (direction == 'u')
//        iFilledEllipse(arr[0][0]+10, arr[1][0] , 10, 20, 100) ;
//    else if (direction == 'd')
//        iFilledEllipse(arr[0][0]+10, arr[1][0] +20, 10, 20, 100) ;


    iFilledCircle(arr[0][0]+10, arr[1][0]+10, 8, 100);
    //  printf("khankir pola len is %d\n",len);

    for (int i=1; i<len; i++)
    {
        iSetColor(r, g,b) ;
        iFilledRectangle(arr[0][i], arr[1][i], 20, 20) ;
        //  printf("len is %d\n",len);
        // iFilledCircle(arr[0][i]+10, arr[1][i]+10, 15, 100) ;
        // iSetColor(255, 0, 0) ;
    }

    // Eyes
    if(direction == 'r'||(restart_dir =='r'&&direction=='t'))
    {
        // iPoint(arr[0][0] + 10, arr[1][0] + 13, 2);
        // iPoint(arr[0][0] + 10, arr[1][0] + 6, 2);
        iSetColor(255, 255, 255);
        iFilledCircle(arr[0][0], arr[1][0]+16, 5, 100);
        iFilledCircle(arr[0][0], arr[1][0]+4, 5, 100);
        iSetColor(0, 0, 0);
        iFilledCircle(arr[0][0]+2, arr[1][0]+16, 2, 100);
        iFilledCircle(arr[0][0]+2, arr[1][0]+4, 2, 100);

        if (snake_tongue()==1)
        {
            iSetColor(255, 0, 0) ;
            iFilledRectangle(arr[0][0]+20, arr[1][0]+8, 8, 3);
        }
    }
    else if(direction == 'l' || (restart_dir =='l'&&direction=='t'))
    {
        // iPoint(arr[0][0] + 10, arr[1][0] + 13, 2);
        // iPoint(arr[0][0] + 10, arr[1][0] + 6, 2);
        iSetColor(255, 255, 255);
        iFilledCircle(arr[0][0]+20, arr[1][0]+16, 5, 100);
        iFilledCircle(arr[0][0]+20, arr[1][0]+4, 5, 100);
        iSetColor(0, 0, 0);
        iFilledCircle(arr[0][0]+18, arr[1][0]+16, 2, 100);
        iFilledCircle(arr[0][0]+18, arr[1][0]+4, 2, 100);
        if (snake_tongue()==1)
        {
            iSetColor(255, 0, 0) ;
            iFilledRectangle(arr[0][0]-8, arr[1][0]+8, 8, 3);
        }
    }

    else if(direction == 'u'||(restart_dir =='u'&&direction=='t'))
    {
        // iPoint(arr[0][0] + 10, arr[1][0] + 13, 2);
        // iPoint(arr[0][0] + 10, arr[1][0] + 6, 2);
        iSetColor(255, 255, 255);
        iFilledCircle(arr[0][0]+16, arr[1][0], 5, 100);
        iFilledCircle(arr[0][0]+4, arr[1][0], 5, 100);
        iSetColor(0, 0, 0);
        iFilledCircle(arr[0][0]+16, arr[1][0]+2, 2, 100);
        iFilledCircle(arr[0][0]+4, arr[1][0]+2, 2, 100);
        if (snake_tongue()==1)
        {
            iSetColor(255, 0, 0) ;
            iFilledRectangle(arr[0][0]+8, arr[1][0]+20, 3, 8);
        }


    }


    else if(direction == 'd'||(restart_dir =='d'&&direction=='t'))
    {
        // iPoint(arr[0][0] + 10, arr[1][0] + 13, 2);
        // iPoint(arr[0][0] + 10, arr[1][0] + 6, 2);
        iSetColor(255, 255, 255);
        iFilledCircle(arr[0][0]+16, arr[1][0]+20, 5, 100);
        iFilledCircle(arr[0][0]+4, arr[1][0]+20, 5, 100);
        iSetColor(0, 0, 0);
        iFilledCircle(arr[0][0]+16, arr[1][0]+18, 2, 100);
        iFilledCircle(arr[0][0]+4, arr[1][0]+18, 2, 100);

        if (snake_tongue()==1)
        {
            iSetColor(255, 0, 0) ;
            iFilledRectangle(arr[0][0]+8, arr[1][0]-8, 3, 8);
        }


    }



}

//snake gets shortened if eats its own tail
void body_eat()
{
    int i;
    for(i=1; i<len; i++)
    {
        // printf("point is %d and i is %d\n",point,i);
        if(arr[0][0]==arr[0][i]&&arr[1][0]==arr[1][i])
        {
            //printf("previous point  is %d\n",point );
            point-=(5*(len-i));
            PlaySound("AppleEat.wav",NULL,SND_ASYNC);
            itoa(point, point_string, 10);
            //printf("point is %d and index is %d\n",point,(len-i));
            len=i;
            life--;
            itoa(life,life_string,10);
            if(life<=0)
            {
                high_score();
                 PlaySound("GameOver.wav",NULL,SND_ASYNC);
                screen = 'o';
            }
            break;
        }
    }
}



//to speed snake up()
void speed_up()
{
    //level 1 speed - 50:
    if(point>=0 && point<=100)
    {
        iResumeTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);

    }
    //level 2 speed : 45
    else if (point >=100 && point <=300)
    {
        iResumeTimer(1);
        iPauseTimer(0);
        iPauseTimer(2);

    }
    //level 3 speed: 35
    else if (point>300)
    {
        iResumeTimer(2);
        iPauseTimer(0);
        iPauseTimer(1);

    }

}


void restart_func()
{
    int x = 200;
    len = 8;
    point = 0;
    itoa(point, point_string, 10);
    life = 3;
    itoa(life,life_string,10);
    direction = 'l';

    for (int i=0; i<len; i++)
    {
        arr[0][i] = x;
        arr[1][i] = 200;
        x += 20;
        //printf("%d with %d\n ", arr[0][i],arr[1][i]);
    }

}


void pause_timers()
{
    if (direction!='t')
    {
        restart_dir = direction;
    }

    //  printf("pause timer len is %d",len);
    direction = 't';
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
}


void resume_timers()
{
    direction = restart_dir;
    // printf("%c",direction);
    // printf("pause timer len is %d",len);
    speed_up();
    iResumeTimer(3);
    iResumeTimer(4);
    iResumeTimer(5);
}
/*
	function iDraw() is called again and again by the system.
	*/
void iDraw()
{
    //place your drawing codes here

    iClear();
    if (screen == 'l')
    {

        iDraw_login();

    }

    else if (screen == 'm')
    {
        iDraw_mainmenu();

    }

    else if(screen == 'h')
    {
        iDraw_leaderboard();

    }
    else if(screen == 'i')
    {
        iDraw_help();

    }


    else if(screen  == 'g')
    {
        //grid();
        if (restart ==1)
        {
            restart_func();
            restart = 0;
        }

        iShowBMP(0,0,"bg.bmp");
        iSetColor(255, 255, 255);
        iFilledRectangle(7, 547, 146, 46);
        iFilledRectangle(567, 547, 226, 46);
        iSetColor(0, 0, 0);
        iFilledRectangle(10, 550, 140, 40);
        iFilledRectangle(570, 550, 220, 40);
        iSetColor(255, 255, 255);
        iText(20, 562, "P o i n t s ", GLUT_BITMAP_HELVETICA_18);
        iText(120, 562, point_string, GLUT_BITMAP_HELVETICA_18);
        iText(580, 562, "H e a l t h ", GLUT_BITMAP_HELVETICA_18);
        for (int j=0; j<life; j++) {
            iShowBMP(670 + j*40, 554, "images/icons/github.bmp");
        }
        if (direction == 't')
        {
            iSetColor(0,0,0);
            iText(600,12,"PRESS a TO RESUME ", GLUT_BITMAP_HELVETICA_12);
        }
        else
        {
            iSetColor(0,0,0);
            iText(600,12,"PRESS space TO PAUSE ", GLUT_BITMAP_HELVETICA_12);
        }

        snake();


        // Setting position and checking co-ordinate match
        // iSetColor(255, 0, 0);
        feed_the_python();

        // Checking co-ordinate match with tetris
        tetris_hit();

        //checking whether ate its own body
        body_eat();

        // Displaying the generated tetris
        drawtetris();

        Generate_spfood();
        Gen_PoisonedFood();

        //speeding up
        speed_up();

        // Displaying food
        iSetColor(235,0,0);
        iFilledCircle(x + 10,y + 10,8,200);
        iSetColor(0,0,0);
        iLine(x + 10,y + 15,x+10,y + 22 );


        // Display pointsiSetColor(255, 255, 255);

    }

    else if(screen = 'o')
    {
        iDraw_gameover();
    }
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
    if (screen=='m')
    {
        iMouseMove_mainmenu(mx,my);
    }
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{

    if (screen == 'l' )
    {
        iMouse_login(button,state,mx,my);
    }
    else if(screen == 'm')
    {
        iMouse_mainmenu(button,state,mx,my);
    }


    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //	printf("x = %d, y= %d\n",mx,my);

    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
    if ( screen == 'g' )
    {
        if (key == 8)
            screen = 'm';
        else if (key == 32)
        {
            pause_timers();
        }
        else if(key=='a')
        {
            resume_timers();
        }
    }
    if (screen == 'l' )
    {
        iKeyboard_login(key);
    }
    else if (screen == 'm')
    {
        iKeyboard_mainmenu(key);
    }
    else if (screen == 'o')
    {
        iKeyboard_gameover(key);
    }
    else if(screen == 'h')
    {
        iKeyboard_leaderboard(key);
    }
    else  if (screen == 'i' )
    {
        iKeyboard_help(key);
    }
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate consta+nts to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

    if (screen == 'm')
    {
        iSpecialKeyboard_mainmenu(key);

    }

    else if(screen == 'o')
    {
        iSpecialKeyboard_gameover(key);
    }

    else if(screen == 'g')
    {
        // Changes the direction of head by Arrow keys
        if (key == GLUT_KEY_DOWN && direction != 'u' )
        {
            direction='d';
        }
        else if (key == GLUT_KEY_LEFT && direction != 'r' )
        {
            direction='l';
        }
        else if (key == GLUT_KEY_RIGHT && direction != 'l' )
        {
            direction='r';
        }
        else if (key == GLUT_KEY_UP && direction != 'd' )
        {
            direction='u';
        }
    }

    //place your codes for other keys here
}


int main()
{

    PlaySound("Opening.wav",NULL,SND_LOOP|SND_ASYNC);
    // Changes the co-ordinate of the snake
    iSetTimer(70, move_snake);
    iSetTimer(50, move_snake);
    iSetTimer(35, move_snake);
    // Generate 1 new tetris
    iSetTimer(3400,generate_tetris);
    iSetTimer(1000,specialFood);
    // Changes the position of  tetris
    iSetTimer(100,movetetris);


    iInitialize(800, 600, "Feed the Python!");
    return 0;
}
