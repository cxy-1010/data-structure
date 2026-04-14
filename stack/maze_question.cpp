# include <iostream>
# include <stack>
# include <vector>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
struct Box
{
    int i;
    int j;
    int di;
    Box(){}
    Box(int i,int j,int di):i(i),j(j),di(di){}
};
void show(stack<Box> a)
{
    vector<Box>ans;
    Box temp;
    while(!a.empty())
    {
        temp=a.top();
        ans.push_back(temp);
        a.pop();
    }
    int size=ans.size();
    for(int i=size-1;i>=0;i--)
    {
        cout<<'['<<ans[i].i<<','<<ans[i].j<<']'<<endl;
    }
}
bool mypath(vector<vector<int>> in,int n,int begini,int beginj,int ei,int ej)
{
    stack<Box> s;
    Box begin(begini,beginj,-1);
    s.push(begin);
    Box temp;
    Box new_box
    bool find;
    int i,j,di;
    while(!s.empty())
    {
        temp=s.top();
        if(temp.i==ei&&temp.j==ej) 
        {
            show(s);
            return true;
        }
        di=temp.di;
        find=false;
        while(di<3&&!find)
        {
            di++;
            i=temp.i+dx[di];
            j=temp.j+dx[di];
            if(i>=0&&i<n&&j>=0&&j<n&&in[i][j]==0) find=true;
        }
        if(find)
        {
            s.top().di=di;
            new_box=Box(i,j,-1);
            s.push(new_box);
            in[i][j]=-1;
        }
        else
        {
            in[temp.i][temp.j]=0;
            s.pop();
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> in(n,vector<int>(n,0));
    for(int i;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>in[i][j];
    }
    int bi,bj,ei,ej;
    cin>>bi>>bj>>ei>>ej;
    return 0;
}