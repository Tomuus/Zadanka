#include <algorithm>
#include <cstdio>
#include <vector>

//Ummmm actually to powinienem uzyc binsercha
//To wszystko wina czasowek
//Chyba sa zle

using namespace std;

int main()
{
    int i,n,tmp;
    scanf("%d", &n);
    vector <int> tab(n);
    for(i=0;i<n;i++) scanf("%d", &tab[i]);
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &tmp);
        auto low= lower_bound(tab.begin(),tab.end(),tmp); //nieudany binsearch bo jestem leniwy
        auto top= upper_bound(tab.begin(),tab.end(),tmp); //zaraz naucze sie jak dokladnie dziala to cos
        printf("%d\n", (int)(top-low));
    }
}
