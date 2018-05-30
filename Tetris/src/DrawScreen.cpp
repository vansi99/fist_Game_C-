#include<iostream>
#define LEFT 4
#define TOP 4
#include"../include/DrawScreen.h"
#include"console.h"
#include"../include/GameState.h"
using namespace std;

void DrawBoard() // draw board have row 10 col 20
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

void DisplayBoard()
{
    int i,j;
    for(i=0; i<MaxI; i++)
    {
        for(j=0; j<MaxJ; j++)
        {

            if(GameState::Board[i][j]==1&&i>=4)
            {gotoXY(j+LEFT+1, i+TOP+1-4);
             TextColor(15);
             cout<<char(2);
            }

            if(GameState::Board[i][j]==0&&i>4)
            {
                TextColor(ColorCode_Back);
                gotoXY(j+LEFT+1,i+TOP+1-4);
                cout<<" ";
            }
        }
    }
}

void Draw_Score_Board(Player_infor infor)
{
    TextColor(ColorCode_Yellow);
    gotoXY(LEFT+MaxJ+3,9);
    cout<<"Your Name:"<<infor.name;
    gotoXY(LEFT+MaxJ+3,10);
    cout<<"Score:  "<<infor.score;
    gotoXY(LEFT+MaxJ+3,11);
    cout<<"Level:  "<<infor.level;
}

void Draw_KeyPlayGame(){
    TextColor(ColorCode_DarkYellow);
    gotoXY(LEFT+MaxJ+3,12);
    cout<<"Instruction:";
    TextColor(ColorCode_Blue);
    gotoXY(LEFT+MaxJ+3,13);
    cout<<"Press W or Arrow up to rotate bricks";
    gotoXY(LEFT+MaxJ+3,14);
    cout<<"Press A or Arrow left to move bricks left";
    gotoXY(LEFT+MaxJ+3,15);
    cout<<"Press D or Arrow right to move bricks right";
    gotoXY(LEFT+MaxJ+3,16);
    cout<<"Press S or Arrow down to drop bricks faster";
    TextColor(ColorCode_Pink);
    gotoXY(LEFT+MaxJ+3,17);
    cout<<"Press Esc to pause your game";
    gotoXY(LEFT+MaxJ+3,18);
    cout<<"Press Enter to resume your game";
}


