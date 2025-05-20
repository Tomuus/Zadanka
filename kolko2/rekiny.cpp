#include <iostream>

using namespace::std;

bool tab[1000007];
bool dp[1000007];
int n,a,b,c,d;

void rekiny(int i, bool magik)
{
    if(!tab[i+a] and ) {dp[i+a]=1; rekiny(i+a,magik);}
    if(!tab[i+b] and ) {dp[i+b]=1; rekiny(i+b,magik);}
    if(!tab[i+c] and ) {dp[i+c]=1; rekiny(i+c,magik);}
    if(!tab[i+d] and magik) {dp[i+d]=1; rekiny(i+d,false);}
}

int main()
{
    long long i=0,j=0;
    cin>>n;
    cin>>a>>b>>c>>d;
    for(i=0;i<n;i++) cin>>tab[i];
    dp[0]=1;
    rekiny(0,0);
}
//sposob nie zadziala dodatkowa tab czy da sie skoczyc magik
