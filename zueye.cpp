# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;
struct BTNode
{
    int data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode():lchild(nullptr),rchild(nullptr){}
    BTNode(int d):data(d),lchild(nullptr),rchild(nullptr){}
};
bool equal(const BTNode* p1,const BTNode* p2)
{
    if(p1==nullptr&&p2==nullptr) return true;
    if(p1==nullptr&&p2!=nullptr) return false; 
    if(p1!=nullptr&&p2==nullptr) return false;
    return p1->data==p2->data; 
}
class BTree
{
public:
    BTNode* r;
    BTree(){r=nullptr;}
    void createBTree1(BTNode*& p,const vector<int>& in,size_t& index)
    {
        if(index>=in.size()) return ;//这里in.size()返回的是size_t
        if(in[index]==-1) {index++;return ;}
        BTNode* s=new BTNode(in[index]);
        index++;
        p=s;
        createBTree1(p->lchild,in,index);
        createBTree1(p->rchild,in,index);
    }   
    void createBTree(const vector<int>& in) {size_t index=0;createBTree1(r,in,index);}
    void show1(BTNode* p)
    {
        if(p==nullptr) return ;
        cout<<p->data;
        if(p->lchild!=nullptr||p->rchild!=nullptr)
        {
            cout<<"(";
            show1(p->lchild);
            if(p->rchild!=nullptr) cout<<',';
            show1(p->rchild);
            cout<<')';
        }
    }
    void show(){show1(r);}
    void get_ans1(BTNode* p)
    {
        if(p==nullptr) {cout<<','<<"#";return ;}
        cout<<','<<p->data;
        get_ans1(p->lchild);
        get_ans1(p->rchild);
    }
    void get_ans(){cout<<r->data;get_ans1(r->lchild);get_ans1(r->rchild);}
    //中序遍历
    void middle1(BTNode* p)
    {
        if(p==nullptr) return ;
        middle1(p->lchild);
        cout<<p->data<<' ';
        middle1(p->rchild);
    }
    void middle(){middle1(r);}
    //后序遍历
    void back1(BTNode* p)
    {
        if(p==nullptr) return ;
        back1(p->lchild);
        back1(p->rchild);
        cout<<p->data<<' ';
    }
    void back(){back1(this->r);}
    //层次遍历
    void level()
    {
        queue<BTNode*> q;
        q.push(this->r);
        BTNode* p;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                p=q.front();q.pop();
                if(p==nullptr) continue;
                cout<<p->data<<' ';
                if(p->lchild!=nullptr) q.push(p->lchild);
                if(p->rchild!=nullptr) q.push(p->rchild);
            }
        }
    }
    bool is_equal(BTree bt)
    {
        queue<BTNode*> q1;
        queue<BTNode*> q2;
        q1.push(this->r);
        q2.push(bt.r);
        BTNode* p1; 
        BTNode* p2; 
        while(!q1.empty()&&!q2.empty())
        {
            int n1=q1.size();
            int n2=q2.size();
            if(n1!=n2) return false;
            for(int i=0;i<n1;i++)
            {
                p1=q1.front();q1.pop();
                p2=q2.front();q2.pop();
                bool is=equal(p1,p2);
                if(!is) return false;
                if(p1!=nullptr) 
                {
                    q1.push(p1->lchild);q1.push(p1->rchild);
                    q2.push(p2->lchild);q2.push(p2->rchild);
                }
            }
        }
        return true;
    }
    int get_leaves1(BTNode* p)
    {
        if(p==nullptr) return 0;
        if(p->lchild==nullptr&&p->rchild==nullptr) return 1;
        return get_leaves1(p->lchild)+get_leaves1(p->rchild);
    }
    int get_leaves(){return get_leaves1(this->r);}
    int get_node1(BTNode* p)
    {
        if(p==nullptr) return 0;
        return get_node1(p->lchild)+get_node1(p->rchild)+1;
    }
    int get_node(){return get_node1(this->r);}
    // bool get_path1(BTNode* p,vector<int> path,vector<int>& ans,int target)
    // {
    //     if(p==nullptr) return false;
    //     path.push_back(p->data);
    //     if(p->data==target)
    //     {
    //         int n=path.size();
    //         for(int i=0;i<n;i++) {ans.push_back(path[i]);}
    //         return true;
    //     }
    //     bool left=get_path1(p->lchild,path,ans,target);
    //     if(left) return true;
    //     else return get_path1(p->rchild,path,ans,target);
    // }
    // bool get_path(vector<int>& ans,int target)
    // {
    //     vector<int> path;
    //     bool is=get_path1(this->r,path,ans,target);
    //     reverse(ans.begin(),ans.end());
    //     return is;
    // }
    bool find_target(BTNode* p,int target)
    {
        if(p==nullptr) return false;
        if(p->data==target) return true;
        return find_target(p->lchild,target)||find_target(p->rchild,target);
    }
    BTNode* get_LCA(BTNode* p,int target_1,int target_2)
    {   
        if(p==nullptr) return nullptr;
        if(p->data==target_1||p->data==target_2) return p;
        /*这一步有两种情况，一种是另一个节点在这个节点下方,那么这个节点就是LCA,
          另一种就是说明这里有相应的节点,返回给上层进行处理*/
        BTNode* left=get_LCA(p->lchild,target_1,target_2);
        BTNode* right=get_LCA(p->rchild,target_1,target_2);
        if(left!=nullptr&&right!=nullptr) {return p;}
        //如果两个都不为空，那么就只有一种可能,两个要找到的节点分别在两个子树上
        if(left==nullptr&&right!=nullptr) return right; 
        if(left!=nullptr&&right==nullptr) return left;
        /*如果只有一个为空，有两种情况：
          1.找到了LCA节点了，返回答案；
          2.没有找到，只是传递信息，说明有*/
        return nullptr;
    }
    BTNode* get_LCA1(int target_1,int target_2)
    {
        if(!find_target(this->r,target_1)||!find_target(this->r,target_2)) return nullptr;
        return get_LCA(this->r,target_1,target_2);
    }
};
int main()
{
    int val;
    int target_1,target_2;
    cin>>target_1>>target_2;
    vector<int> in;
    while(cin>>val) {in.push_back(val);}
    BTree bt;
    bt.createBTree(in);
    BTNode* lca=bt.get_LCA1(target_1,target_2);
    if(lca==nullptr) cout<<-1<<endl;
    else cout<<lca->data<<endl;
    return 0;   
}