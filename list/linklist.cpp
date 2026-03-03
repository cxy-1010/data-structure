# include <iostream>
using namespace std;

//单链表
template<class T> 
struct LinkNode
{
    T data;
    LinkNode<T>* next;
    LinkNode():next(nullptr) {}
    LinkNode(T d):data(d),next(nullptr){}
};
template<class T> 
class LinkList
{
public:
    LinkNode<T>* head;

    LinkList() {head=new LinkNode<T>();}
    ~LinkLIst()
    {
        LinkNode<T>* pre,p;
        pre=head;p=pre->next;
        while(p!=nullptr)
        {
            delete pre;
            pre=p;p=p->next;
        }
        delete pre;
    }
    void Add(T e)
    {
        LinkNode<T>* p=head;
        LinkNode<T>* addelem=new LinkNode<T>(e);
        while(p->next!=nullptr)
            p=p->next;
        p->next=addelem;
    }
    int getlength()
    {
        LinkNode<T>* p=head;
        int len=0;
        while(p->next!=nullptr)
        {
            len++;
            p=p->next;
        }
        return len;
    }
    bool GetElem(int i,T& e)
    {
        if(i<0) return false;
        LinkNode<T>* p=geti(i);
        if(p!=nullptr)
        {
            e=p->data;
            return true;
        }
        else return false;
    }
    bool SetElem(int i,const T& e)
    {
        if(i<0) return false;
        LinkNode<T>* p=geti(i);
        if(p!=nullptr)
        {
            p->data=e;
            return true;
        }
        else return false;
    }
    int GetNo(const T& e)
    {
        int j=0;
        LinkNode<T>* p=head->next;
        while(p!=nullptr&&p->data!=e)
        {
            j++;
            p=p->next;
        }
        if(p!=nullptr) return j;
        else return -1;
    }
    //插入元素,将e作为第i个元素
    bool Insert(int i,T e)
    {
        if(i<0) return false;
        LinkNode<T>* p=geti(i-1);
        if(p==nullptr) return false;
        LinkNode<T>* s=new LinkNode<T>(e);
        s->next=p->next;
        p->next=s;
        return true;
    }
    //删除元素
    bool Delete(int i)
    {
        if(i<0) return false;
        LinkNode<T>* p=geti(i-1);
        if(p==nullptr) return false;
        if(p->next==nullptr) return false;
        LinkNode<T>* s=p->next;
        p->next=s->next;
        delete s;
        return true;
    }
    //输出所有节点值
    void display()
    {
        LinkNode<T>* p=this->head->next;
        while(p!=nullptr)
        {
            cout<<p->data<<' ';
            p=p->next;
        }
        cout<<endl;
    }
    //头插法
    void CreatelistF(T a[],int n)
    {
        for(int i=0;i<n;i++)
        {
            LinkNode<T>* temp=new LinkNode<T> (a[i]);
            temp->next=head->next;
            head->next=temp;//若{1，2，3，4}插入后为{4，3，2，1} 
        }
    }
    //尾插法
    void CreatelistR(T a[],int n)
    {
        LinkNode<T>* temp=head;
        for(int i=0;i;<n;i++)
        {
            LinkNode<T>* s=new ListNode<T> (a[i]);
            temp->next=s;
            temp=s;
        }
    }
    //-1<=i<n
    LinkNode<T>* geti(int i)
    {
        if(i<-1) return nullptr;
        LinkNode<T>* ans=head;
        int j=-1;
        while(j<i&&ans!=nullptr)
        {
            j++;
            ans=ans->next;
        }
        return ans;
    }
};
//获得中间元素
//方法一：计数法
template<class T>
T Middle1(const LinkList<T>& a)
{
    int j=1;
    int len=a.getlength();
    LinkNode<T>* p=a.head->next;
    while(j<=(len/2))
    {
        j++;
        p=p->next;
    }
    return p->data;
}
//方法二：快慢指针法
template<class T>
T middle2(const LinkList<T>& a)
{
    LinkNode<T>* slow=a.head->next;
    LinkNode<T>* fast=a.head->next;
    while(slow!=nullptr||fast!=nullptr)
    {
        if(fast->next==nullptr||fast->next->next==nullptr) 
            return slow->data;
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main()
{
    return 0;
}