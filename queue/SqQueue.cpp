# include <iostream>
using namespace std;
const int MaxSize=100;
template<class T>
class SqQueue
{
public:
    T* data;
    int front,rear;
    SqQueue()
    {
        data=new T[MaxSize];
        front=-1;
        rear=-1;
    }
    ~SqQueue()
    {
        delete[] data;
        front=-1;rear=-1;
    }
    bool empty(){return front==rear;}
    bool push(const T& e)
    {
        if(rear==MaxSize) return false;
        rear++;
        data[rear]=e;
        return true;
    }
    bool pop(T& e)
    {
        if(empty()) return false;
        front++;
        e=data[front];
        return true;
    }
    bool gethead(T& e)
    {
        if(empty()) return false;
        int head=front+1;
        e=data[head];
        return true;
    }
}
int main()
{

    return 0;
}