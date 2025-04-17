#include <iostream>

using namespace std;

int main()
{
    long long n,m,c;
    cin>>n>>m>>c;
    if ((c%n==0 or c%m==0) and c<=n*m) cout<<"TAK";
    else cout<<"NIE";
}