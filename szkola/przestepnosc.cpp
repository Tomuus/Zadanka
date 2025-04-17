#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i;
    cin>>i;
    if(i%400==0 or (i%4==0 and i%100!=0)) cout<<"TAK";
    else cout<<"NIE";
}