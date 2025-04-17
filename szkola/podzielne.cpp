#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int count_up_to_b = b / c;
    int count_up_to_a_minus_1 = (a - 1) / c;

    int result = count_up_to_b - count_up_to_a_minus_1;

    cout << result << '\n';
    return 0;
}