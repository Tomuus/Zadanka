#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,i,x,y;
    string a;
    cin>>n>>a;
    int tab[a.size()+1][2];
    tab[0][0]=0;
    tab[0][1]=0;
    for(i=1;i<=a.size();i++)
    {
        tab[i][0]=tab[i-1][0];
        tab[i][1]=tab[i-1][1];
        if(a[i-1]=='z') tab[i][0]++;
        else tab[i][1]++;
        //cout<<tab[i][0]<<'a'<<tab[i][1]<<' ';
    }
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        if(tab[y][0]-tab[x-1][0]==tab[y][1]-tab[x-1][1]) {cout<<"labor omnia vincit"<<endl; continue;}
        if(tab[y][0]-tab[x-1][0]>tab[y][1]-tab[x-1][1]) cout<<'z';
        else cout<<'n';
        cout<<' '<<abs(tab[y][0]-tab[x-1][0]-(tab[y][1]-tab[x-1][1]))<<endl;
    }
}
