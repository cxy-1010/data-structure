# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
using namespace std;
struct BTNode
{
    char data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode():lchild(nullptr),rchild(nullptr){}
    BTNode(char a):data(a),lchild(nullptr),rchild(nullptr){}
};
class BTree
{
public:
    BTNode* r;
    BTree(){r=nullptr;}
    void CreateBTree(string str)
    {
        stack<BTNode*> st;
        BTNode* p;
        bool flag;
        int i=0;
        int len=str.length();
        while(i<len)
        {
            switch(str[i])
            {
                case '(':
                    st.push(p);
                    flag=true;
                    break;
                case ')':
                    st.pop();
                    break;
                case ',':
                    flag=false;
                    break;
                default:
                {
                    p=new BTNode(str[i]);
                    if(r==nullptr) {r=p;}
                    else
                    {
                        if(!st.empty())
                        {
                            if(flag) st.top()->lchild=p;
                            else st.top()->rchild=p;
                        }
                    }
                }
            }
            i++;
        }
    }
    void DisBTree(){DisBTreel(r);}//因为这个根节点一般是private类型，所以这里要用两个函数
    void DisBTreel(BTNode* p)
    {
        if(p==nullptr) return; 
        cout<<p->data;
        if(p->lchild!=nullptr||p->rchild!=nullptr)
        {
            cout<<'(';
            DisBTreel(p->lchild);
            if(p->rchild!=nullptr) cout<<',';
            DisBTreel(p->rchild);
            cout<<')';
        }
    }
    BTNode* FindNode(char x){return FindNode1(r,x);}
    BTNode* FindNode1(BTNode* p,char x)
    {
        BTNode* temp;
        if(p==nullptr) return nullptr;
        else if(p->data==x) return p;
        else
        {
            temp=FindNode1(p->lchild,x);
            if(temp!=nullptr) return temp;
            temp=FindNode1(p->rchild,x);
            return temp;
        }
        return nullptr; 
    }
    int Heigh(){return Heigh1(r);}
    int Heigh1(BTNode* p)
    {
        if(p==nullptr) return 0;
        return max(Heigh1(p->lchild),Heigh1(p->rchild))+1;
    }
    void DestroyBTree(BTNode* p)
    {
        if(p==nullptr) return ;
        DestroyBTree(p->lchild);
        DestroyBTree(p->rchild);
        delete p;
    }
    ~BTree()
    {
        DestroyBTree(r);
        r=nullptr;
    }
    //先序遍历
    void Preorder1(BTree& bt) {Preorder11(bt.r);}
    void Preorder11(BTNode* p)
    {
        if(p!=nullptr)
        {
            cout<<p->data;
            Preorder11(p->lchild);
            Preorder11(p->rchild);
        }
    }
    //中序排列
    void Inorder1(BTree& bt) {Inorder11(bt.r);}
    void Inorder11(BTNode* p)
    {
        if(p!=nullptr)
        {
            Inorder11(p->lchild);
            cout<<p->data;
            Inorder11(p->rchild);
        }
    }
    //后序排列
    void Postorder1(BTree& bt) {Postorder11(bt.r);}
    void Postorder11(BTNode* p)
    {
        if(p!=nullptr)
        {
            Postorder11(p->lchild);
            Postorder11(p->rchild);
            cout<<p->data;
        }
    }
    
