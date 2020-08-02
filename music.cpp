#include "music.h"
#include <iostream>
using namespace std;
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include<stdio.h>

void music::add_song()
{
    cout<<endl<<"Enter song title: ";
    cin.ignore();
    gets(title);
}

void music::play_song(char sound[40])
{
    PlaySound(TEXT(sound),NULL,SND_ASYNC);
}

char* music::return_title()
{
    return title;
}

void music::display_song()
{
    cout<<endl<<title;
}

void music::stop_song()
{
    PlaySound(NULL,NULL,0);
}
