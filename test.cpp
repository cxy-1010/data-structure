# include <iostream>
# include <string>
# include <iomanip>
using namespace std;
int main()
{
   string s;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        cout<<hex<<(int)s[i]<<' ';
    }
    return 0;
}