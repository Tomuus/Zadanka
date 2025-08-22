#include <iostream>
#include <vector>

using namespace std;

vector <pair<long long, long long>> graf[500007];
long long deph[500007];
long long jump[500007][20];
long long maks[500007][20]; //takie random shit zebym wiedzial jaki jest max na danym skoku
//long long patyk[500007];
long long kijek[500007];
long long current;

void kolejki(int p, int parent)
{
    jump[p][0]=parent;
    maks[p][0]=kijek[p]; //kur.. ja juz nie pamietam ktora odleglosc tu trymalem
                        //dobra liczmy na to ze jest ok
    //patyk[p]=patyk[parent]+kijek[p]; //wannabe sumy prefiksowe (to ma taie male szanse ze dziala) 
    long long i;
    for(int i=1;i<20;i++) {
            jump[p][i]=jump[jump[p][i-1]][i-1]; //tego sie nie dotykam
            maks[p][i]=max(maks[jump[p][i-1]][i-1],maks[p][i-1]); //ok chyba ogarniam
    }
    for(auto [i,w] : graf[p])
    {
        if(i==parent) continue;
        kijek[i]=w;
        deph[i]=deph[p]+1;
        kolejki(i,p);
    }
}

int lift(int b,int t)
{
    for(int i=19;i>=0;i--)
    {
        if(deph[jump[b][i]]>=deph[t]) { 
                current = max(current, maks[b][i]);
                b=jump[b][i];
        }
    }
    return b;
}

int lca(int a, int b)
{
    current = -999999999; //to bedzie nasz wynik
    if(deph[a]<deph[b]) swap(a,b);
    a=lift(a,b);
    if(a==b) return current;
    for(int i=19;i>=0;i--)
    {
        if(jump[a][i]!=jump[b][i])
        {
            
            current = max(current, maks[a][i]);
            current = max(current, maks[b][i]);
            a=jump[a][i];
            b=jump[b][i];
        }
    }
    return max(max(maks[a][0], maks[b][0]), current);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i,n,m,a,b,p;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>a>>b>>p;
        graf[a].push_back({b,p});
        graf[b].push_back({a,p});
    }
    deph[1]=0;
    //patyk[1]=0;
    kolejki (1,1);
    //for(i=1;i<=5;i++) cout<<patyk[i]<<' ';
    while(true)
    {
        cin>>a;
        if (a==-1)return 0;
        cin>>b;
        int x=lca(a,b);
        if (a==b) x=0;
        cout<<x<<endl;
        //cout<<patyk[a]+patyk[b]-patyk[x]-patyk[x]<<endl;
    }
}
