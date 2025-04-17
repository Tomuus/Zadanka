#include <iostream>

using namespace std;

int tab[7];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,i,tmp=1;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        tmp*=i;
    }
    cout<<tmp;
}