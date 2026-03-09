# include <iostream>
using namespace std;
template<class T>
struct CLinkNode
{
    T data;
    CLinkNode* next;
    CLinkNode():next(nullptr){}
    CLinkNode(T x):data(x),next(nullptr){}
};
template<class T> 
class CLinkList
{
public:
    CLinkNode<T>* head;
    CLinkList()
    {
        head=new CLinkNode<T>();
        head->next=head;
    }
    ~CLinkList()
    {
        CLinkNode<T>* p=head->next,*temp;
        while(p!=head)
        {
            temp=p->next;
            delete p;
            p=temp;
        }
        delete head;
    }
};
//求有多少个为x的元素
template<class T>
int countelem(const CLinkList<T>& a,T x)
{
    int count=0;
    CLinkNode<T>* p=a.head->next;
    while(p!=a.head)
    {
        if(p->data==x) count++;
        p=p->next;
    }
    return count;
}
//利用循环列表解决约瑟夫环
void Joseph(int n,int m)
{
    CLinkList<int> a;
    for(int i=n;i>=1;i--)
    {
        CLinkNode<int>* temp=new CLinkNode<int>(i);
        temp->next=a.head->next;
        a.head->next=temp;
    }
    CLinkNode<int>* p=a.head->next;
    for(int i=0;i<n;i++)
    {
        int j=1;
        while(j!=m)
        {
            j++;
            if(p->next==a.head) p=p->next->next;
            else p=p->next;
        }
        cout<<p->data<<' ';
        CLinkNode<int>* q;
        /*问题：你先让 p->next 指向了下下个节点，然后去 delete p->next。
        此时你删掉的是下下个节点，而不是你原本想替换掉的那个重复节点*/
        if(p->next!=a.head) {p->data=p->next->data;q=p->next->next;delete p->next;p->next=q;}
        else
        {
            p->data=p->next->next->data;
            q=a.head->next->next;
            delete a.head->next;
            a.head->next=q;
        }
    }
    cout<<endl;
}
int main()
{
    Joseph(6,3);
    return 0;
}