#include <iostream>

using namespace std;

class Array
{
    private:
    int length;
    int maxSize;
    int cur;
    int *list;

    public:
    Array::Array(int maxSize)
    {
        cur = length = 0;
        this->maxSize = maxSize;
        this ->list = new int[maxSize];
    }
    ~Array()
    {
        delete[] list;

    }

    //is full?

    bool full()
    {
        return length == maxSize;
    }

    //insert at curr


    bool insetrCur(int value)
    {
        if(full()) return false;

        for(int i = length ; i > cur; --i)
        {
            list[i] = list[i -1];
        }

        list[cur] = value;
        length ++;
        return true;
    }



};