# include <iostream>
# include <fstream>
# include <vector>
using namespace std;
bool find(int goal,const vector<int> v)
{
    int len=v.size();
    for(int i=0;i<len;i++)
        {if(v[i]==goal) return true;}
    return false;
}
void put(int& count,int n,int col_count,vector<int>& row,vector<int>& diagonal1,vector<int>& diagonal2)
{
    if(n==col_count) {count++;return ;}
    int k=0;
    for(int i=0;i<n;i++)
    {
        bool is1=find(i,row);
        bool is2=find(i-col_count,diagonal1);
        bool is3=find(i+col_count,diagonal2);
        if(!is1&&!is2&&!is3)
        {
            k++;
            row.push_back(i);
            diagonal1.push_back(i-col_count);
            diagonal2.push_back(i+col_count);
            put(count,n,col_count+1,row,diagonal1,diagonal2);
            row.pop_back();
            diagonal1.pop_back();
            diagonal2.pop_back();
        }
    }
    if(k==0) {return ;}
}
int main()
{
    ifstream ifs("in.txt",ios::in);
    int n;
    ifs>>n;    
    return 0;
}