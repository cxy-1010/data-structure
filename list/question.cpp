# include <iostream>
# include <sstream>
# include <string>
# include <vector>
using namespace std;
struct Data
{
    string data;
    string nex;
    string now;
    Data(){}
    Data(string d,string ne,string n)
    {
        this->data=d;
        this->nex=ne;
        this->now=n;
    }
};
struct LinkNode
{
    Data mydata;
    LinkNode* next;
    LinkNode():next(nullptr) {}
    LinkNode(Data a):mydata(a),next(nullptr){}
};
class LinkList
{
public:
    LinkNode* head;
    LinkList(){head=new LinkNode ();}
    ~LinkList()
    {
        LinkNode* p=head->next,*pre;
        while(p!=nullptr)
        {
            pre=p->next;
            delete p;
            p=pre;
        }
        delete head;
    }
};
int main()
{
    string temp,begin;
    getline(cin,temp);
    istringstream iss(temp);
    int size,index;
    iss>>begin>>size;
    string now,data,next;
    vector<Data> ans;
    for(int i=0;i<size;i++)
    {
        getline(cin,temp);
        istringstream iss(temp);
        iss>>now>>data>>next;
        if(now==begin) {index=i;}
        ans.emplace_back(data,next,now);
    }
    LinkList a;
    LinkNode* p=a.head;
    LinkNode* s=new LinkNode(ans[index]);
    p->next=s;
    p=s;
    for(int i=1;i<size;i++)
    {
        begin=ans[index].nex;
        for(int j=0;j<size;j++)
            if(ans[j].now==begin) {index=j;break;}
        s=new LinkNode(ans[index]);
        p->next=s;
        p=s;
    }
    LinkList a1,a2;
    p=a.head->next;
    LinkNode* a1p=a1.head;//开始的一半
    LinkNode* a2p=a2.head;//后来的一半（倒插）
    for(int i=0;i<size;i++)
    {
        if(i<size/2)
        {
            a1p->next=p;
            a1p=p;
            p=p->next;
        }
        else
        {
            s=p->next;
            p->next=a2p->next;
            a2p->next=p;
            p=s;
        }
    }
    a1p->next=nullptr;
    p=a.head;
    a.head->next=nullptr;
    a1p=a1.head->next;
    a2p=a2.head->next;
    while(a1p!=nullptr)
    {
        (a2p->mydata.nex)=(a1p->mydata.now);
        if(a2p->next!=nullptr) (a1p->mydata.nex)=(a2p->next->mydata.now);
        else (a1p->mydata.nex)="-1";
        s=a1p->next;
        a1p->next=a2p->next;
        a2p->next=a1p;
        a2p=a1p->next;
        a1p=s;
    }
    if(a2p!=nullptr) (a2p->mydata.nex)="-1";
    a2p=a2.head->next;
    while(a2p!=nullptr)
    {
        cout<<(a2p->mydata.now)<<' '<<(a2p->mydata.data)<<' '<<(a2p->mydata.nex)<<endl;
        a2p=a2p->next;
    }
    a1.head->next = nullptr;
    a2.head->next = nullptr;
    return 0;
}