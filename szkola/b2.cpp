#include <iostream>

using namespace std;

int bins(int tab[],int s,int p,int l)
{
    int m=(p+l)/2;
    if(l<p) return -1;
    if(tab[m]==s) return m;
    if(tab[m]>s) return bins(tab,s,p,m-1);
    else return bins(tab,s,m+1,l);
}

int main()
{
    int i,n,m,tmp,ans;
    cin>>n;
    int tab[n];
    for(i=0;i<n;i++) cin>>tab[i];
    cin>>m;
    cout<<bins(tab,m,0,n);

}
