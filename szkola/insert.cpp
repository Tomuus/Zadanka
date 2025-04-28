#include <iostream>

using namespace std;

int main()
{
    long long n,i,j,curr;
    cin>>n;
    int tab[n+1];
    tab[0]=0;
    for(i=1;i<=n;i++) cin>>tab[i];
    for(i=2;i<=n;i++)
    {
        curr=tab[i];
        for(j=i-1;j>=0;j--)
        {
            if(curr<tab[j]) tab[j+1]=tab[j];
            else {tab[j+1]=curr; break;}
        }
        for(j=1;j<=n;j++) cout<<tab[j]<<' ';
        cout<<endl;
    }
    return 0;
}
