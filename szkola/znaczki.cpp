#include <iostream>
#include <map>

using namespace std;

map <long long, bool> tab;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,tmp,i,wynik=0;
    cin>>a>>b;
    for (i=0; i<a; i++) {
        cin>>tmp;
        tab[tmp]=true;
    }
    for (i=0; i<b; i++) {
        cin>>tmp;
        if(!tab[tmp]) wynik++;
    }
    cout<<wynik;
}