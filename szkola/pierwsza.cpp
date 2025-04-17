#include <iostream>

using namespace::std;

bool prim (int n)
{
    int i=0;
    if(n==0 or n==1) return false;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int n,i,tmp;
    cin>>n;
    if(prim(n)) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;
    /*for(i=0;i<n;i++)
    {
        cin>>tmp;
        if(prim(tmp)) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }*/
}