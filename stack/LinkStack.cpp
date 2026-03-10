# include <iostream>
using namespace std;
template<class T>
struct LinkNode
{
    T data;
    LinkNode<T>* next;
    LinkNode():next(nullptr){}
    LinkNode(const T& e):data(e),next(nullptr){}
};
template<class T>
class LinkStack
{
public:
    LinkNode<T>* head;
    LinkStack()
    {
        head=new LinkNode<T>();
    }
    ~LinkStack()
    {
        LinkNode<T>* pre,*p=head->next;
        while(p!=nullptr)
        {
            pre=p->next;
            delete p;
            p=pre;
        }
        delete head;
    }
    bool empty(){return head->next==nullptr;}
    bool push(const T& e)
    {
        LinkNode<T>* p=new LinkNode<T>(e);
        p->next=head->next;
        head->next=p;
        return true;
    }
    bool pop(T& e)
    {
        if(empty()) return false;
        LinkNode<T>* p=head->next;
        e=p->data;
        head->next=head->next->next;
        delete p;
        return true;
    }
    bool gettop(T& e)
    {
        if(empty()) return false;
        e=head->next->data;
        return true;
    }
};

int main()
{
    return 0;
}