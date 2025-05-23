#include<iostream>
#include <map>

using namespace::std;

map <long long, long long> tab;

int main()
{
    //cout<<'a';
    int n, i=0,konto,pieniadz;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>konto>>pieniadz;
        if(tab[konto]+pieniadz<0) cout<<"NIE";
        else
        {
            cout<<tab[konto]+pieniadz;
            tab[konto]+=pieniadz;
        }
        cout<<endl;
    }
    return 0;
}
