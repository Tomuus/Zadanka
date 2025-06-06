//dobra to chya bylo mocno zmarnowane 30 minut

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace::std;

priority_queue<tuple<long long,long long,long long, long long>, vector<tuple<long long,long long,long long, long long>>, greater<tuple<long long,long,long long, long long>>> td;
//debugowanie tej linijki bedzie craaaaazy  ^
vector <long long> graf[1002004];
long long odl[1002004];
long long visited[1002004]; //tbh to mam pomysl zeby to trzymalo energie bo wyjdzie lepiej
long long status[700000];

void kolejki (long long p,long long n,long long m,long long e)
{
    visited[p]=1;
    odl[p]=0;
    td.push({0,status[p],p,e});
    while(!td.empty())
    {
        //dobra jutro o tym zapomne przyda sie dokumentacja
        long long l=get<0>(td.top()); //min wielkosc liny zeby tu sie dostac (po tym jest nasze pq)
        long long h=get<1>(td.top()); //wysokosc komina
        long long i=get<2>(td.top()); //numer komina
        long long p=get<3>(td.top()); //energia bo czemu nie
        td.pop();
        if(p>visited[i]) continue;
        visited[i]=1;
        if((i+1)%n!=0 and status[i+1]!=-1)
        {
            if(status[i+1]==0)
            {
                td.push({l,0,i+1,e});
                odl[i+1]=min(odl[i+1],l);
            }
            if(status[i+1]>h and p>0)
            {
                td.push({max(l,status[i+1]-h),status[i+1],i+1,p-1}); //bede jutro pamietal jak to dziala tak? ... tak?
                odl[i+1]=min(max(l,status[i+1]-h),odl[i+1]);
            }
            if(status[i+1]!=0 and status[i+1]<h)
            {
                td.push({l,status[i+1],i+1,e});
                odl[i+1]=min(odl[i+1],l);
            }
        }
        if(i+n<n*m and status[i+1]!=-1)
        {
            if(status[i+n]==0)
            {
                td.push({l,0,i+n,e});
                odl[i+n]=min(odl[n+1],l);
            }
            if(status[i+n]>h and p>0)
            {
                td.push({max(l,status[i+n]-h),status[i+n],i+n,p-1});
                odl[i+n]=min(odl[i+n],max(l,status[i+n]-h));
            }
            if(status[i+n]!=0 and status[i+n]<h)
            {
                td.push({l,status[i+n],i+n,e});
                odl[i+n]=min(odl[n+i],l);
            }
        }
        td.pop();
    }
    return;
}

int main()
{
    fill(odl, odl + 1002004, 696969696969); //lekki crashout i juz zaczynam sie zmieninac w staszicowego
    fill(visited, visited + 1002004, 0);
    fill(status,status+700000,-1);
    long long n,m,i,e;
    cin>>n>>m>>e;
    for(i=0;i<n*m;i++)
    {
        cin>>status[i];
    }
    kolejki(0,n,m,e);
    cout<<odl[n*m-1];
    return 0;
}
