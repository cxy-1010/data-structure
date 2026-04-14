# include <iostream>
# include <string>
# include <stack>
using namespace std;
inline bool is_right(char c){return c=='(';}
bool is_logal(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/') return false;
    else return true;
}
int my_rank(char c)
{
    if(c=='(') return 0;
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
}
int main()
{
    string s1;
    cin>>s1;
    bool is_s1=true;
    int len1=s1.length();
    string s1_process="";
    stack<char> stack_1;
    for(int i = 0; i < len1; i++) 
    {
        char c = s1[i];
        if(isdigit(c))
        {
            int temp=i+1;
            s1_process += c;
            while(temp<len1)
            {
                if(isdigit(s1[temp])){s1_process+=s1[temp];}
                else break;
                temp++;
            }
            i=temp-1;
            s1_process += "#";
        }
        else if(isalpha(c)) 
        {
            s1_process += c;
            s1_process += "#";
        }
        else if(c == '('){stack_1.push(c);}
        else if(c == ')') 
        {
            while(!stack_1.empty() && stack_1.top() != '(') 
            {
                s1_process += stack_1.top();
                stack_1.pop();
            }
            if(stack_1.empty()) {is_s1=false;break;}
            stack_1.pop(); 
        }
        else 
        {
            if(i == 0 || (!isdigit(s1[i-1]) && !isalpha(s1[i-1]) && s1[i-1] != ')')) {is_s1=false;break;}
            while(!stack_1.empty() && my_rank(stack_1.top()) >= my_rank(c)) 
            {
                s1_process+=stack_1.top();
                stack_1.pop();
            }
            stack_1.push(c);
        }
    }
    while(!stack_1.empty()&&is_s1) 
    {
        if(stack_1.top() == '(') {is_s1=false;break;}
        s1_process+=stack_1.top();
        stack_1.pop();
    }
    cout<<is_s1<<endl;
    cout<<s1_process<<endl;
    return 0;
}