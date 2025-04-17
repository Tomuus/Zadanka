#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,i;
    cin>>n;
    for(i=0;i<n+2;i++) cout<<'#';
    cout<<endl<<'#';
    for(i=0;i<n;i++) cout<<'@';
    cout<<'#'<<endl;
    for(i=0;i<n+2;i++) cout<<'#';
}