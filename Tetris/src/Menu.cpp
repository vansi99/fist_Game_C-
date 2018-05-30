#include "Menu.h"
#include "console.h"
#include <iostream>
using namespace std;

void title()
{
    clrscr();
    TextColor(ColorCode_Yellow);
    cout << "#==============================================================================#\n"; Sleep(50);

    gotoXY(9,5); cout << "TTTTTTT EEEEEEE TTTTTTT RRRRRR    III    SSSSS\n"; Sleep(50);
    gotoXY(9,6); cout << "   T    E          T    R     R    I    S     S\n"; Sleep(50);
    gotoXY(9,7); cout << "   T    E          T    R     R    I    S\n"; Sleep(50);
    gotoXY(9,8); cout << "   T    EEEEE      T    RRRRRR     I     SSSSS\n"; Sleep(50);
    gotoXY(9,9); cout << "   T    E          T    R   R      I          S\n"; Sleep(50);
    gotoXY(9,10);cout << "   T    E          T    R    R     I    S     S\n"; Sleep(50);
    gotoXY(9,11);cout << "   T    EEEEEEE    T    R     R   III    SSSSS\n"; Sleep(50);
    gotoXY(9,12);cout << "\n\n\n\n";

    cout << "\t<Menu>\n"; Sleep(50);
    cout << "\t1: Start Game\n\t2: Quit\n\n"; Sleep(50);

    cout << "#==============================================================================#\n"; Sleep(50);
    cout << "Choose >> "; Sleep(50);
}
