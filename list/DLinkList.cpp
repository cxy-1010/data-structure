# include <iostream>
using namespace std;
template<class T> 
struct DLinkNode
{
    T data;
    DLinkNode<T>* next;
    DLinkNode<T>* prior;
    DLinkNode():next(nullptr),prior(nullptr){}
    DLinkNode(T d):data(a),next(nullptr),prior(nullptr){}
};
template<class T>
class DLinkList
{
public:
    DLinkNode<T>* head;

};
int main()
{
    return 0;
}