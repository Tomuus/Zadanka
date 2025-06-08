#include <iostream>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>

//jezu to jest jakas czarna magia
//dobra zaraz to ogarne i naucze sie moze jakos z pamieci pisac

using namespace::std;

typedef long long lo; //niemozliwe czyzbym uzyl mozgu i nauczyl sie czegos nowego

const long long big=1e9;
unordered_map <lo,lo> tab;
unordered_map <lo,lo> kolejki;
long long ll=1;

void push(lo l, lo p, lo k)
{
    if(kolejki[k]%2==0) return;
    lo mid =(l+p)/2;
    tab[k*2]=(mid-l+1)-tab[k*2];
    tab[2*k+1]=(p-mid)-tab[k*2+1];
    kolejki[k*2]+=kolejki[k];
    kolejki[k*2+1]+=kolejki[k];
    kolejki[k]=0;
}

void apdejt (lo k, lo l, lo p, lo ol, lo op, lo v)
{
    if(ol>p or op<l) return;
    if(ol<=l and p<=op)
    {
        tab[k]=(p-l+1)-tab[k];
        kolejki[k]+=v;
        return;
    }
    push(l,p,k);
    int mid=(l+p)/2;
    apdejt (k*2,l,mid,ol,op,v);
    apdejt (k*2+1,mid+1,p,ol,op,v);
    tab[k]=tab[k*2]+tab[k*2+1];
}

long long przedzial(long long p, long long k, long long a, long long b, long long i) {
    if (p <= a && b <= k ) return tab[i]; //dokladnie wewnatrz
    if (b<p or a>k) return 0; //zly przedzial
    push(a,b,i);
    long long mid = (a + b) / 2; //cos miedzy
    return przedzial(p, k, a, mid, i * 2) + przedzial(p, k, mid+1, b, i * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //fill(tab, tab + ((1<<21)+7), 0);
    long long i,n,m,a,b,c;
    char x;
    cin>>n>>m;
    while(ll<n) ll*=2;
    //for(i=0;i<n;i++) tab[ll+i]=1; //wczytywanie
    //for(i=ll-1;i>0;i--) tab[i]=tab[i*2]+tab[i*2+1]; //dopelnianie
    //for(i=0;i<n+5;i++) cout<<tab[i]<<' ';
    //cout<<przedzial(0,n-1,0,ll-1,1)<<endl;
    for(i=0;i<m;i++)
    {
        cin>>x>>a>>b;
        a--; b--;
        if(x=='*') {apdejt(1,0,ll-1,a,b,1);}
        else cout<<b-a+1-przedzial(a,b,0,ll-1,1)<<'\n';
        //for(int j=ll;j<ll+n;j++) cout<<tab[j]<<' ';
        //cout<<endl;
    }
}
