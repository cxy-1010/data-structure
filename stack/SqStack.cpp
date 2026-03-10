# include <iostream>
# include <string>
# define MaxSize 100
using namespace std;
template<class T>
class SqStack
{
private:
    T* data;
    int top;
public:
    SqStack()
    {
        data=new T[MaxSize];
        top=-1;
    }
    ~SqStack()
    {
        top=-1;
        delete[] data;
    }
    bool empty(){return top==-1;}
    bool push(T e)
    {
        if(top==MaxSize) return false;
        top++;
        data[top]=e;
        return true;
    }
    bool pop(T& e)
    {
        if(empty()) return false;
        e=data[top];
        top--;
        return true;
    }
    bool gettop(T& e)
    {
        if(empty()) return false;
        e=data[top];
        return true;
    }
};
bool isMatch(const string& a)
{
    SqStack<char> get;
    int len=a.length();
    char temp;
    for(int i=0;i<len;i++)
    {
        if(a[i]=='{'||a[i]=='('||a[i]=='[') get.push(a[i]);
        else
        {
            if(a[i]=='}')
            {
                if(get.empty()) return false;
                get.gettop(temp);
                if(temp!='{') return false;
                else get.pop(temp);
            }
            else if(a[i]==']')
            {
                if(get.empty()) return false;
                get.gettop(temp);
                if(temp!='[') return false;
                else get.pop(temp);
            }
            else if(a[i]==')')
            {
                if(get.empty()) return false;
                get.gettop(temp);
                if(temp!='(') return false;
                else get.pop(temp);
            }
        }
    }
    return true;
}
bool isPalind(const string& a)
{
    SqStack<char> s;
    int len=a.length();
    int i=0;
    while(i<len/2)
    {
        s.push(a[i]);
        i++;
    }
    if(len%2==1) i++;
    char temp;
    while(i<len)
    {
        s.pop(temp);
        if(a[i]!=temp) return false;
        i++;
    }
    return true;
}

//最小栈问题
template<class T>
class Minstack
{
private:
    T* data;
    T* mindata;
    int top;
    int mintop;
    bool minempty() {return mintop==-1;}
    bool minpush(const T& e)
    {
        mintop++;
        mindata[mintop]=e;
    }
    T minpop()
    {
        T e=mindata[mintop];
        mintop--;
        return e;
    }
    T mingettop()
    {
        T e=mindata[mintop];
        return e;
    }
public:
    Minstack()
    {
        data=new T[MaxSize];mindata=new T[MaxSize];
        top=-1;mintop=-1;
    }
    ~Minstack()
    {
        delete[] data;delete[] mindata;
        top=-1;mintop=-1;
    }
    bool empty(){return top==-1;}
    bool push(const T& e)
    {
        if(top==Maxsize-1) return false;
        top++;
        data[top]=e;
        if(minempty()||mingettop()>=e)
           {minpush(e);}
        return true;
    }
    bool pop(T& e)
    {
        if(empty()) return false;
        e=data[top];
        top--;
        if(e==mingettop()) {minpop();}
        return true;
    }
    bool gettop(T& e)
    {
        if(empty()) return false;
        e=data[top];
        return true;
    }
    bool getmin(T& e)
    {
        if(minempty()) return false;
        e=mindata[mintop];
        return true;
    }
};
int main()
{
    string test1="[{()}]";
    cout<<(boolalpha)<<isMatch(test1)<<endl;
    string test2="123454321";
    cout<<boolalpha<<isPalind(test2)<<endl;
    return 0;
}