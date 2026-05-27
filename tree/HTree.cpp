# include <iostream>
# include <fstream>
# include <vector>
# include <queue>
# include <string>
# include <sstream>
# include <algorithm>
using namespace std;
struct HTNode
{
    char data;
    double weight;
    int parent;
    int lchild;
    int rchild;
    bool flag;//看是左节点还是右节点
    HTNode(){parent=-1;lchild=rchild=-1;}
    HTNode(char d,double w)
    {
        data=d;
        weight=w;
        parent=-1;lchild=rchild=-1;
        flag=true;
    }
};
struct HTCode
{
    string code;
    char val;
    HTCode(){}
    HTCode(const string& c,char val):code(c),val(val){}
};
struct HeapNode
{
    double weight;
    int i;
    HeapNode(){}
    HeapNode(double w,int index):weight(w),i(index){}
    bool operator<(const HeapNode& s)const
    {
        if(weight==s.weight) return i>s.i;
        return weight>s.weight;
    }
};
void CreateHT(const vector<char>& c_arr,const vector<double>& w_arr,vector<HTNode>& ht)
{
    int size=c_arr.size();
    priority_queue<HeapNode> pq;
    for(int i=0;i<size;i++)
    {
        ht[i]=(HTNode(c_arr[i],w_arr[i]));
        pq.push(HeapNode(w_arr[i],i));
    }
    for(int i=size;i<2*size-1;i++)
    {
        HeapNode p1=pq.top();pq.pop();
        HeapNode p2=pq.top();pq.pop();
        ht[i].weight=p1.weight+p2.weight;
        ht[i].lchild=p1.i;
        ht[i].rchild=p2.i;
        ht[p1.i].parent=i;
        ht[p2.i].parent=i;
        ht[p1.i].flag=true;
        ht[p2.i].flag=false;
        pq.push(HeapNode(ht[i].weight,i));
    }
}
void CreateHCode(const vector<HTNode>& ht,vector<HTCode>& hcd)
{
    int size=hcd.size();
    for(int i=0;i<size;i++)
    {
        string code;
        char val=ht[i].data;
        int j=i;
        while(ht[j].parent!=-1)
        {
            if(ht[j].flag) {code+='0';}
            else {code+='1';}
            j=ht[j].parent;
        }
        reverse(code.begin(),code.end());
        hcd[i]=HTCode(code,val);
    }
}
string decode(const vector<HTNode>& ht,string project)
{   
    int size=ht.size();
    HTNode root=ht[size-1],p;
    int len=project.length();
    string ans;
    for(int i=0;i<len;i++)
    {
        if(project[i]=='0')
        {
            if(i==0) p=ht[root.lchild];
            else p=ht[p.lchild];
        }
        if(project[i]=='1')
        {
            if(i==0) p=ht[root.rchild];
            else p=ht[p.rchild];
        }
        if(p.lchild==-1&&p.rchild==-1)
            {ans+=p.data;p=root;}
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    string temp;
    vector<char> c_arr;
    vector<double> w_arr;
    char c;double w;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        temp[1]=' ';
        istringstream iss(temp);
        iss>>c>>w;
        c_arr.push_back(c);
        w_arr.push_back(w);
    }
    vector<HTNode> ht(2*n-1);
    CreateHT(c_arr,w_arr,ht);
    vector<HTCode> hcd(n);
    CreateHCode(ht,hcd);
    ifstream ifs("in.txt",ios::in);
    ofstream ofs("out.txt",ios::out);
    while(ifs>>temp)
    {
        string ans=decode(ht,temp);
        ofs<<ans<<endl;
    }
    return 0;
}
/*
8
a:0.04 
b:0.22
c:0.06
d:0.18
e:0.21
f:0.12
g:0.08
h:0.09
*/