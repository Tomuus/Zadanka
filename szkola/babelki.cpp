#include <iostream>

using namespace std;

int main()
{
    long long n,i=0,j=1;
    bool f=true;
    cin>>n;
    long long tab[n];
    while(i<n)
    {
        cin>>tab[i];
        i++;
    }
    while(j<n)
    {
        i=1;
        f=false;
        while(i<n)
        {
            if(tab[i]<tab[i-1]) {swap(tab[i],tab[i-1]); f=true;}
            i++;
        }
        for(int k=0;k<n;k++) cout<<tab[k]<<' ';
        cout<<endl;
        j++;
    }
    return 0;
}
