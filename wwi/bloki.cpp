#include <iostream>
#include <stack>

using namespace std;

typedef long long unsigned ll;

int main()
{
        int n, ans = 0;
        stack <ll> bloki;
        cin>>n;
        for (ll a, b, i=0; i<n; i++) {
                cin>>b>>a; //szerokosc nie robi zadnej rozniy
                //cout<<'p';
                if (bloki.size() == 0) {bloki.push(a); continue;}
                while (bloki.size() != 0 and a < bloki.top()) {
                       //cout<<'z'<<bloki.top();
                        bloki.pop(); 
                        ans++;
                } 
                if (bloki.size() == 0) {bloki.push(a); continue;}
                if (a > bloki.top()) bloki.push(a);
                if (a == bloki.top()) continue;
        }
        cout<<ans+bloki.size();
}
