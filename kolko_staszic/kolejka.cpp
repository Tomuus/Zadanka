#include <iostream>
#include<queue>

using namespace::std;

int main()
{
    queue <int> kolejka;
    int i,n,tmpi;
    char tmpc;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmpc;
        if(tmpc=='+')
        {
            cin>>tmpi;
            kolejka.push(tmpi);
        }
        else{
            cout<<kolejka.front()<<endl;
            kolejka.pop();
        }
    }
}