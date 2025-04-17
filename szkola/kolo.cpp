#include <iostream>
#include <cmath>
#include <iomanip>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double r;
    cin>>r;
    cout<<setprecision(3)<<fixed<<M_PI*r*r<<endl<<M_PI*r*2;
}