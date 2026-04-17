# include <iostream>
# include <string>
using namespace std;
# define Max_Size 1005
template<class T>
class Stack
{
public: 
    T* data;
    int rear;
    Stack() {data=new T[Max_Size];rear=-1;}
    ~Stack()
    {
        delete[] data;
        rear=0;
    }
    bool is_empty(){return rear==-1;}
    bool push(T e)
    {
        if(rear==Max_Size) return false;
        rear++;
        data[rear]=e;
        return true;
    }
    bool pop(T& e)
    {
        if(is_empty()) return false;
        e=data[rear];
        rear--;
        return true;
    }
    bool top(T& e)
    {
        if(is_empty()) return false;
        e=data[rear];
        return true;
    }
};
int my_rank(char a)
{
    if(a=='(') return 1;
    if(a=='[') return 2;
    if(a=='{') return 3;
    return 0;
}
int main()
{
    string s;
    cin>>s;
    int len=s.length();
    int max_ans=0,ans=0;
    Stack<char> my_stack;
    char temp;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{') {my_stack.push(s[i]);ans+=my_rank(s[i]);}
        else if(s[i]==')'||s[i]==']'||s[i]=='}')
        {
            if(my_stack.is_empty()) {cout<<-999<<endl; return 0;}
            if(s[i]==')')
            {
                my_stack.top(temp);
                if(temp!='(') {cout<<-999<<endl; return 0;}
                else {my_stack.pop(temp);}
            }
            if(s[i]==']')
            {
                my_stack.top(temp);
                if(temp!='[') {cout<<-999<<endl; return 0;}
                else {my_stack.pop(temp);}
            }
            if(s[i]=='}')
            {
                my_stack.top(temp);
                if(temp!='{') {cout<<-999<<endl; return 0;}
                else {my_stack.pop(temp);}
            }
        }
        if(my_stack.is_empty())
        {
            if(ans>max_ans) max_ans=ans;
            ans=0;
        }
    }
    if(s=="") cout<<0<<endl;
    if(my_stack.is_empty()) {cout<<-999<<endl;return 0;}
    icout<<max_ans<<endl;
    return 0;
}
