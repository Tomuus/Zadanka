#include <ios>
#include <cstring>
#include <cstdio>

//Wcale nie kopiowale identycznego kodu z kolka ze staszica

// Mial pan pecha bo ten faraon tez byl na nim i wystarczylo 2 linijki zmienic
//Tu tez 2




using namespace std;

int tab[(1<<20) + 1];
int ll=1;

void zamiana (int i, int nowe)
{
    i+=ll;
    tab[i]=nowe;
    while(i>1)
    {
        i/=2;
        tab[i]=max(tab[i*2], tab[i*2+1]);
    }
}

int przedzial(int p, int k, int a, int b, int i) {
    if (p <= a && b <= k + 1) return tab[i];
    if (b <= p || k + 1 <= a) return -2147483648;
    int mid = (a + b) / 2;
    return max (przedzial(p, k, a, mid, i * 2) , przedzial(p, k, mid, b, i * 2 + 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    memset(tab, 0x80, sizeof(tab));
    int i,n,m,index,nw;
    char op[10];
    scanf("%d %d", &n, &m);
    while(ll<n) ll*=2;
    for(i=0;i<n;i++) scanf("%d", &tab[ll + i]); //wczytywanie
    for(i=ll-1;i>0;i--) tab[i]=max(tab[i*2],tab[i*2+1]); //dopelnianie
    //for(i=0;i<n+5;i++) cout<<tab[i]<<' ';
    for(i=0;i<m;i++)
    {
        scanf("%s %d %d", op, &index, &nw);
        if (op[0] != 'M') zamiana(index - 1, nw);
        else printf("%d\n", przedzial(index - 1, nw - 1, 0, ll, 1));
        //for(int j=0;j<n;j++) cout<<tab[ll+j]<<' ';
        //cout<<endl;
    }
}
