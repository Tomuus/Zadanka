#include <iostream>
#include <vector>

using namespace std;

//czyzby to byla dokumentacja by tomus (tak to jest mozliwe)
//jezu dlaczego ten kod ma tak dokladne czasowki

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long i,n,j,wynik=0,min_kup;
    cin>>n;
    vector <long long> ceny(n), koszty(n); //kto wymyslil ze vectory sa szybsze
    for(i=0;i<n;i++) cin>>ceny[i];
    koszty[0]=0;
    for(i=1;i<n;i++)
    {
        cin>>koszty[i];
    }
    min_kup=ceny[0]; //min_kup trzyma najlepsze miejsce w ktorym mozemy kupic wliczajac koszt prejazdu
    for(i=0;i<n;i++)
    {
        min_kup+=koszty[i];
        min_kup=min(min_kup,ceny[i]); //updatowanie min_kup
        wynik=max(wynik,ceny[i]-min_kup); //szukanie lepszej opcji (wynik na start jest 0 dlatego jezeli nic sie nie oplaca to 0)
        //cout<<min_kup<<' ';
    }
    min_kup=ceny[n-1];
    for(i=n-1;i>=0;i--) //to samo przejscie od 2 strony
    {
        min_kup+=koszty[i+1];
        min_kup=min(min_kup,ceny[i]);
        wynik=max(wynik,ceny[i]-min_kup);
        //cout<<min_kup<<' ';
    }
    cout<<wynik;
}
