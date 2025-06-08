#include <iostream>

//jezu to jest jakas czarna magia
//dobra zaraz to ogarne i naucze sie moze jakos z pamieci pisac

using namespace::std;

typedef long long lo; //niemozliwe czyzbym uzyl mozgu i nauczyl sie czegos nowego

const int big=1e9;
int tab[(1<<21) + 7];
int kolejki[(1<<21)+7];
int ll=1;

void push(int l, int p, int k)
{
    if(kolejki[k]==0) return;
    int mid =(l+p)/2;
    tab[k*2]= kolejki[k];
    tab[2*k+1] = kolejki[k];
    kolejki[k*2]=kolejki[k];
    kolejki[k*2+1]=kolejki[k];
    kolejki[k]=0;
}

void apdejt (int k, int l, int p, int ol, int op, int v)
{
    if(ol>p or op<l) return;
    if(ol<=l and p<=op)
    {
        tab[k]=v;
        kolejki[k]=v;
        return;
    }
    push(l,p,k);
    int mid=(l+p)/2;
    apdejt (k*2,l,mid,ol,op,v);
    apdejt (k*2+1,mid+1,p,ol,op,v);
    tab[k]=max(tab[k*2],tab[k*2+1]);
}

int przedzial(int p, int k, int a, int b, int i) {
    if (p <= a && b <= k ) return tab[i]; //dokladnie wewnatrz
    if (b<p or a>k) return 0; //zly przedzial
    push(a,b,i);
    int mid = (a + b) / 2; //cos miedzy
    return max(przedzial(p, k, a, mid, i * 2) , przedzial(p, k, mid+1, b, i * 2 + 1));
}

int main()
{
    fill(tab, tab + ((1<<21)+7), 0);
    int i,n,m,a,b,c,p;
    cin>>n>>m;
    while(ll<n) ll*=2;
    /*for(i=0;i<n;i++) cin>>tab[ll+i]; //wczytywanie
     *    for(i=ll-1;i>0;i--) tab[i]=tab[i*2]tab[i*2+1]; //dopelnianie */
    //cout<<'a';
    //for(i=0;i<=n;i++) cout<<tab[i+ll]<<' ';
    //cout<<endl;
    //cout<<przedzial(0,n-1,0,ll-1,1)<<endl;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        c=przedzial(b,a+b-1,0,ll-1,1)+1;
        //cout<<c<<' ';
        apdejt(1,0,ll-1,b,a+b-1,c);
        //for(int j=0;j<=n;j++) cout<<tab[ll+j]<<" ";
        //cout<<endl;
    }
    //cout<<endl;
    cout<<przedzial(0,n+1,0,ll-1,1)<<endl;
    //for(i=0;i<=n;i++) cout<<tab[ll+i]<<" ";
}
