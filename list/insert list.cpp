# include <iostream>
using namespace std;
struct mylist
{
    int n;
    mylist * next;
    mylist(int n)
    {
        this->n=n;
        next=nullptr;
    }
};
int main()
{
    mylist* begin;
    begin=new mylist(0);
    mylist* temp1=begin;
    for(int i=1;i<10;i++)
    {
        mylist* temp=new mylist(i);
        temp1->next=temp;
        temp1=temp;
    }
    mylist* a=begin;
    while(a!=nullptr)
    {
        cout<<a->n<<' ';
        a=a->next;
    }
    cout<<endl;
    
    //开始倒叙
    //1.我的方法：原地反转法
    mylist* p=begin->next;
    mylist* q=p->next;
    p->next=begin;
    begin->next=nullptr;
    while(q->next!=nullptr)
    {
        mylist* temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    q->next=p;
    begin=q;
    mylist* a1=begin;
    while(a1!=nullptr)
    {
        cout<<a1->n<<' ';
        a1=a1->next;
    }
    cout<<endl;

    //2.头插法
    /*
    头插法：不管队伍多长，新来的人永远直接插在领头人的正后方。
    结果：最后来的人反而排在了最前面，所以头插法建立的链表数据是逆序的。
    */
    mylist* lead=new mylist(-1);
    lead->next=nullptr;

    mylist* curr=begin;
    while(curr!=nullptr)
    {
        mylist* temp=curr->next;
        curr->next=lead->next;
        lead->next=curr;
        curr=temp;
    }
    begin=lead->next;
    mylist* a2=begin;
    while(a2!=nullptr)
    {
        cout<<a2->n<<' ';
        a2=a2->next;
    }
    cout<<endl;
    return 0;
}