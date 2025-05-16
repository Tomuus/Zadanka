#include <iostream>
#include <map>

using namespace std;

map <int,int> omap;
map <int,int> last;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int i,n,tmp,mx=0,mn=2000000;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        if (omap.find(tmp) == omap.end()) {
            omap[tmp]=i;
            //cout<<'n';
            last[tmp]=i;
        }
        else
        {
            //cout<<'s';
            mx=max(mx,i-omap[tmp]);
            mn=min(mn,i-last[tmp]);
        }
        last[tmp]=i;
    }
    if(mn==2000000) cout<<0<<' ';
    else cout<<mn<<' ';
    cout<<mx;
}
