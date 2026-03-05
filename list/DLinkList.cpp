# include <iostream>
using namespace std;
template<class T> 
struct DLinkNode
{
    T data;
    DLinkNode<T>* next;
    DLinkNode<T>* prior;
    DLinkNode():next(nullptr),prior(nullptr){}
    DLinkNode(T d):data(a),next(nullptr),prior(nullptr){}
};
template<class T>
class DLinkList
{
public:
    DLinkNode<T>* dhead;
    //头插法建表
    void CreateListF(T a[],int n)
    {
        DLinkNode<T>* s;
        for(int i=0;i<n;i++)
        {
            s=new DLinkNode<T> (a[i]);
            s->next=dhead->next;
            if(dhead->next!=nullptr) dhead->next->prior=s;
            s->prior=dhead;
            dhead->next=s;
        }
    }
    //尾插法
    void CreateListR(T a[],int n)
    {
        DLinkNode<T>* p=this->dhead,*s;
        for(int i=0;i<n;i++)
        {
            s=new DLinkNode<T> (a[i]);
            p->next=s;
            s->prior=p;
            p=s;
        }
        s->next=nullptr;
    }
    DLinkNode<T>* geti(int i)
    {
        if(i<-1) return nullptr;
        DLinkNode<T>* ans=this->dhead;
        int index=-1;
        while(index!=i&&ans!=nullptr)
        {
            index++;
            ans=ans->next;
        }
        return ans;
    }
    //插入元素
    bool insert(int i,T e)
    {
        if(i<0) return false;
        DLinkNode<T>* p=geti(i-1);
        if(p==nullptr) return false;
        DLinkNode<T>* s=new DLinkNode<T>(e);
        s->next=p->next;
        if(p->next!=nullptr) p->next->prior=s;
        s->prior=p;
        p->next=s;
        return true;
    }
    //删除元素
    bool deleteelem(int i)
    {
        if(i<0) return false;
        DLinkNode<T>* p=geti(i);
        if(p==nullptr) return false;
        p->prior->next=p->next;
        if(p->next!=nullptr) p->next->prior=p->prior;
        delete p;//要记得写
        return true;
    }
};
//单链表要记住前驱元素，双链表只用一个元素
template<class T>
bool delx(DLinkList<T>& a,T x)
{
    DLinkNode<T>* p=a.dhead->next;
    while(p!=nullptr)
    {
        if(p->data==x) 
        {
            p->prior->next=p->next;
            if(p->next!=nullptr) p->next->prior=p->prior;
            delete p; 
            return true;
        }
        p=p->next;
    }
    return false;
}
//交换
template<class T>
void swap(DLinkList<T>& a,T x)
{
    DLinkNode<T>* p=a.dhead->next,* q;
    q=nullptr;
    while(p!=nullptr)
    {
        if(p->data==x) q=p;
        p=p->next;
    }
    if(q==nullptr||q==a.dhead->next) return ;
    DLinkNode<T>* pre=q->prior;
    pre->next=p->next;
    if(p->next!=nullptr) p->next->prior=pre;
    pre->prior->next=p;
    p->prior=pre->prior;
    p->next=pre;
    pre->prior=p;
}
int main()
{
    return 0;
}