#include <iostream>

using namespace std;

typedef long long ll;

int tab[1000007];

bool check (int goal)
{
        int prev = -2000000;
        for (auto i : tab)
        {
                if (prev > i-goal) return false;
                prev = i-goal;
        }
        return true;
}

int bins (ll p, ll l)
{
        ll m=(p+l)/2;
        if(p>l) return m;
        if (check(m)) l = m;
        else p = m;
        return bins(p, l);
}

int main()
{
        int n;
        cin>>n;
        for (int i=0; i<n; i++) cin>>tab[i];
        int ans = bins(-1e5-7, 1e5+7);
        cout<<ans;
}
