# include <iostream>
using namespace std;
struct BthNode
{
    char data;
    BthNode* lchild;
    BthNode* rchild;
    int ltag,rtag;
    BthNode() {lchild=rchild=nullptr;}
    BthNode(char d)
    {
        data=d;
        lchild=rchild=nullptr;
    }
};
class ThreadTree
{
private:
    BthNode* r;
    BthNode* root;
    BthNode* pre;
public:
    ThreadTree()
    {
        r=nullptr;
        root=nullptr;
    }
    ~ThreadTree()
    {
        if(r!=nullptr) DestroyBTree1(r);
        if(root!=nullptr) delete root;
    }
    void DestroyBTree1(BthNode* p)
    {
        if(p->ltag==0) DestroyBTree1(p->lchild);
        if(p->rtag==0) DestroyBTree1(p->rchild);
        delete p;
    }
    void CreateBTree(string s);
    void DispBTree();
    void CreateThread();
    void Thread(BthNode*& p);
    void ThInOrder();
};
void ThreadTree::CreateThread()
{
    this->root=new BthNode();
    root->ltag=0;root->rtag=1;
    root->rchild=root;
    if(r==nullptr)
    {
        root->lchild=root;
        root->rchild=nullptr;
    }
    else
    {
        root->lchild=r;
        pre=root;
        Thread(r);
        pre->rchild=root;
        pre->rtag=1;
        root->rchild=pre;//这一步是干什么的
    }
}
void ThreadTree::Thread(BthNode*& p)
{
    if(p==nullptr) return ;
    Thread(p->lchild);
    if(p->lchild==nullptr)
    {
        p->lchild=pre;
        p->ltag=1;
    }
    else p->ltag=0;
    if(pre->rchild==nullptr)
    {
        pre->rchild=p;
        pre->rtag=1;
    }
    else p->rtag=0;
    pre=p;
    Thread(p->rchild);
}
int main()
{
    return 0;
}