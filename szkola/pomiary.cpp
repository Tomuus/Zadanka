#include <iostream>

using namespace std;

int main()
{
    long long n,i,l=0,last=0;
    while(last!=-1)
    {
        cin>>n;
        if(n!=last) l++;
        last=n;
    }
    cout<<l-1;
}