#include <ios>
#include <iostream>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,m,i,tmp,j,q,x1,y1,x2,y2;
    cin>>n>>m;
    long long sumy[n+1][m+1];
    for(i=1;i<=n;i++)
    {
        sumy[i][0]=0;
        for(j=1;j<=m;j++)
        {
            cin>>sumy[i][j];
            sumy[i][j]+=sumy[i][j-1];
        }
    }
    for(j=1;j<=m;j++)
    {
        sumy[0][j]=0;
        for(i=1;i<=n;i++)
        {
            sumy[i][j]+=sumy[i-1][j];
        }
    }
    sumy[0][0]=0;
    //for(i=0;i<=n;i++) {cout<<"\n"; for(j=0;j<=m;j++) cout<<sumy[i][j];}
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<sumy[x2][y2]-sumy[x1-1][y2]-sumy[x2][y1-1]+sumy[x1-1][y1-1]<<endl; //autystyczne linujki tomusia na randomowe dodawanie
    }
}
