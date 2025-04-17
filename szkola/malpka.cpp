#include <iostream>
#include <numeric>  

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, size, jump;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> size >> jump;
        cout << size / gcd(size, jump) << "\n";
    }
}