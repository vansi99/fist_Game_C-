#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <iostream>
#include "console.h"
#include "DrawScreen.h"
#include "Bricks.h"
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include<string>
#include"GameState.h"
#include"BlockState.h"
#include"Block.h"
#include"MoveBrick.h"
#include"Player.h"
#include"ToolOfGameLoop.h"
using namespace std;

#define MaxI 22
#define MaxJ 10
#define LEFT 4
#define TOP 4

void GameLoop();

#endif // GAMELOOP_H
