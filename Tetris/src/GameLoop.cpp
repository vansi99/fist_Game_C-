#include "../include/GameLoop.h"
#include "../include/GameState.h"

int GameState::Board[MaxI][MaxJ];

void GameLoop(){

    clrscr();
    int GamePlay=1;
    Block *currBlock;
    Player_infor infor;
    gotoXY(12,12);
    cout<<"Enter Your Name:";
    cin.ignore(1);
    getline(cin,infor.name);
    clrscr();
    clock_t Start,End;
    srand(time(0));
    currBlock = CreateBlock(Random_ID_Block());
    int IDNext=Random_ID_Block();
    DrawBoard();
    New_Game(&infor);
    Draw_KeyPlayGame();

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
           Merge_BlockStorage(currBlock);
           int result=Test_State_Player(currBlock, &infor);
           if(result==0)
            break;
           Delete_Memory_Block(currBlock);
           currBlock=CreateBlock(IDNext);
           IDNext=Random_ID_Block();
           DisplayBoard();
       }

    }while(GamePlay);

    TextColor(ColorCode_DarkGreen);
    clrscr();
    gameOver(infor.score,infor.name);
}
