#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

queue <long long> td;
vector <long long> graf[1002004];
long long odl[1002004];
long long visited[1002004];

void kolejki (long long p)
{
    visited[p]=1;
    odl[p]=0;
    td.push(p);
    while(!td.empty())
    {
        for(auto i : graf[td.front()])
        {
            if (visited[i]==0)
            {
                visited[i]=1;
                odl[i]=odl[td.front()]+1;
                td.push(i);
            }
        }
        td.pop();
    }
    return;
}

int main()
{
    fill(odl, odl + 1002004, -1);
    fill(visited, visited + 1002004, 0);
    long long n,m,i,a,b,szer,dlu,start,koniec;
    char tmp;
    cin>>szer>>dlu;
    char miasto[szer][dlu];
    //cout<<"ffghyj";
    for(i=0;i<dlu;i++)
    {
        for(long long j=0;j<szer;j++)
        {
            long long pozycja=i*szer+j+1;
            cin>>tmp;
            miasto[j][i]=tmp;
            if(tmp!='#')
            if(tmp=='.' or tmp=='P' or tmp=='W')
            {
                if(j>0 and (miasto[j-1][i]=='.' or miasto[j-1][i]=='P' or miasto[j-1][i]=='W' ))
                {
                    graf[pozycja].push_back(pozycja-1);
                    graf[pozycja-1].push_back(pozycja);
                }
                if(i>0 and (miasto[j][i-1]=='.' or miasto[j][i-1]=='P' or miasto[j][i-1]=='W'))
                {
                    graf[pozycja].push_back(pozycja-szer);
                    graf[pozycja-szer].push_back(pozycja);
                }
            }
            if(tmp=='P') start=pozycja;
            if(tmp=='W') koniec=pozycja;
        }
    }
    /*for(i=0;i<=szer*dlu;i++)
    {
        for(int j : graf[i]) cout<<j<<' ';
        cout<<endl;
    }*/
    kolejki(start);
    if (odl[koniec]!=-1)cout<<odl[koniec];
    else cout<<"NIE";
    return 0;
}