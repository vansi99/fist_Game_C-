#ifndef DRAWSCREEN_H
#define DRAWSCREEN_H

#include "console.h"
#define LEFT 4
#define TOP 4
class DrawScreen
{
    public:
        DrawScreen();
        virtual ~DrawScreen();
        void DrawBoard();

    protected: private:
};

#endif // DRAWSCREEN_H
