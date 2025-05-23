#include <iostream>
#include <string>

using namespace std;

int main()
{
    //nie ma to jak modyfikowanie kodu z przed roku
    int i=0,tmp,p=0,k=0,sum=0,w,d=0;
    string a;
    cin>>a;
    cin>>w;
    while(p<=n)
    {
        if (sum==w)
        {
            d++;
            sum+=tab[p];
            p++;
        }
        if(sum<w)
        {
            sum+=tab[p];
            p++;
        }
        if(w<sum)
        {
            sum-=tab[k];
            k++;
        }
    }
    cout<<d;
}
