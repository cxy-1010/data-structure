# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# include <cmath>
using namespace std;
int getmax(int n)
{
    int max_i=-1;
    while(n%2==0)
    {
        max_i=2;
        n/=2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0)
        {
            max_i=i;
            n/=i;
        }
    }
    if(n>2) max_i=n;
    return max_i;
}
int main()
{
    ifstream ifs("in.txt", ios::in);
    if (!ifs.is_open()) return 0;

    int n;
    if (!(ifs >> n)) return 0;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int elem;
        if (ifs >> elem) {
            a.push_back(elem);
        }
    }
    int size=a.size(),ans=-1,max=0;
    for(int i=0;i<size;i++)
    {
        int temp=getmax(a[i]);
        if(temp>max) {max=temp;ans=a[i];}
    }
    cout<<ans<<endl;
    return 0;
}