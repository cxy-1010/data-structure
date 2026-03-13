# include <iostream>
# include <string>
# include <stack>
using namespace std;
int m(char a)
{
    if(a=='(') return 0;
    if(a=='+'||a=='-') return 1;
    if(a=='*'||a=='/') return 2;
    return -1;
}
int main()
{
    string a;
    getline(cin,a);
    stack<char> s;
    int len=a.length();
    for(int i=0;i<len;i++)
    {
        if(isdigit(a[i])) cout<<a[i]<<' ';
        else if(a[i]=='(') s.push(a[i]);
        else if(a[i]==')')
        {
            while(!s.empty()&&s.top()!='(')
            {
                cout<<s.top()<<' ';
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty()&&m(s.top())>=m(a[i]))
            {
                cout<<s.top()<<' ';
                s.pop();
            }
            s.push(a[i]);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<' ';
        s.pop();
    }
    cout<<endl;
    return 0;
}