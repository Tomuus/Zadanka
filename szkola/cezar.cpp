#include <iostream>
#include <string>

using namespace::std;

char cezar (char n, int b)
{
    if(n>='a' and n<='z')
    {
        if(n+b>'z') return n+b-26;
        if(n+b<'a') return n+b+26;
        else return n+b;
    }
    if(n<='Z' and n>='A')
    {
        if(n+b>'Z') return n+b-26;
        if(n+b<'A') return n+b+26;
        else return n+b;
    }
    return n;
}


void szyfruj (string n, int b)
{
    for(int i=0;i<n.size();i++)
    {
        //cout<<'*';
        cout<<cezar(n[i],b);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    int a,b;
    cin>>a>>b>>n;
    if (a==1) szyfruj(n,b);
    else szyfruj (n, b*-1);
}