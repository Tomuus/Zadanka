#include<iostream>

using namespace::std;

int main()
{
    int n,i=0,sl=0,tmp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        sl+=tmp;
    }
    cout<<sl;
    return 0;
}