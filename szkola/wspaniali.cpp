#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i,n;
    cin>>n;
    int tab[n];
    for (i=0; i<n; i++) {
        cin>>tab[i];
    }
    sort(tab,tab+n);
    for (i=n-1; i>n-11; i--) {
        cout<<tab[i]<<' ';
    }
    return 0;
}