#include <iostream>

using namespace std;

int tab[7];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(i%7==0 and i%11==0) {cout<<"Wiwat!"<<endl; continue;}
        else if(i%7==0) cout<<"Hurra!"<<endl;
        else if(i%11==0) cout<<"Super!"<<endl;
        else cout<<i<<endl;
    }
}