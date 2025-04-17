#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i,n,w=0;
    cin>>n;
    int tab[n];
    for (i=0; i<n; i++) {
        cin>>tab[i];
    }
    sort(tab,tab+n);
    for (i=1; i<n; i+=2) {
        w+=(tab[i]-tab[i-1]);
    }
    cout<<w;
    return 0;
}