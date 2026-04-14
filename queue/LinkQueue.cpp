# include <iostream>
using namespace std;
template<class T>
struct LinkNode
{
    T data;
    LinkNode<T>* next;
    LinkNode():next(nullptr){}
    LinkNode(T d):data(d),next(nullptr){}
};
template<class T>
class LinkQueue
{
public:
    LinkNode<T>* front;
    LinkNode<T>* rear;
    LinkQueue()
    {
        front=nullptr;
        rear=nullptr;
    }
    ~LinkQueue()
    {
        LinkNode<T>* temp;
        rear=nullptr;
        while(front!=nullptr)
        {
            temp=front->next;
            delete front;
            front=temp;
        }
    }
    bool empty(){return rear==nullptr;}
    
};
int main()
{

    return 0;
}