    //递归遍历（求节点数）
    //基于先序遍历的求解算法
    int NodeCount1(BTree& bt) {return Nodecount11(bt.r);}
    int NodeCount11(BTNode* p)
    {
        if(p==nullptr) return 0;
        int k=1;
        int m=NodeCount11(p->lchild);
        int n=NodeCount11(p->rchild);
        return k+m+n;
    }
    //基于中序遍历的求解算法
    int NodeCount2(BTree& bt) {return NodeCount22(bt.r);}
    int NodeCount22(BTNode* p)
    {
        if(p==nullptr) return 0;
        int m=NodeCount22(p->lchild);
        int k=1;
        int n=NodeCount22(p->rchild);
        retunr m+k+n; 
    }
    //基于后序遍历的求解算法
    int NodeCount3(BTree& bt) {return NodeCount33(bt.r);}
    int NodeCount33(BTNode* p)
    {
        if(p==nullptr) return 0;
        int m=NodeCount33(p->lchild);
        int n=NodeCount33(p->rchild);
        int k=1;
        retunr m+n+k; 
    }
    //从左到右输出二叉树节点值（前中后序都可以实现，这里只用先序实现）
    void DispLeaf1(BTree& bt) {DispLeaf11(bt.r);}
    void DispLeaf11(BTNode* p)
    {
        if(p==nullptr) return ;
        if(p->lchild==nullptr&&p->rchild==nullptr) {cout<<p->data<<' ';return ;}
        DispLeaf11(p->lchild);
        DispLeaf11(p->rchild);
    }
    //交换二叉树所有的左右子树（前中后序都可以实现，这里只用先序实现）
    void Swap1(BTree& bt) {Swap11(bt.r);}
    void Swap11(BTNode* p)
    {
        if(p==nullptr) return ;
        swap(p->lchild,p->rchild);
        Swap11(p->lchild);
        Swap11(p->rchild);
    }
    int level(BTree& bt,char x){return level1(bt,x,1);}
    int level1(BTNode* p,char x,int h)
    {
        if(p==nullptr) return nullptr;
        if(p->data==x) return h;
        int l;
        l=level1(p->lchild,x,h+1);
        if(l!=0) return l;
        return level1(p->rchild,x,h+1);
    }
    void Trans(string sb,BTree& bt) {Trans1(sb,0,bt.r);}
    void Trans1(string sb,int i,BTNode*& p)
    {
        if(i<sb.length())
        {
            if(sb[i]!='#')
            {
                p=new BTNode(sb[i]);
                Trans1(sb,2*i+1,p->lchild);
                Trans1(sb,2*i+2,p->rchild);
            }
            else p=nullptr;
        }
        else b=nullptr;
    }
    int KCount(BTree& bt,int k)
    {
        int count=0;
        KCount1(bt.r,1,k,count);
        return count;
    }
    void KCount1(BTNode* p,int h,int k,int& count)
    {
        if(p==nullptr) return ;
        if(h==k) count++;
        else
        {
            KCount1(p->lchild,h+1,k,count);
            KCount1(p->rchild,h+1,k,count);
        }
    }
    void Ancestor1(BTree& bt,char x,vector<char>& res)
    {
        Ancestor11(bt.r,x,res);
        reverse(ans.begin(),ans.end());
    }
    void Ancestor11(BTNode* p,char x,vector<char>& res)
    {
        if(p==nullptr) return false;
        if(p->lchild==nullptr&&p->rchild->data==x) 
        {
            res.push_back(p->data);
            return true;
        }
        if(p->lchild->data==x&&p->rchild==nullptr)
        {
            res.push_back(p->data);
            return true;
        }
        if(Ancestor11(p->lchild,x,res)||Ancestor11(p->rchild,x,res))
        {
            res.push_back(p->data);
            return true;
        }
        return false;
    }
    void Ancestor2(BTree& bt,char x,vector<char>& res)
    {
        vector<char> path;
        Ancestor22(bt.r,x,path,res);
    }
    void Ancestor22(BTNode* p,char x,vector<char> path,vector<char>& res)
    {
        if(p==nullptr) return ;
        path.push_back(p->data);
        if(p->data==x)
        {
            path.pop_back();
            res=path;
            return ;
        }
        Ancestor22(p->lchild,x,path,res);
        Ancestor22(p->rchild,x,path,res);
    }
    void Ancestor3(BTree& bt,char x,vector<char>& res)
    {
        vector<char> path;
        Ancestor31(bt.r,x,path,res);
    }
    bool Ancestor31(BTNode* p,char x,vector<char> path,vector<char>& res)
    {
        if(p==nullptr) return false;
        path.push_back(p->data);
        if(p->data==x)
        {
            path.pop_back();
            res=path;
            return true;
        }
        if(Ancestor31(p->lchild,x,path,res))
            return true;
        else
            return Ancestor31(p->rchild,x,path,res);
    }
};
//遍历的非递归算法
void PreOrder2(BTree& bt)
{
    if(bt.r==nullptr) return ;
    stack<BTNode*> st;
    st.push(bt.r);
    BTNode* p;
    while(!st.empty())
    {
        p=st.top();st.pop();
        cout<<p->data<<" ";
        if(p->lchild!=nullptr) 
            st.push(p->lchild);
        if(p->rchild!=nullptr)
            st.push(p->rchild);
    }
}
struct SNode
{
    BTNode* p;
    bool flag;
    SNode(){}
    SNode(BTNode* p,bool flag1)
    {
        this->p=p;
        this->flag=flag1;
    }
};
void push(stack<SNode*>& st,BTNode* p)
{
    if(p->lchild==nullptr&&p->rchild==nullptr)
        {st.push(SNode(p,true));}
    else 
        st.push(SNode(p,false);)
}

int main()
{
    return 0;
}




/*
class BTree {
private:
    // 前序遍历递归判断
    bool check(const BTNode* p1, const BTNode* p2) {
        if (p1 == nullptr && p2 == nullptr) return true;  // 两个都为空，相同
        if (p1 == nullptr || p2 == nullptr) return false; // 一个空一个不空，不同
        if (p1->data != p2->data) return false;           // 根节点值不同
        
        // 递归检查左子树和右子树（前序思维：根 -> 左 -> 右）
        return check(p1->lchild, p2->lchild) && check(p1->rchild, p2->rchild);
    }

public:
    bool is_equal(const BTree& bt) { // 顺便改成常引用传参，避免拷贝整棵树
        return check(this->r, bt.r);
    }
*/
/*
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
          另一种就是说明这里有相应的节点,返回给上层进行处理
          
        BTNode* left=get_LCA(p->lchild,target_1,target_2);
        BTNode* right=get_LCA(p->rchild,target_1,target_2);
        if(left!=nullptr&&right!=nullptr) {return p;}
        //如果两个都不为空，那么就只有一种可能,两个要找到的节点分别在两个子树上
        if(left==nullptr&&right!=nullptr) return right; 
        if(left!=nullptr&&right==nullptr) return left;
        /*如果只有一个为空，有两种情况：
          1.找到了LCA节点了，返回答案；
          2.没有找到，只是传递信息，说明有
        return nullptr;
    }
    BTNode* get_LCA1(int target_1,int target_2)
    {
        if(!find_target(this->r,target_1)||!find_target(this->r,target_2)) return nullptr;
        return get_LCA(this->r,target_1,target_2);
    }
};
*/