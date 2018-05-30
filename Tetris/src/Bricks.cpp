#include "Bricks.h"
#include <iostream>
#include "console.h"
#include"GameState.h"
using namespace std;
Block *CreateBlock(int ID)
{
    Block *pBlock = new Block[sizeof(Block)];

    switch(ID)
    {
        case 15:
            pBlock ->Row=4;
            pBlock ->Col=1;
            pBlock ->iBoard=0;
            pBlock ->jBoard=5;
            break;
        case 31:
            pBlock ->Row=2;
            pBlock ->Col=2;
            pBlock ->iBoard=2;
            pBlock ->jBoard=5;
            break;
        default:
            pBlock ->Row=2;
            pBlock ->Col=3;
            pBlock ->iBoard=2;
            pBlock ->jBoard=5;
            break;
    }

        pBlock -> arr = new int* [pBlock -> Row] ; // dynamic array point lv 1 about row

        for(int i=0; i< pBlock -> Row; i++)
        {
            pBlock ->arr[i]=new int [pBlock -> Col]; // each row have dynamic array
        }

        /* convert binary of block into decimal */

        for(int i=0; i< pBlock -> Row * pBlock -> Col; i++)
        {
            pBlock -> arr[i/pBlock -> Col][i% pBlock -> Col] = (ID >> (pBlock -> Col * pBlock -> Row - 1 - i)) & 1;
        }

        return pBlock;

}

void Merge_BlockStorage(Block *pBlock)
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

void Draw_Block(Block *pBlock)
{
    int i,j;
    for(i=0; i< pBlock -> Row; i++)
    {
        for(j=0; j< pBlock -> Col; j++)
        {
            if(pBlock -> arr[i][j]==1&&pBlock ->iBoard+i>3)
            {
                TextColor(ColorCode_Red);
                gotoXY(LEFT + pBlock -> jBoard +  j +1, TOP + pBlock -> iBoard + i -3);
                cout<<char(2);
            }
        }
    }
}

void Delete_Block(Block *pBlock)
{
    int i,j;
    for(i=0; i< pBlock -> Row; i++)
    {
        for(j=0; j< pBlock -> Col; j++)
        {
            if(pBlock -> arr[i][j]==1&&pBlock ->iBoard+i>3)
            {
                gotoXY(LEFT + pBlock -> jBoard +  j +1, TOP + pBlock -> iBoard + i -3);
                cout<<" ";
            }
        }
    }
}

void Delete_Memory_Block(Block *pBlock)
{
    int i;
    // Delete Memory of array fist

    for(i=0; i< pBlock ->Row ; i++)
        delete[] pBlock ->arr[i];
    delete[] pBlock ->arr;
    // Then Delete memory block
    delete(pBlock);
    pBlock=NULL;
}

int Random_ID_Block()
{
    int x=rand()%7;
    switch(x)
    {
    case 0:
        return 15;
        break;
    case 1:
        return 31;
        break;
    case 2:
        return 51;
        break;
    case 3:
        return 30;
        break;
    case 4:
        return 58;
        break;
    case 5:
        return 57;
        break;
    case 6:
        return 60;
        break;
    }
}

void Draw_Next_Block(int ID)
{
    Block *pNext_Block=CreateBlock(ID);
    int iRoot=LEFT + MaxJ +5;
    int jRoot=TOP;
    for(int i=0; i< pNext_Block ->Row; i++)
    {
        for(int j=0; j<pNext_Block ->Col; j++)
        {
            if(pNext_Block ->arr[i][j]==1)
            {TextColor(ColorCode_DarkGreen);
            gotoXY(iRoot+j,jRoot + i);
            cout<<char(2);
            }
        }
    }
}

void Delete_Next_Block()
{
    int iRoot=LEFT + MaxJ +5;
    int jRoot=TOP;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            TextColor(ColorCode_Back);
            gotoXY(iRoot+j,jRoot + i);
            cout<<" ";
        }
    }
}

