#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

/*
 * dobra jak przeszlo to ide w dokumentacje
 * zadanie zajelo mi jakies 2h wiec wsm przydaloby sie
 * na poczatku mialem zapytac chata o podpowiedz ale w koncu to nie umialem mu wytlumaczyc jak podpowiadac
 * w zwiazku z tym kod jest 100% tomus (mimo ze z moja inteligencja malo to mozliwe)
 */

map <long long ,int> wysokosci; //mapa bo nie stworzy pustych indeksow przechowuje na jakiej wysokosci znajduje sie punkt o szerokosci x
map <long long, int> hierarhia; //przechowuje kolejnosc punktow wzdluz x

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long i,n,x,y,energia=0;
    int old;
    cin>>n;
    long long prawo[n+1],lewo[n+1],szerokosci[n]; //lewo i prawo to sumy prefiksowe mowiace ile energii zuzywamy na pokonanie danej wysokosci (nie liczy szerokosci) szerokosci[n] trzyma oryginalna kolejnosc
    for(i=0;i<n;i++){
        cin>>x>>y; //wczytywanie ale ta czesc jest taka na logike
        wysokosci[x]=y;
        szerokosci[i]=x;
    }
    i=0;
    prawo[0]=0;
    lewo[0]=0;
    for(auto j:wysokosci) //sumy prefiksowe ida po calej mapie w lewo i prawo w kolejnosci od prawej do lewej (tu przydaje sie mapa bo nie ma tych pustych indeksow wiec mozna je ominac)
    {
        if(i==0) {old=j.second; hierarhia[j.first]=0; i++; continue;} //dodatkowe warunki dla i=0 (to sa te linijki z dolu petli wklejone drugi raz)
        prawo[i]=prawo[i-1]+max(0,j.second-old); //max(0) jest po to zeby nie liczyc zejsc w dol
        lewo[i]=lewo[i-1]+max(0,old-j.second);
        //cout<<prawo[i]<<'l'<<lewo[i]<<' '; //debugery sa overrated
        old=j.second;
        hierarhia[j.first]=i; //wypelnianie hierarhii
        i++;
    }
    old=0;
    for(i=0;i<n-1;i++){
        energia+=abs(szerokosci[i]-szerokosci[i+1]);
        if(szerokosci[i]-szerokosci[i+1]<0) energia+=prawo[hierarhia[szerokosci[i+1]]]-prawo[hierarhia[szerokosci[i]]];  //true jezeli idziemy w prawo
        //liczenie sum prefiksowych tym wielkim tabem
        // w skrocie:
        //szerokosci przechowuje pozycje x punktu
        //hierarhia przechowuje jego kolejnosc wzgledem tego x
        //prawo i lewo przechowuje odlegloscie wg. hierarhii
        else energia+=lewo[hierarhia[szerokosci[i]]]-lewo[hierarhia[szerokosci[i+1]]];
        //cout<<energia-old<<'x'<<abs(szerokosci[i]-szerokosci[i+1])<<' '; //skibidi debugowanie by tomus
        old=energia;
    }
    cout<<energia;
}
