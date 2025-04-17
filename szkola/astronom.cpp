#include <iostream>

using namespace::std;

int main()
{
    int n,i,tmp,bck;
    bool stan;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>tmp;
        if((tmp>bck and tmp!=15) or tmp==0) stan=true;
        else stan=false;
        bck=tmp;
    }
    if (n<2 and tmp!=0 and tmp!=15)
    {
        cout<<"UNKNOWN";
        return 0;
    }
    if(stan) cout<<"UP";
    else cout<<"DOWN";
}