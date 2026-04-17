# include <iostream>
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
void count(vector<int>& len,vector<Box> path)
{
    int size=path.size();
    len.push_back(size);
}
void find_path(vector<vector<int>>& a,vector<Box> path,int begin_i,int begin_j,int goal_i,int goal_j,vector<int>& len)
{
    Box now=Box(begin_i,begin_j,-1);
    path.push_back(now);
    int i,j,next_i,next_j,di;
    int size=path.size();
    i=path[size-1].i;
    j=path[size-1].j;
    di=path[size-1].di;
    if(i==goal_i&&j==goal_j)
    {
        count(len,path);
    }
    else
    {
        while(di<3)
        {
            di++;
            next_i=i+dx[di];
            next_j=j+dy[di];
            if(next_i>=0&&next_i<=goal_i&&next_j>=0&&next_j<=goal_j&&a[next_i][next_j]==0)
            {
                a[next_i][next_j]=-1;
                find_path(a,path,next_i,next_j,goal_i,goal_j,len);
                a[next_i][next_j]=0;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> in(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) 
            {cin>>in[i][j];}
    }
    vector<int> len;
    vector<Box> path;
    in[0][0]=-1;//这里不处理会出现多运行好多次因为这个默认是一开始就
    find_path(in,path,0,0,n-1,m-1,len);
    int max=0;
    int size=len.size();
    for(int i=0;i<size;i++)
    {
        if(max<len[i]) max=len[i];
    }
    cout<<max<<endl;
    return 0;
}
/*
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
0 1 1 1 0
0 0 0 0 0
*/