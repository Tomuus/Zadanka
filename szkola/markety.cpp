#include <iostream>
#include <algorithm>

using namespace std;

int tab[1000][1000];
int m;

int comp(int a, int b)
{
    int cena=0;
    for(int i=0;i<m;i++)
    {
        cena+=min(tab[a][i],tab[b][i]);
    }
    return cena;
}

int main()
{
    int i,n,j,mn=99999999;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>tab[i][j];
        }
        for(j=0;j<i;j++)
        {
            mn=min(mn,comp(j,i));
        }
    }
    cout<<mn;
}