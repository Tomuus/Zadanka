#include <algorithm>
#include <iostream>
#include <unordered_map>

typedef long long ll;

using namespace std;

unordered_map<ll, int> freq;

int tab[4007];

int main()
{
        ll n, ans = 0;
        cin>>n;
        fill(tab, tab+n, 0);
        for (int i=0; i<n; i++)
        {
                cin>>tab[i];
                freq[tab[i]]++;
        }
        for(int i=0; i<n; i++)
        {
                for (int j=0; j<n; j++) {
                        if (i == j)continue;
                        int curr = 0-tab[i]-tab[j];
                        if (curr == tab[i] or curr == tab[j]) ans--; 
                        if (curr == tab[i] and curr == tab[j]) ans--;
                        if(freq.count(curr)>0) ans+=freq[curr];
                        //if (freq[curr]) cout<<curr<<'i'<<freq[curr]<<' ';
                }
        }
        cout<<ans/6;
}
