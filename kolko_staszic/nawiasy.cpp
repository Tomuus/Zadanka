#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll ;

int main()
{
    stringstream ss;
    ll n,i,d=0;
    stack <int> o;
    char tmp;
    cin>>n;
    n*=2;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        if(tmp=='(')
        {
            d++;
            o.push(i);
        }
        else if(d>0)
        {
            d--;
            ss<<endl<<i+1<<' '<<o.top()+1;
            o.pop();
        }
        else {cout<<"NIE"; return 0;}
        //cout<<d<<' ';
    }
    if (d!=0) cout<<"NIE";
    else
    {
        cout<<"TAK"<<endl;
        string b=ss.str();
        reverse(b.begin(),b.end());
        cout<<b;
    }
    return 0;
}
