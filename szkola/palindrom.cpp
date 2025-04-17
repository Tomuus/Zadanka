#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    cin>>n;
    int p=0,k=n.size()-1;
    while(p<k)
    {
        if(n[p]!=n[k]) {cout<<"NIE"; return 0;}
        p++;
        k--;
    }
    cout<<"TAK";
}