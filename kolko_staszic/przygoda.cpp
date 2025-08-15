#include <iostream>
#include <vector>

using namespace std;

vector<int> graf [100007];
int odl[100007];
int ndl[100007];
int mdl=0;
int ddl=0;

void droga(int s, int o)
{
    ndl[s]=0;
    odl[s]=odl[o]+1;
    if(mdl<=odl[s])
    {
        ddl=mdl;
        mdl=odl[s];
    }
    for(auto i: graf[s])
    {
        if(i==o)continue;
        droga(i,s);
        ndl[s]=max(ndl[s],ndl[i]+1);
    }
    return;
}

int main()
{
    int i,n,tmp,tmp1;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        cin>>tmp>>tmp1;
        graf[tmp].push_back(tmp1);
        graf[tmp1].push_back(tmp);
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        odl[0]=-1;
        droga(tmp,0);
        cout<<mdl+1<<endl;
    }
}
