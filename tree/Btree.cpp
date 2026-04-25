# include <iostream>
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
};
int main()
{
    return 0;
}