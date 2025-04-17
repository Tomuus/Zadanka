#include <iostream>
#include <string>

using namespace std;

int tab[7];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    int sum=0,l=0;
    cin>>n;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]!='x') sum+=int(n[i])-48;
    }
    //cout<<sum<<endl;
    while(sum%9!=0) {sum++; l++;}
    if(l==0) cout<<9;
    else cout<<l;
}