# include <iostream>
# include <string>
using namespace std;
const int MAXV=100;
const int INF=0x3f3f3f3f;
class MatGraph
{
public:
    int edges[MAXV][MAXV];
    int n,e;//顶点数和边数
    string vexs[MAXV];//一一映射，存放节点的真正名字
    void createMatGraph(int arr[][MAXV],int n,int e)
    {
        this->n=n;this->e=e;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {edges[i][j]=arr[i][j];}
        }
    }
    vois DispMatGraph()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(this->edges[i][j]==INF) cout<<"∞"<<' ';
                else cout<<this->edges[i][j]<<' ';
            }
            cout<<endl;
        }
    }
};
int main()
{
    
    return 0;
}