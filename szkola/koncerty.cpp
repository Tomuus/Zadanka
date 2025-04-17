#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> prefix(n + 1, 0);
    for (int i=1; i<=n;i++) 
    {
        char x;
        cin>>x;
        prefix[i] = prefix[i - 1] + (x - '0'); 
    }
    int q;
    cin>>q;
    while (q--) 
    {
        int l, r;
        cin>>l>>r;
        cout<<(prefix[r] - prefix[l - 1]) << '\n';
    }
    return 0;
}