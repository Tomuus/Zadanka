#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dziel(const vector<long long>& tab, long long goal, long long n)
{
    long long ans = 1;
    long long last = tab[0];
    for (int i = 1; i < n; i++)
    {
        if (tab[i] - last >= goal)
        {
            last = tab[i];
            ans++;
        }
    }
    return ans;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> tab(n);
    for (int i = 0; i < n; i++)
        cin >> tab[i];

    sort(tab.begin(), tab.end()); // upewnij się, że stanowiska są posortowane

    long long l = 0, p = tab[n - 1] - tab[0];
    while (l < p)
    {
        long long mid = (l + p + 1) / 2;
        if (dziel(tab, mid, n) >= m)
            l = mid;
        else
            p = mid - 1;
    }

    cout << l << "\n";
}
