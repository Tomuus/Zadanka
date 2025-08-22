#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;

int main ()
{
        int n, type;
        cin>>type>>n;
        if(type!=1) cout<<"NIE";
        for(int i=0; i<n; i++)
        {
                int input;
                cin>>input;
                cout<<input<<' '<<input-1<<endl;
                int tab[input-1];
                for(int j=0; j<input; j++)
                {
                           tab[j]=j;                                       
                }
                random_device rd;
                mt19937 g(rd());
                shuffle(&tab[0], &tab[input-2], g);
                for auto
                cout<<"\n";
        }
}
