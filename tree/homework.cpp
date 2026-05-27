# include <iostream>
# include <vector>
# include <queue>
using namespace std;
struct BTNode
{
    char data;
    char left_data;
    char right_data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode()
    {
        lchild=nullptr;
        rchild=nullptr;
    }
    BTNode(char d,char l,char r)
    {
        data=d;
        left_data=l;
        right_data=r;
        lchild=nullptr;
        rchild=nullptr;
    }
};
class BTree
{
public:
    BTNode* r;
    void display1(BTNode* p)
    {
        if(p==nullptr) return ;
        cout<<p->data;
        if(p->lchild!=nullptr||p->rchild!=nullptr)
        {
            cout<<'(';
            display1(p->lchild);
            if(p->rchild!=nullptr) cout<<',';
            display1(p->rchild);
            cout<<')';
        }
    }
    void display(){display1(this->r);}
    int find_target1(char t,BTNode* p,int index)
    {
        if(p==nullptr) return -1;
        if(p->data==t) return index;
        int l=find_target1(t,p->lchild,index+1);
        int r=find_target1(t,p->rchild,index+1);
        if(l==-1||r==-1) return max(l,r);
        return min(l,r);
    }
    int find_target(char target){int index=1;return find_target1(target,this->r,index);}
    int find_target2(char target)
    {
        queue<BTNode*> q;
        q.push(this->r);
        int index=1;
        BTNode* p;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                p=q.front();q.pop();
                if(p->data==target) return index;
                if(p->lchild!=nullptr) q.push(p->lchild);
                if(p->rchild!=nullptr) q.push(p->rchild);
            }
            index++;
        }
        return -1;
    }
    void show(BTNode* p)
    {
        if(p==nullptr) return;
        cout<<p->data<<' ';
        show(p->lchild);
        show(p->rchild);
    }
    void display_son1(BTNode* p,char t)
    {
        if(p==nullptr) return ;
        if(p->data==t)
        {
            show(p->lchild);
            show(p->rchild);
        }
        display_son1(p->lchild,t);
        display_son1(p->rchild,t);
    }
    void display_son(char target){display_son1(this->r,target);}
};
int main()
{
    int n;
    cin>>n;
    char d,r,l;
    BTNode* p;
    vector<BTNode*> in;
    for(int i=0;i<n;i++)
    {
        cin>>d>>l>>r;
        in.emplace_back(new BTNode(d,l,r));
    }
    for(int i=0;i<n;i++)
    {
        char left=in[i]->left_data;
        char right=in[i]->right_data;
        if(left!='#')
        {
            for(int j=i;j<n;j++)
            {
               if(in[j]->data==left)
               {
                    in[i]->lchild=in[j];
                    break;
               } 
            }
        }
        if(right!='#')
        {
            for(int j=i;j<n;j++)
            {
               if(in[j]->data==right)
               {
                    in[i]->rchild=in[j];
                    break;
               } 
            }
        }
    }
    BTree bt;
    bt.r=in[0];
    char target;
    cin>>target;
    bt.display_son(target);
    return 0;
}
/*
7
A B C
B D E
C # F
D # #
E # #
F G #
G # #
*/