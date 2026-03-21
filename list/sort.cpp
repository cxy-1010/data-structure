# include <iostream>
# include <fstream>
using namespace std;
template<class T> 
struct LinkNode
{
    T data;
    LinkNode<T>* next;
    LinkNode<T>* lnext;
    LinkNode():next(nullptr),lnext(nullptr){}
    LinkNode(T d):data(d),next(nullptr),lnext(nullptr){}
};
template<class T> 
class LinkList
{
public:
    LinkNode<T>* head;
    LinkList() {head=new LinkNode<T>();}
    ~LinkList()
    {
        LinkNode<T>* pre,* p;
        pre=head;p=pre->lnext;
        while(p!=nullptr)
        {
            delete pre;
            pre=p;p=p->lnext;
        }
        delete pre;
    }
};
LinkNode<int>* merge(LinkNode<int>* a,LinkNode<int>* b)
{
    LinkNode<int>* p;
    LinkNode<int>* head=p;
    while(a!=nullptr&&b!=nullptr)
    {
        if(a->data<=b->data)
        {
            p->next=a;
            p=a;
            a=a->next;
        }
        else
        {
            p->next=b;
            p=b;
            b=b->next;
        }
    }
    if(a!=nullptr) p->next=a;
    if(b!=nullptr) p->next=b;
    return head->next;
}
int main()
{
    ifstream ifs("in.txt",ios::in);
    int val,n=0;
    LinkList<int> a;
    LinkNode<int>* s;
    LinkNode<int>* p=a.head;
    while(ifs>>val)
    {
        s=new LinkNode<int>(val);
        p->lnext=s;
        p=s;
        n++;
    }
    ifs.close();
    int len=n;
    LinkNode<int>* pa,*pb;
    LinkNode<int>*temp;
    while(a.head->lnext->lnext!=nullptr)
    {
        p=a.head->lnext;
        while(p!=nullptr)
        {
            cout<<p->data<<' ';
            p=p->next;
        }
        cout<<endl;
        p=a.head;
        pa=a.head->lnext;
        pb=a.head->lnext->lnext;
        for(int i=0;i<len/2;i++)
        {
            temp=merge(pa,pb);
            p->lnext=temp;
            p=temp;
            temp->lnext=pb->lnext;
            pa=pb->lnext;
            if(pa!=nullptr) pb=pa->lnext;
            else break;
            if(pb==nullptr) break;
        }    
    }
    ofstream ofs("out.txt",ios::out);
    p=a.head->lnext;
    while(p!=nullptr)
    {
        ofs<<p->data<<' ';
        p=p->next;
    }
    return 0;
}
/*
// 1. 合并两个有序链表
LinkNode<int>* merge(LinkNode<int>* l1, LinkNode<int>* l2) {
    LinkNode<int> dummy;
    LinkNode<int>* tail = &dummy;
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1; l1 = l1->next;
        } else {
            tail->next = l2; l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// 2. 切断链表，返回切断点之后的头
LinkNode<int>* split(LinkNode<int>* head, int n) {
    for (int i = 1; head && i < n; i++) head = head->next;
    if (!head) return nullptr;
    LinkNode<int>* next = head->next;
    head->next = nullptr; // 断开
    return next;
}

// 3. 主排序逻辑（放入 main 或类方法）
void sortLinkList(LinkList<int>& list, int n) {
    if (n <= 1) return;

    LinkNode<int>* head = list.head->next; // 真正的第一个数据节点
    LinkNode<int> dummy;
    dummy.next = head;

    for (int h = 1; h < n; h <<= 1) { // 步长：1, 2, 4, 8...
        LinkNode<int>* prev = &dummy;
        LinkNode<int>* cur = dummy.next;

        while (cur) {
            LinkNode<int>* left = cur;
            LinkNode<int>* right = split(left, h); // 找到右半部分的头
            cur = split(right, h);                 // 找到下一对的头

            prev->next = merge(left, right);       // 合并
            while (prev->next) prev = prev->next;  // 移动 prev 到末尾
        }
    }
    list.head->next = dummy.next; // 更新原来的头结点指向
}*/