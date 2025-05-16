#include <ios>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    long long n,k,x,i,tmp,zmeczenie=-1,dni=0;
    cin>>n>>k>>x;;
    for(i=0;i<n-1;i++)
    {
        cin>>tmp;
        if(zmeczenie-tmp>=0) zmeczenie-=tmp;
        else
        {
            zmeczenie=x-tmp;
            //cout<<tmp<<' ';
            dni++;
        }
    }
    if(dni<=k) cout<<"TAK";
    else cout<<"NIE";
    return 0;
}
