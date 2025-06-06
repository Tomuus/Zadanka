#include <iostream>
#include <array>

using namespace std;

const long long mod=1000000007;

array<array<long long,2>,2> matrix_mult (array<array<long long,2>,2> a, array<array<long long,2>,2> b)
{
    array<array<long long,2>,2> ans = {{{0,0},{0,0}}};
    long long i,j,k;
    for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++) {ans[i][j]+=a[i][k]*b[k][j]; ans[i][j]%=mod;} //linijkopodobna funkcja n^3 by tomus
    return ans;
}

array<array<long long,2>,2> qp (array<array<long long,2>,2> base, long long pow)
{
    array<array<long long,2>,2> ans={{{1,0},{0,1}}};
    while(pow>0)
    {
        if(pow%2==1) ans=matrix_mult(ans, base);
        base=matrix_mult(base,base);
        pow/=2;
    }
    return ans;
}

array<array<long long,4>,4> big_mult (array<array<long long,4>,4> a, array<array<long long,4>,4> b)
{
    array<array<long long,4>,4> ans;
    ans =
    {{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    }};
    long long i,j,k;
    for(i=0;i<4;i++) for(j=0;j<4;j++) for(k=0;k<4;k++) {ans[i][j]+=a[i][k]*b[k][j]; ans[i][j]%=mod;} //linijkopodobna funkcja n^3 by tomus
    return ans;
}


array<array<long long,4>,4> big_qp (array<array<long long,4>,4> base, long long pow)
{
    array<array<long long,4>,4> ans;
    ans =
    {{
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    }};
    while(pow>0)
    {
        if(pow%2==1) ans=big_mult(ans, base);
        base=big_mult(base,base);
        pow/=2;
    }
    return ans;
}

//qp({{{1,1},{1,0}}},b)[0][0];

int main()
{
    long long a,b,tab[4];
    cin>>a>>b;
    array<array<long long,2>,2> tmp=qp({{{1,1},{1,0}}},a-1);
    tab[0]=0;
    tab[1]=tmp[0][0];
    tab[3]=tmp[1][0];
    tab[2]=tab[1]*tab[3];
    tab[1]*=tab[1];
    tab[3]*=tab[3];
    tab[1]%=mod;
    tab[2]%=mod;
    tab[3]%=mod;
    array<array<long long,4>,4> baz =
    {{
    {1,1,2,1},
    {0,1,2,1},
    {0,1,1,0},
    {0,1,0,0}
    }};
    baz=big_qp(baz, b-a+1);
    long long ans_fr=0;
    ans_fr+=tab[1]*baz[0][1]%mod;
    ans_fr%=mod;
    ans_fr+=tab[2]*baz[0][2]%mod;
    ans_fr%=mod;
    ans_fr+=tab[3]*baz[0][3]%mod;
    ans_fr%=mod;
    cout<<ans_fr;
}
