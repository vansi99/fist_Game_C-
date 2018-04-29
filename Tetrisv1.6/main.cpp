#include <iostream>
#include "console.h"
#include "ColorDisplay.h"
#include "DrawScreen.h"
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

#define MaxI 22
#define MaxJ 10
#define LEFT 4
#define TOP 4

int Board[MaxI][MaxJ];



void DisplayBoard();

void ClearRow(int row);


struct Block{
    int **arr;
    int Row,Col;
    int iBoard,jBoard;
};

/* ID
square: 31;
L: 57 60 ;
I: 15;
z: 51 30;
*/


Block *CreateBlock(int ID);

bool Inside(int i, int j);


bool Left(int i, int j);


bool Right(int i, int j);


bool Down(int i, int j);

bool In_Real_Board(int i);

void TurnLeft(Block *pBlock);


                        /* MOVE BLOCK  */

void TurnRight(Block *pBlock);


int Drop(Block *pBlock);


void Merge_Storage(Block *pBlock);


void Rotate(Block *pBlock);

void Draw_Block(Block *pBlock);


void Delete_Block(Block *pBlock);

                            /* PLAYER INFORMATION*/
struct Player_infor{
    long int score;
    int level;
    float speed;
};

void New_Game(Player_infor *Infor);


int Update_Infor(Player_infor *Infor, long int score);


void Draw_Score_Board(Player_infor infor);

bool Test_State_Player(Block *pBlock, Player_infor *Infor);

void Delete_Memory_Block(Block *pBlock);


int Random_ID_Block();


void Draw_Next_Block(int ID);


void Delete_Next_Block();

void Pause(char Key_Input);

int main()
{
    Block *currBlock;
    Player_infor infor;
    clock_t Start,End;
    srand(time(0));
    currBlock = CreateBlock(Random_ID_Block());
    int IDNext=Random_ID_Block();
    DrawBoard();
    New_Game(&infor);

    do{

        Draw_Score_Board(infor);
        Draw_Block(currBlock);
        Delete_Next_Block();
        Draw_Next_Block(IDNext);
        Start=clock();
       do{
           if(_kbhit())
           {
              char Key_Input= toupper(getch()); // take code key down
              Pause(Key_Input);
              Delete_Block(currBlock); // delete bock
              switch(Key_Input)
              {
              case 'W': case 72:
                Rotate(currBlock);
                break;
              case 'A': case 75:
                TurnLeft(currBlock);
                break;
              case 'D': case 77:
                TurnRight(currBlock);
                break;
              case 'S': case 80:
                Drop(currBlock);
                break;
              }
            Draw_Block(currBlock);
        }
        End=clock();
       }while((End-Start)<infor.speed);
       Delete_Block(currBlock);
       if(Drop(currBlock)==0) //cant drop
       {
           Merge_Storage(currBlock);
           int result=Test_State_Player(currBlock, &infor);
           if(result==0)
            break;
           Delete_Memory_Block(currBlock);
           currBlock=CreateBlock(IDNext);
           IDNext=Random_ID_Block();
           DisplayBoard();
       }

    }while(1);
    TextColor(LIGHT_GREEN);
    clrscr();
    cout<<"Game Over!!! \nYour score: " <<infor.score;
	_getch();
}



void DisplayBoard()
{
    int i,j;
    for(i=0; i<MaxI; i++)
    {
        for(j=0; j<MaxJ; j++)
        {

            if(Board[i][j]==1&&i>=4)
            {gotoXY(j+LEFT+1, i+TOP+1-4);
             TextColor(15);
             cout<<char(2);
            }

            if(Board[i][j]==0&&i>4)
            {
                TextColor(BLACK);
                gotoXY(j+LEFT+1,i+TOP+1-4);
                cout<<" ";
            }
        }
    }
}


void ClearRow(int row)
{
    int i,j;

    for(i=row; i>0; i--)
        for(j=0; j<MaxJ; j++)
            Board[i][j]=Board[i-1][j];
}


/* ID
square: 31;
L: 57 60 ;
I: 15;
z: 51 30;
*/


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

bool Inside(int i, int j)
{
    if(i>=0&&i<MaxI&&j>=0&&j<MaxJ)
        return true;
    else
        return false;
}

bool Left(int i, int j)
{
    if(j>0&&Inside(i,j)==true&&Board[i][j-1]==0)
        return true;
    else
        return false;
}

bool Right(int i, int j)
{
    if(j<MaxJ-1&&Inside(i,j)==true&&Board[i][j+1]==0)
        return true;
    else
        return false;
}

bool Down(int i, int j)
{

    if(i<MaxI-1&&Inside(i,j)==true&&Board[i+1][j]==0)
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
                Board[pBlock -> iBoard+i][pBlock -> jBoard+j]=1;
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
               || Board[pBlock ->iBoard +i][pBlock ->jBoard +j] ==1 )
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

void Draw_Block(Block *pBlock)
{
    int i,j;
    for(i=0; i< pBlock -> Row; i++)
    {
        for(j=0; j< pBlock -> Col; j++)
        {
            if(pBlock -> arr[i][j]==1&&pBlock ->iBoard+i>3)
            {
                TextColor(LIGHT_RED);
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
                            /* PLAYER INFORMATION*/


void New_Game(Player_infor *Infor)
{
    Infor ->level=1;
    Infor ->score=0;
    Infor ->speed=1000;
}

int Update_Infor(Player_infor *Infor, long int score)
{

    if((Infor ->score%100)+score>=100)
    {
        Infor ->level ++;
        if(Infor ->speed >200)
        {Infor ->speed -=100;
        }
    }

    Infor ->score+=score;

    return 0;

}

void Draw_Score_Board(Player_infor infor)
{
    TextColor(LIGHT_YELLOW);
    gotoXY(LEFT+MaxJ+2,10);
    cout<<"Score:  "<<infor.score;
    gotoXY(LEFT+MaxJ+2,11);
    cout<<"Level:  "<<infor.level;
}

bool Test_State_Player(Block *pBlock, Player_infor *Infor)
{
    int i,j,temp;
    i=pBlock ->Row-1;
    int Game_Over=0;
    long int Score_Each_Row=20;
    if(pBlock ->iBoard<=3) return Game_Over;
    // test from row-1 to row <=3 of block
    long int Score=0;
    do{
        temp=0;

        for(j=0; j<MaxJ; j++)
        {
            if(Board[pBlock ->iBoard+i][j]==1)
                temp++;
        }
        if(temp==MaxJ)
        {
            Score+=Score_Each_Row;
            /*một chuỗi combo tương ứng điểm hàng sau bằng điểm hàng trước cộng thêm điểm hàng đầu
              ví dụ ăn 1 hàng được 20 đ combo3 =điểm hàng 1 + điểm hàng 2=(điểm hàng 1+điểm hàng 1)+điểm hàng 3(=điểm hang 2 + điểm hàng 1)                      */
            Update_Infor(Infor, Score);
            ClearRow(pBlock ->iBoard +i);
            Sleep(80);
        }
        else{
            i=i-1;

        }
    }while(i>=0);
    return 1;

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
            {TextColor(LIGHT_GREEN);
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
            TextColor(BLACK);
            gotoXY(iRoot+j,jRoot + i);
            cout<<" ";
        }
    }
}

void Pause(char Key_Input){
    int enter=13;
    int esc=27;

    if(Key_Input==esc){
        gotoXY(18,15);
        TextColor(YELLOW);
        do{
            Key_Input=getch();
        }while(Key_Input!=enter);

    }
}
