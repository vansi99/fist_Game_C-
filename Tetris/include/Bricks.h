#ifndef BRICKS_H
#define BRICKS_H
#include"Block.h"
#define LEFT 4
#define TOP 4
Block *CreateBlock(int ID);

void Merge_BlockStorage(Block *pBlock);

void Draw_Block(Block *pBlock);

void Delete_Block(Block *pBlock);

void Delete_Memory_Block(Block *pBlock);

int Random_ID_Block();

void Draw_Next_Block(int ID);

void Delete_Next_Block();


#endif // BRICKS_H
