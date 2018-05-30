#include "MoveBrick.h"
#include "BlockState.h"
#include"GameState.h"
#define MaxI 22
#define MaxJ 10
#include"Block.h"
void TurnLeft(Block *pBlock)
{
    for(int i=0; i < pBlock -> Row; i++)
        for(int j=0; j <pBlock -> Col; j++)
            {if(pBlock->arr[i][j] == 1)
                {
                    if(Left( pBlock ->iBoard+i, pBlock -> jBoard +j ) == false
                       ||In_Real_Board( pBlock -> iBoard ) == false)
                        return;
                }
            }
            pBlock -> jBoard -= 1;

}

                        /* MOVE BLOCK  */

void TurnRight(Block *pBlock)
{
    for(int i=0; i < pBlock -> Row; i++)
        for(int j=0; j <pBlock -> Col; j++)
            {if(pBlock->arr[i][j] == 1)
                {
                    if(Right( pBlock ->iBoard+i, pBlock -> jBoard +j ) == false
                       ||In_Real_Board( pBlock -> iBoard ) == false)
                        return;
                }
            }
            pBlock -> jBoard += 1;

}

int Drop(Block *pBlock)
{
    int Can_Drop = 1;
    int Cant_Drop = 0;
    for(int i=0; i < pBlock -> Row; i++)
        for(int j=0; j <pBlock -> Col; j++)
            {if(pBlock->arr[i][j] == 1)
                {
                    if(Down( pBlock ->iBoard+i, pBlock -> jBoard +j ) == false )
                        return Cant_Drop;
                }
            }
            pBlock -> iBoard += 1;
            return Can_Drop;

}

void Merge_Storage(Block *pBlock)
{
    for(int i=0 ; i< pBlock -> Row; i++)
    {
        {for(int j=0; j< pBlock -> Col; j++)
            if(pBlock ->arr[i][j]==1)
            {
                GameState::Board[pBlock -> iBoard+i][pBlock -> jBoard+j]=1;
            }
        }
    }
}



void Rotate(Block *pBlock)
{
    int i,j;
    int ** exArr;
    int exRow = pBlock -> Col;
    int exCol = pBlock -> Row;
    // create extra matrix 2-D
    exArr = new int *[exRow];


    for(i=0; i < exRow; i++)
    {
        exArr[i] = new int [exCol];
    }
    // Rotate 90
    for(i= pBlock -> Row -1; i>=0; i--)
    {
        for(j= pBlock -> Col - 1; j>= 0; j--){
            exArr[j][pBlock  -> Row-i-1] =pBlock ->arr[i][j];
        }
    }

    // test can Rotate
    for (i=0; i< exRow; i++)
    {
        for(j=0; j< exCol; j++)
        {
            if(pBlock->jBoard+j>=MaxJ)//fix bug right rotate
                pBlock->jBoard-=1;
            if(Inside(pBlock ->iBoard +i, pBlock ->jBoard +j)==false
               || GameState::Board[pBlock ->iBoard +i][pBlock ->jBoard +j] ==1 )
                return;
        }
    }
    for(i=0; i< pBlock ->Row; i++)
    delete[] pBlock ->arr[i];
    delete[] pBlock ->arr;
    // Update
    pBlock ->Col = exCol;
    pBlock ->Row = exRow;
    pBlock ->arr = exArr;


}
