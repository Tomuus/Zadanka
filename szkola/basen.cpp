#include <iostream>

using namespace::std;

int main()
{
    int i,n,tmp,baseny=1,old=-1;
    bool kierunek=true;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        if(kierunek and tmp<old) {kierunek=false; baseny++;}
        if(!kierunek and tmp>old) {kierunek=true; baseny++;}
        old = tmp;
    }
    cout<<baseny;
}