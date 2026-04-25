# include <iostream>
# include <algorithm>
# include <vector>
using namespace std; 
//双亲储存结构
struct PNode
{
    char data;
    int parent;
    PNode(char data,int parent)
    {
        this->data=data;
        this->parent=parent;
    }
}; 
int Level(vector<PNode> t,int i)
{
    if(i<0|| i>=t.size()) return 0;
    int count=1;
    while(t[i].parent!=-1)
    {
        count++;
        i=t[i].parent;
    }
    return count;
}
//孩子链式储存结构
struct SonNode
{
    char data;
    vector<SonNode*> sons;
    SonNode(){}
    SonNode(char d):data(d) {}
};
int height1(SonNode* p)
{
    if(p==nullptr) return 0;
    int maxsh=0;
    int size=p->sons.size();
    for(int i=0;i<size;i++)
    {
        int sh=height1(p->sons[i]);//采用循环调用
        maxsh=max(sh,maxsh);
    }
    return maxsh;
}
//长子兄弟链式储存结构
struct EBNode
{
    char data;
    EBNode* brother;
    EBNode* eson;
    EBNode():brother(nullptr),eson(nullptr){}
    EBNode(char d):data(d),brother(nullptr),eson(nullptr){}
};
int height(EBNode* p)
{
    if(p==nullptr) return 0;
    EBNode* temp;
    int maxsh=0;
    while(p!=nullptr)
    {
        temp=p->brother;
        int sh=height(p->eson);
        p=temp;
        maxsh=max(sh,maxsh);
    }
    return maxsh+1;
}
int main()
{
    return 0;
}