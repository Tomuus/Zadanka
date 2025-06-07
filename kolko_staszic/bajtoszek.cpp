#include <iostream>
#include <array>

using namespace std;

typedef long long ll;

const long long mod=1000000009;

array<array<long long,3>,3> matrix_mult (array<array<long long,3>,3> a, array<array<long long,3>,3> b)
{
    array<array<long long,3>,3> ans = {{{0,0,0},{0,0,0},{0,0,0}}};
    long long i,j,k;
    for(i=0;i<3;i++) for(j=0;j<3;j++) for(k=0;k<3;k++) {ans[i][j]+=a[i][k]*b[k][j]; ans[i][j]%=mod;} //linijkopodobna funkcja n^3 by tomus
    return ans;
}

array<array<long long,3>,3> qp (array<array<long long,3>,3> base, long long pow)
{
    array<array<long long,3>,3> ans={{{1,0,0},{0,1,0},{0,0,1}}};
    while(pow>0)
    {
        if(pow%2==1) ans=matrix_mult(ans, base);
        base=matrix_mult(base,base);
        pow/=2;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    n--;
    array<array<long long,3>,3> ans;
    ans=
    {{
    {1,0,1},
    {1,0,0},
    {0,1,0}
    }};
    ans=qp(ans,n);
    cout<<ans[0][0];
}
