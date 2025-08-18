#include <iostream>

//jezu to jest jakas czarna magia
//dobra zaraz to ogarne i naucze sie moze jakos z pamieci pisac
//Kurw cos mnie pieklo jezeli wierzylem ze bede to robil z pamieci

using namespace::std;

typedef long long lo; //niemozliwe czyzbym uzyl mozgu i nauczyl sie czegos nowego

const long long big=1e9;
long long tab[(1<<21) + 7];
long long kolejki[(1<<21)+7];
long long ll=1;

void push(lo l, lo p, lo k)
{
    if(kolejki[k]==0) return; //Jezeli brak zadan koniec
    lo mid =(l+p)/2;
    tab[k*2]+= kolejki[k]*(mid-l+1); //Aktualizacja dzieci
    tab[2*k+1] += kolejki[k]*(p-mid);
    kolejki[k*2]+=kolejki[k]; //Danie dzieciom zadania aktualizacji
    kolejki[k*2+1]+=kolejki[k];
    kolejki[k]=0;
}

void apdejt (lo k, lo l, lo p, lo ol, lo op, lo v)
//Rozpis zmiennych
//k - miejsce w tablicy
//l, p - rozwarzany przedzial
//ol, op - docelowy przedzial
//v - o ile zmienic
{
    if(ol>p or op<l) return; //Jezeli nie nalezy do przedizalu do aktualizacji, omin
    if(ol<=l and p<=op) //Jezeli nalezy, aktualizuj
    {
        tab[k]+=v*(p-l+1); //Jako ze aktualizujemy wiele punktow, mnozymy
        kolejki[k]+=v; //kolejkujemy dalsze zamiany
        return;
    }
    //Jezeli nalezy tylko czesciowo
    push(l,p,k); //Aktualizuj poprzednie zmiany
    int mid=(l+p)/2;
    apdejt (k*2,l,mid,ol,op,v); //Wejscie glebiej w dzieci akt. wieszcholka
    apdejt (k*2+1,mid+1,p,ol,op,v);
    tab[k]=tab[k*2]+tab[k*2+1]; //Aktualizacja danego punktu na podstawie zmiany dzieci
}

long long przedzial(long long p, long long k, long long a, long long b, long long i) {
    if (p <= a && b <= k ) return tab[i]; //dokladnie wewnatrz
    if (b<p or a>k) return 0; //zly przedzial
    push(a,b,i); //Aktoualizacja dzieci
    long long mid = (a + b) / 2; //cos miedzy
    return przedzial(p, k, a, mid, i * 2) + przedzial(p, k, mid+1, b, i * 2 + 1);
}

int main()
{
    fill(tab, tab + ((1<<21)+7), 0);
    long long i,n,m,a,b,c;
    char x;
    cin>>n>>m;
    while(ll<n) ll*=2;
    for(i=0;i<n;i++) cin>>tab[ll+i]; //wczytywanie
    for(i=ll-1;i>0;i--) tab[i]=tab[i*2]+tab[i*2+1]; //dopelnianie
    //for(i=0;i<n+5;i++) cout<<tab[i]<<' ';
    cout<<przedzial(0,n-1,0,ll-1,1)<<endl;
    for(i=0;i<m;i++)
    {
        cin>>x>>a>>b;
        a--; b--;
        if(x=='+') {cin>>c; apdejt(1,0,ll-1,a,b,c);}
        else cout<<przedzial(a,b,0,ll-1,1);
    }
}
