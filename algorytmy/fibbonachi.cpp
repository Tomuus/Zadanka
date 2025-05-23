#include <iostream>
#include <array>

using namespace std;

array<array<long long,2>,2> matrix_mult (array<array<long long,2>,2> a, array<array<long long,2>,2> b)
{
    array<array<long long,2>,2> ans = {{{0,0},{0,0}}};
    long long i,j,k;
    for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++) ans[i][j]+=a[i][k]*b[k][j]; //linijkopodobna funkcja n^3 by tomus
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

int main()
{
    long long a,b,n,i;
    //cout<<matrix_mult({{{1,1},{1,0}}},{{{1,1},{1,0}}})[0][0];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>b;
        cout<<qp({{{1,1},{1,0}}},b)[0][0]<<endl;
    }
}
