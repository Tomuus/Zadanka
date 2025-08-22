#include <iostream>

using namespace std;

int main ()
{
        int n, m, j;
        cin>>n>>m;
        j = m;
        for(int i=0; i<n; i++)
        {
                cout<<(i-n/2)<<' '<<j<<endl;
                j--;
        }
}
