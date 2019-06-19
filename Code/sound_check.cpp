#include<iostream>
#include<windows.h>
#include <mmsystem.h>
using namespace std;

main()
{
    PlaySound("AppleEat.wav",NULL,SND_ASYNC);
}
