# include <iostream>
# include <string>
using namespace std;
const int MAXN=100;
const int INF=0x3f3f3f3f;
struct ArcNode//arc有方向的边
{
    int adjvex;//adjacent邻接 vertex顶点
    int weight;
    ArcNode* nextarc;
};
struct HNode
{
    string info;//顶点信息
    ArcNode* firstarc;    
};
class AdjGraph
{
public:
    HNode adjlist[MAXN];
    int n,e;
    AdjGraph()
    {
        for(int i=0;i<MAXN;i++)
          {adjlist[i].firstarc=nullptr;}
    }
    ~AdjGraph()
    {
        ArcNode* p,* temp;
        for(int i=0;i<MAXN;i++)
        {
            p=adjlist[i].firstarc;
            while(p!=nullptr)
            {
                temp=p->nextarc;
                delete p;
                p=temp;
            }

        }
    }
    void CreateAdjGraph(int arr[][MAXN],int n,int e)
    {
        ArcNode* s;
        this->n=n;this->e=e;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]!=0&&arr[i][j]!=INF)
                {
                    s=new ArcNode();
                    s->adjvex=j;
                    s->weight=arr[i][j];
                    s->nextarc=adjlist[i].firstarc;//不带头节点的头插法
                    adjlist[i].firstarc=s;
                }
            }
        }
    }
    void DispAdjGraph()
    {
        ArcNode* p;
        for(int i=0;i<n;i++)
        {
            cout<<"["<<i<<']';
            p=adjlist[i].firstarc;
            while(p!=nullptr)
            {
                cout<<"->";
                cout<<'('<<p->adjvex<<','<<p->weight<<')';
                p=p->nextarc;
            }
            cout<<endl;
        }
    }
};
int main() {
    int n = 4; // 4个顶点 (0, 1, 2, 3)
    int e = 4; // 4条边

    // 1. 初始化一个邻接矩阵
    int matrix[MAXN][MAXN];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) matrix[i][j] = 0; // 自己到自己距离为0
            else matrix[i][j] = INF;     // 默认无边
        }
    }

    // 2. 添加具体的边和权重
    matrix[0][1] = 5;  // 0 -> 1 权重 5
    matrix[0][2] = 8;  // 0 -> 2 权重 8
    matrix[1][3] = 3;  // 1 -> 3 权重 3
    matrix[2][3] = 7;  // 2 -> 3 权重 7

    // 3. 创建图对象并转换
    AdjGraph g;
    g.CreateAdjGraph(matrix, n, e);

    // 4. 打印邻接表
    g.DispAdjGraph();

    return 0;
}