#include <iostream>

using namespace::std;

bool tab[1007][1007];
int dp[1007][1007];
int n,m,mx=-1;//,mi=-1,mj=-1;

void sprawdz(int i)
{
    int j=0;
    for(j=0;j<m;j++)
    {
        if(tab[i][j]) dp[i][j]=1;
        if(i<n-1)
        {
            if(j==0 or j>=m-1 or !tab[i][j]) continue;
            else dp [i][j] += min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
        }
        if(dp[i][j]>mx) mx=dp[i][j];
    }
    return;
}

int main()
{
    long long i=0,j=0;
    char tmp;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //cout<<'@';
            cin>>tmp;
            tab[i][j]=(tmp=='X');
        }
    }
    //cout<<'v';
    for(i=n-1;i>=0;i--)
    {
        //cout<<'#';
        sprawdz(i);
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) cout<<dp[i][j]<<' ';
        cout<<endl;
    }*/
    cout<<mx<<' ';//<<mi<<' '<<mj;
}
