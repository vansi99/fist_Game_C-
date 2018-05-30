#include "ToolOfGameLoop.h"
#include "console.h"
#include<conio.h>
#include<iostream>
using namespace std;

void Pause(char Key_Input){
    int enter=13;
    int esc=27;

    if(Key_Input==esc){
        gotoXY(18,15);
        TextColor(ColorCode_Yellow);
        do{
            Key_Input=getch();
        }while(Key_Input!=enter);

    }
}

void gameOver(long int score,string name)
{
    gotoXY(5,3);
    TextColor(ColorCode_DarkRed);
    gotoXY(5,4); cout << " GGGGG     A    M     M EEEEEEE  OOOOO  V     V EEEEEEE RRRRRR\n" ; Sleep(50);
    gotoXY(5,5); cout << "G     G   A A   MM   MM E       O     O V     V E       R     R\n"; Sleep(50);
    gotoXY(5,6); cout << "G        A   A  M M M M E       O     O V     V E       R     R\n"; Sleep(50);
    gotoXY(5,7); cout << "G  GGGG A     A M  M  M EEEEE   O     O V     V EEEEE   RRRRRR\n"; Sleep(50);
    gotoXY(5,8); cout << "G     G AAAAAAA M     M E       O     O  V   V  E       R   R\n"; Sleep(50);
    gotoXY(5,9); cout << "G     G A     A M     M E       O     O   V V   E       R    R\n"; Sleep(50);
    gotoXY(5,10);cout << " GGGGG  A     A M     M EEEEEEE  OOOOO     V    EEEEEEE R     R\n"; Sleep(50);

    cout<<"\n"<<name<<"'s score: " <<score<<endl; Sleep(50);
    cout << "\n\nPress any key and enter\n"; Sleep(50);
    getch();
}
