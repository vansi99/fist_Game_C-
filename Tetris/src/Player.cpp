#include "Player.h"
#include "console.h"
#define MaxI 22
#define MaxJ 10

void New_Game(Player_infor *Infor)
{
    Infor ->level=1;
    Infor ->score=0;
    Infor ->speed=1000;
}

void ClearRow(int row)
{
    int i,j;

    for(i=row; i>0; i--)
        for(j=0; j<MaxJ; j++)
            {
                GameState::Board[i][j]=GameState::Board[i-1][j];
            }
    Sleep(80);
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
            if(GameState::Board[pBlock ->iBoard+i][j]==1)
                temp++;
        }
        if(temp==MaxJ)
        {
            Score+=Score_Each_Row;
            /*một chuỗi combo tương ứng điểm hàng sau bằng điểm hàng trước cộng thêm điểm hàng đầu
              ví dụ ăn 1 hàng được 20 đ combo 3 hàng =điểm hàng 1 + điểm hàng 2(điểm hàng 1+điểm hàng 1)+điểm hàng 3(điểm hang 2 + điểm hàng 1)                      */
            Update_Infor(Infor, Score);
            ClearRow(pBlock ->iBoard +i);
        }
        else{
            i=i-1;

        }
    }while(i>=0);
    return 1;

}
