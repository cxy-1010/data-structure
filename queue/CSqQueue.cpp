# include <iostream>
# include <sstream>
# include <string>
# include <vector>
using namespace std;
int MaxSize=10;
template<class T>
class CSqQueue
{
public:
    T* data;
    int front ;
    int rear;
    CSqQueue()
    {
        data=new T[MaxSize];
        front=0;
        rear=0;
    }
    ~CSqQueue() {delete[] data;}
    bool empty() {return front==rear;}
    bool push(T e)
    {
        if(((rear+1)%MaxSize)==front) return false;
        rear=(rear+1)%MaxSize;
        data[rear]=e;
        return true;
    }
    bool pop(T& e)
    {
        if(empty()) return false;
        front=(front+1)%MaxSize;
        e=data[front];
        return true;
    }
    bool gethead(T& e)
    {
        if(empty()) return false;
        int head=(front+1)%MaxSize;
        e=data[head];
        return true;
    }
    bool getrear(T& e)
    {
        if(empty()) return false;
        e=data[rear];
        return true;
    }
    int getsize()  {return (rear-front+MaxSize)%MaxSize;}
    //看当rear在front后面的时候，可以看成MaxSize+rear-front;在前面的时候，可以看作front-rear
};