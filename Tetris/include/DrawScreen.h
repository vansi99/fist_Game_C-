#ifndef DRAWSCREEN_H
#define DRAWSCREEN_H
#include "console.h"
#include "GameState.h"
#include "Player.h"
#define LEFT 4
#define TOP 4
#define MaxI 22
#define MaxJ 10

    void DrawBoard();
    void DisplayBoard();
    void Draw_Score_Board(Player_infor infor);
    void Draw_KeyPlayGame();

#endif // DRAWSCREEN_H
