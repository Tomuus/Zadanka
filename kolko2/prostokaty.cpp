#include <iostream>

using namespace::std;

int main()
{
    int i,n,j,odp=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j*j<=i;j++)
        {
            if(i%j==0) odp++;
        }
    }
    cout<<odp;
}
