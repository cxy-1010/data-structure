# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <deque>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    string line;
    vector<deque<string>> a(n);
    for(int i=0;i<n;i++)
    {
        getline(cin,line);
        istringstream iss(line);
        string temp;
        while(iss>>temp)
            a[i].push_back(temp);
    }
    getline(cin,line);
    string goal,goalindex,name;
    vector<string> goallines;
    while(getline(cin,line))
    {
        goallines.push_back(line);
    }
    cout<<"DEPARTS"<<endl;
    int linesize=goallines.size();
    for(int i=0;i<linesize;i++)
    {
        istringstream iss(goallines[i]);
        iss>>goal;
        if(goal=="LEAVES")
        {
            iss>>goalindex;
            int index=stoi(goalindex)-1;
            if(index >= 0 && index < n && !a[index].empty()) 
            {
                cout << a[index].front() << endl;
                a[index].pop_front();            
            }
        }
        if(goal=="ENTERS")
        {
            iss>>name;
            iss>>goalindex;
            int index=stoi(goalindex)-1;
            if(index >= 0 && index < n) a[index].push_back(name);
        }
    }
    cout<<endl;
    cout<<"FINAL CONTENTS"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"queue "<<i+1<<':';
        int size=a[i].size();
        for(int j=0;j<size;j++)
            cout<<' '<<a[i][j];
        cout<<endl;
    }
}