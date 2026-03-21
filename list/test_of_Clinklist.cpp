# include <iostream>
# include <string>
using namespace std;
int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    if(a.length()!=b.length())
    {
        cout<<0<<endl;
        return 0;
    }
    b=(b+b);
    int  i=b.find(a);
    if(i!=-1) cout<<1<<endl;
    else cout<<2<<endl;
    return 0;
}


























/* include <iostream>
# include <string>
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
    string a,b;
    getline(cin,a);
    getline(cin,b);
    LinkNode<char>* ahead=new LinkNode<char>(a[0]);
    LinkNode<char>* bhead=new LinkNode<char>(b[0]);
    ahead->next=ahead;
    bhead->next=bhead;
    LinkNode<char>* pa=ahead;
    LinkNode<char>* pb=bhead;
    int lena=a.length();
    int lenb=b.length();
    if(lena!=lenb) {cout<<0<<endl; return 0;}
    LinkNode<char>* s;
    for(int i=0;i<lena;i++)
    {
        s=new LinkNode<char>(a[i]);
        pa->next=s;
        s->next=ahead;
        pa=s;
    }
    for(int i=0;i<lenb;i++)
    {
        s=new LinkNode<char>(b[i]);
        pb->next=s;
        s->next=bhead;
        pb=s;
    }
    pa=ahead->next;
    pb=bhead->next;
    bool is=true;
    int index=1;
    while(is)
    {
        if(pa->data==pb->data)
        {
            int temp=1;
            while(pa->data==pb->data)
            {
                pa=pa->next;
                pb=pb->next;
                temp++;
            }
            if(temp==lena) {is=false;}
            else index++;
        }
        else
        {
            pb=pb->next;
            if(index==lena) break;
            index++;
        }
    }
    if(!is) {cout<<1<<endl;}
    else {cout<<0<<endl;}
    return 0;
}*/