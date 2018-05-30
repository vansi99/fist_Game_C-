#include "BlockState.h"
#include "GameState.h"

bool Inside(int i, int j)
{
    if(i>=0&&i<MaxI&&j>=0&&j<MaxJ)
        return true;
    else
        return false;
}

bool Left(int i, int j)
{
    if(j>0&&Inside(i,j)==true&&GameState::Board[i][j-1]==0)
        return true;
    else
        return false;
}

bool Right(int i, int j)
{
    if(j<MaxJ-1&&Inside(i,j)==true&&GameState::Board[i][j+1]==0)
        return true;
    else
        return false;
}

bool Down(int i, int j)
{

    if(i<MaxI-1&&Inside(i,j)==true&&GameState::Board[i+1][j]==0)
        return true;
    else
        return false;

}

bool In_Real_Board(int i)
{
    if(i>=3)
        return true;
    else
        return false;
}
