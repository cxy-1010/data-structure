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
//求最大值个数
template<class T> 
int maxcount(const LinkList<T>& a)
{
    int count=0;
    LinkNode<T>* p=a.head->next;
    T tmax=p->data;//设置一个暂时的最大值使得只用遍历一遍
    while(p!=nullptr)
    {
        if(p->data>tmax)
        {
            tmax=p->data;
            count=1;
        }
        else if(p->data==tmax)
            count++;
        p=p->next;
    }
    return count;
}
//删除最大值的节点
template<class T>
void Deletemax(LinkList<T>& a)
{
    LinkNode<T>* p=a.head->next;
    T max=p->data;
    while(p!=nullptr)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    LinkNode<T>* pre=a.head //考虑到第一个可能是最大值
    p=pre->next;//要注意需要更新p
    while(p!=nullptr)
    {
        if(p->data==max)
        {
            pre->next=p->next;
            delete p;
            p=pre->next;
        }
        else//注意这里有个else因为上一个已经完成了
        {
            p=p->next;
            pre=pre->next;
        }
    }
}
int main()
{
    return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* begin=new ListNode(0,head);
        ListNode* swap1=head;
        if(swap1==nullptr) return head;
        ListNode* swap2=head->next;
        if(swap2==nullptr) return head;
        head=swap2;//注意这个交换
        while(swap1!=nullptr&&swap2!=nullptr)
        {
            swap1->next=swap2->next;
            swap2->next=swap1;
            begin->next=swap2;
            begin=swap1;
            swap1=begin->next;
            if(swap1==nullptr) return head;
            swap2=begin->next->next;
            if(swap2==nullptr) return head;
        }
        return head;        
    }
};
*/