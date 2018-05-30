#ifndef PLAYER_H
#define PLAYER_H
#include"Block.h"
#include"GameState.h"
#include<iostream>
#include<string>

struct Player_infor{
    long int score;
    std::string name;
    int level;
    float speed;
};

void New_Game(Player_infor *Infor);
void ClearRow(int row);
int Update_Infor(Player_infor *Infor, long int score);
bool Test_State_Player(Block *pBlock, Player_infor *Infor);

#endif // PLAYER_H
