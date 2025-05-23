#include <iostream>
#include<stack>

using namespace::std;

int main()
{
    stack <int> kolejka;
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
            cout<<kolejka.top()<<endl;
            kolejka.pop();
        }
    }
}

