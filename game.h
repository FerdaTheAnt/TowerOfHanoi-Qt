#ifndef GAME_H
#define GAME_H

#include "stack.h"
#include <QList>

struct Log
{
    Stack A;
    Stack B;
    Stack C;
};

void fill(Stack * s, int n);
void move(Stack * poleA, Stack * poleB);
void game(Stack* PoleA, Stack* PoleB, Stack* PoleC, int diskNum, QList<Log> *log);

#endif // GAME_H
