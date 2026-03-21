# include <iostream>
# include <iomanip>
using namespace std;
template<class T> 
struct LinkNode
{
    T data;
    LinkNode<T>* next;
    LinkNode():next(nullptr) {}
    LinkNode(T d):data(d),next(nullptr){}
};
int main()
{
    int n;
    cin>>n;
    LinkNode<int>* head=new LinkNode<int>(1);
    head->next=head;
    LinkNode<int>* p=head,* s;
    for(int i=2;i<=n;i++)
    {
        s=new LinkNode<int>(i);
        p->next=s;
        p=s;
        s->next=head;
    }
    int m,index=1;
    LinkNode<int>* temphead,*tempp;
    while(cin>>m)
    {
        index=1;
        p=head;
        for(int i=0;i<n;i++)
        {
            index=1;
            while(index!=m)
            {
                index++;
                p=p->next;
            }
            if(i==0) 
            {
                int temp=p->data;
                p->data=p->next->data;
                p->next->data=temp;
                temphead=p->next;
                tempp=p->next;
                p->next=p->next->next;
            }
            else 
            {
                int temp=p->data;
                p->data=p->next->data;
                p->next->data=temp;
                tempp->next=p->next;
                p->next=p->next->next;
                tempp=tempp->next;
                tempp->next=temphead;
            }
        }
        head=temphead;
    }
    p=head;
    cout<<setw(4)<<right<<p->data;
    p=p->next;
    while(p!=head)
    {
        cout<<setw(4)<<right<<p->data;
        p=p->next;
    }
    cout<<endl;
    return 0;
}