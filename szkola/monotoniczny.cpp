#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int tab[256];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(begin(tab), end(tab), 0);

    int mx = -1;
    char mxi = '\0';
    string n;
    cin >> n;

    for (char i : n) {
        tab[i]++;
        if (tab[i] > mx || (tab[i] == mx && i > mxi)) {
            mx = tab[i];
            mxi = i;
        }
    }
    sort(n.begin(),n.end());
    for (char i : n) {
        if (i != mxi) cout << i;
    }
    cout << "\n";
}