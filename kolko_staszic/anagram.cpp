#include <iostream>
#include <string>

using namespace std;

int lit[30][4]={};

int main()
{
    //cout<<'s';
    string a,b;
    int j,ans=0;
    //cout<<'x';
    cin>>a;
    cin>>b;
    //cout<<'a';
    for(auto i: a) lit[int(i)-96][0]++;
    for(auto i: b)
    {
        lit[int(i)-96][1]++;
    }
    for(j=0;j<30;j++)
    {
        lit[j][2]=min(lit[j][0],lit[j][1]);
        lit[j][3]=lit[j][2];
        ans+=lit[j][3];
    }
    if(ans==0)
    {
        cout<<"BRAK\nBRAK";
        return 0;
    }
    cout<<ans<<endl;
    for(auto i : a)
    {
        if(lit[int(i)-96][2]>0)
        {
            cout<<i;
            lit[int(i)-96][2]--;
        }
    }
    cout<<endl<<ans<<endl;
    for(auto i : b)
    {
        if(lit[int(i)-96][3]>0)
        {
            cout<<i;
            lit[int(i)-96][3]--;
        }
    }
}
