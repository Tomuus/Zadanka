#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i,n,tmp,prew=0;
    cin>>n;
    for(i=1;i<n+1;i++) {
        cin>>tmp;
        cout<<tmp-prew<<' ';
        prew=tmp;
    }
}