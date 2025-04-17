#include <iostream>
#include <string>

using namespace std;

int tab[7];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]=='a') cout<<4;
        else if(n[i]=='e') cout<<3;
        else if(n[i]=='i') cout<<1;
        else if(n[i]=='o') cout<<0;
        else if(n[i]=='s') cout<<5;
        else cout<<n[i];
    }
}