#include <iostream>
#include <vector>

using namespace std;

//czyzby to byla dokumentacja by tomus (tak to jest mozliwe)
//jezu dlaczego ten kod ma tak dokladne czasowki brakowalo mi 0.01s

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long i,n,j,wynik=0,min_kup;
    cin>>n;
    vector <long long> ceny(n), koszty(n); //kto wymyslil ze niby vectory sa szybsze
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
        if(i!=0) min_kup=min(min_kup,ceny[i]);
        wynik=max(wynik,ceny[i]-min_kup);
        //cout<<min_kup<<' ';
    }
    min_kup=ceny[n-1];
    for(i=n-1;i>=0;i--)
    {
        min_kup+=koszty[i+1]; //doslownie zmienienie tego w 2 linijki amiast trzymania w max pomoglo po co to jest az tak
        if(i!=n-1)min_kup=min(min_kup,ceny[i]);
        wynik=max(wynik,ceny[i]-min_kup);
        //cout<<min_kup<<' ';
    }
    cout<<wynik;
}
