#include "DrawScreen.h"
#include<iostream>
#include"console.h"
#include"ColorDisplay.h"
#define LEFT 4
#define TOP 4
using namespace std;
DrawScreen::DrawScreen()
{
    //ctor
}

DrawScreen::~DrawScreen()
{
    //dtor
}

void DrawScreen:: DrawBoard() // draw board have row 10 col 20
{
    for(int i=LEFT; i<=LEFT+10+1; i++)
    {

        for(int j=TOP; j<=TOP+18+1; j++)
        {

            if((j==TOP||j==TOP+18+1)&&i>LEFT&&i<LEFT+10+1)
            {
                gotoXY(i,j);
                TextColor(7);
                cout<<char(205);
            }

            if((i==LEFT||i==LEFT+10+1)&&j>TOP&&j<TOP+18+1)
            {
                gotoXY(i,j);
                TextColor(7);
                cout<<char(186);
            }
        }

        gotoXY(LEFT,TOP);TextColor(ColorCode_DarkRed);cout<<char(219);
        gotoXY(LEFT+10+1,TOP);TextColor(ColorCode_DarkRed);cout<<char(219);
        gotoXY(LEFT,TOP+18+1);TextColor(ColorCode_DarkRed);cout<<char(219);
        gotoXY(LEFT+10+1,TOP+18+1);TextColor(ColorCode_DarkRed);cout<<char(219);
    }
}
