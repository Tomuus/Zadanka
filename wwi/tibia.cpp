#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <long long, unordered_map <long long, int>> tab;
unordered_map<long long, unordered_map<long long, int>> dp;

int main ()
{
        int n, m, s;
        cin>>n>>m>>s;
        for(int i=0; i<s; i++)
        {
                int x, y, p;
                cin>>x>>y>>p;
                tab[x][y]=p;
        }
        for (int i=1; i<=m; i++)
        {
                for (int j=1; j<=n; j++)
                {
                        dp[j][i] = max(dp[j][i-1],dp[j-1][i]);
                        dp[j][i] += tab[j][i];
                }
        }
        cout<<dp[n][m];
}
