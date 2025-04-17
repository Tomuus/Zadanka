#include<iostream>

using namespace::std;

int main()
{
    //cout<<'q';
    int n,i,cel,start=-1,end=0,kap=0,w=-1,z=0;
    cin>>n>>cel;
    int tab[n];
    for(i=0;i<n;i++) cin>>tab[i];
    //cout<<'a';
    while((start<n or kap<cel) and end<n)
    {
        if (kap<cel and start<n-1) {
            start++;
            kap+=tab[start];
            z++;
            //cout<<'+';
        }
        else{
            kap-=tab[end];
            end++;
            z--;
            //cout<<end<<' ';
        }
        if(kap<=cel) w=max(z,w);
        //cout<<'*';
    }
    cout<<w;
    return 0;
}