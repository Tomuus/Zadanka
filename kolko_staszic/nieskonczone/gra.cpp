#include <iostream>
#include <string>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout<<'@';
    string tmp="ab";
    int p=0,k=1000000,mid;
    while(tmp!="OK")
    {
        //cout<<'#';
        mid=(p+k)/2;
        cout<<mid<<endl;
        cin>>tmp;
        if(tmp=="WIEKSZA") p=mid;
        else k=mid;
        if(tmp=="OK") return 0;
    }
    return 0;
}