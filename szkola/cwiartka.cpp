#include <iostream>

using namespace std;

int main()
{
    int n,m,i=0;
    cin>>n>>m;
    if(n>0 and m>0) cout<<'I';
    if(n<0 and m>0) cout<<"II";
    if(n<0 and m<0) cout<<"III";
    if(n>0 and m<0) cout<<"IV";
    if(n==0 and m!=0) cout<<"OY";
    if(n!=0 and m==0) cout<<"OX";
    if(n==0 and m==0) cout<<'0';
}