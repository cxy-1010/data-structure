# include <iostream>
using namespace std;
template<class T>
struct CDLinkNode
{
    CDLinkNode<T>* next;
    CDLinkNode<T>* prior;
    T data;
    CDLinkNode(T x):data(x),next(nullptr),prior(nullptr){}
    CDLinkNode():next(nullptr),prior(nullptr){}
};
template<class T>
class CDLinkList
{
public:
    CDLinkNode<T>* head;
    CDLinkList()
    {
        head=new CDLinkNode<T> ();
        head->next=head;
        head->prior=head;
    } 
    ~CDLinkList()
    {
        CDLinkNode<T>* p=head->next,*temp;
        while(p!=head)
        {
            temp=p->next;
            delete p;
            p=temp;
        }
        delete head;
    }
};
//合并两个链表
template<class T>
void Comb(CDLinkList<T>& a,CDLinkList<T>& b)
{
    //如果 b 是空的（只有头结点），直接返回
    if (b.head->next == b.head) return;

    //先a尾接上b头
    CDLinkNode<T>* atail=a.head->prior;
    CDLinkNode<T>* bfrist=b.head->next;
    atail->next=bfrist;
    bfrist->prior=atail;
    //再b尾接上ahead
    CDLinkNode<T>* btail=b.head->prior;
    btail->next=a.head;
    a.head->prior=btail;

    // 4. 重要：重置链表 b，防止析构时误删 a 的节点
    b.head->next = b.head;
    b.head->prior = b.head;
}
int main()
{
    return 0;
}