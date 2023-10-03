#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack{
    int capacity;
    int sp;
    int* disks;
public:
    Stack():capacity(0), sp(-1), disks(nullptr){}

    Stack(int n):capacity(n),sp(-1), disks(new int[capacity]){}

    Stack(const Stack &other)
        :capacity(other.capacity)
        ,sp(other.sp)
        ,disks(new int[capacity])
    {
        copyDataFrom(other);
    }

    ~Stack()
    {
        delete[] disks;
    }

    void copyDataFrom(const Stack &other)
    {
        for(int i = 0; i<=this->sp;i++){
            this->disks[i] = other.disks[i];
        }
    }

    bool empty() const
    {
        return(this->sp == -1);
    }

    bool full() const
    {
        return(this->sp == capacity-1);
    }

    void push(const int disk)
    {
        if(full()){
            std::cerr<<"Pushing to full stack.";
            return;
        }
        sp++;
        disks[sp] = disk;
    }

    int top() const
    {
        if(empty()){
            return -2;
        }
        return disks[sp];
    }

    void pop()
    {
        if(empty()){
            std::cerr << "Pop in empty stack.";
            return;
        }
        sp--;
    }

    int read(int at)
    {
        if(at<0 || at >= capacity){
            std::cerr << "Reading stack out of bounds";
            return -1;
        }

        if(empty()){
            return -2;
        }

        return disks[at];
    }

    int getSp()
    {
        return sp;
    }

    int getCapacity()
    {
        return this->capacity;
    }

    Stack& operator=(const Stack &rhs)
    {
        this->sp = rhs.sp;
        this->capacity = rhs.capacity;
        delete[] this->disks;
        this->disks = new int[capacity];
        copyDataFrom(rhs);
        return *this;
    }
};

#endif // STACK_H
