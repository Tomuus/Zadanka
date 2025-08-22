#include <iostream>
#include <random>

using namespace std;

int main ()
{
        int seed;
        cin >> seed;
        mt19937 ran(seed);
        cout<<ran() % 1000000000 << ' ' << ran() % 1000000000 <<endl;
}
