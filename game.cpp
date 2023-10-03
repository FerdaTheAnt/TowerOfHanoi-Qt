#include "game.h"
#include <math.h>
#include <iostream>

void save(Stack* PoleA, Stack* PoleB, Stack* PoleC, QList<Log> *log)
{
    Log l;
    log->append(l);
    log->last().A = *PoleA;
    log->last().B = *PoleB;
    log->last().C = *PoleC;
}

void fill(Stack *s, int n)
{
    for(int i = 0; i < n; i++){
        s->push(n-i);
    }
}

void move(Stack * poleA, Stack * poleB)
{
    int diskA = poleA->top();
    int diskB = poleB->top();
    if(diskA == -2 && diskB == -2){
        std::cerr << "Cannot make a move between two empty poles.";
        return;
    }
    if(diskA == -2){
        poleA->push(diskB);
        poleB->pop();
    }
    else if(diskB == -2){
        poleB->push(diskA);
        poleA->pop();
    }
    else if(diskA < diskB){
        poleB->push(diskA);
        poleA->pop();
    }
    else{
        poleA->push(diskB);
        poleB->pop();
    }
    return;
}

void game(Stack* PoleA, Stack* PoleB, Stack* PoleC, int diskNum, QList<Log> *log)
{
    fill(PoleA, diskNum);
    int m = pow(2, diskNum) - 1;
    save(PoleA, PoleB, PoleC, log);
    for(int i = 0; i<m;i++){
        switch(i%3){
            case 0: move(PoleA, PoleB);
                break;
            case 1: move(PoleA, PoleC);
                break;
            case 2: move(PoleB, PoleC);
                break;
            default:
                break;
        }
        save(PoleA, PoleB, PoleC, log);
    }
}
