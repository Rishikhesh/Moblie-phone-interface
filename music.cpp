#include "music.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include<stdio.h>
 
using namespace std;

void music::add_song()
{
    cout<<endl<<"Enter song title: ";
    cin.ignore();
    gets(title);
}

void music::play_song(string sound)
{
    PlaySound(TEXT(sound),nullptr,SND_ASYNC);
}

string music::return_title()
{
    return title;
}

void music::display_song()
{
    cout<<endl<<title;
}

void music::stop_song()
{
    PlaySound(nullptr,nullptr,0);
}
