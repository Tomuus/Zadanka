#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,a,b,wynik,roz;
    char best;
    string n;
    //cout<<"!";
    cin>>n>>m;
    roz=n.size();
    int tab[roz+1][30],i=0,j;
    //cout<<'!';
    for(j=0;j<30;j++)tab[0][j]=0;
    for(i=1;i<=n.size();i++)
    {
        for(j=0;j<=26;j++) tab[i][j]=tab[i-1][j];
        //cout<<'*';
        tab[i][int(n[i-1])-96]+=1;
    }
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        wynik=-1;
        for(j=0;j<=26;j++)
        {
            if(tab[b][j]-tab[a-1][j]>wynik)
            {
                wynik=tab[b][j]-tab[a-1][j];
                best=char(j+96);
            }
        }
        cout<<best<<' '<<wynik<<endl;
    }
}
