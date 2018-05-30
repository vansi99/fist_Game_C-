#include<iostream>
#include"include\Menu.h"
#include"include\GameLoop.h"
using namespace std;
short menu();

int main()
{
    switch (menu())
    {
    case 1:
        GameLoop();
        break;
    case 2:
        return 0;
    default:
        cout<<"Choose 1~2";
    }

    return 0;
}

short menu(){
    title();

    int select_num = 0;

    cin >> select_num;

    switch (select_num)
    {
    case 1:
    case 2:
    case 3:
        break;
    default:
        select_num = 0;
        break;
    }

    return select_num;
}
