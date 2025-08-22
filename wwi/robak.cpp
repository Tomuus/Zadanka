#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue <pair <long long, long long>> q;
vector <int> graf[250007];
vector <long long> h;
bool visited[100007];
long long mxg=1e9+5;
int goal;
long long ml = 1e9+5;

void kolejki(long long s)
{
    long long mx=-1;
    visited[s]=1;
    q.push({h[s],s});
    mxg=h[s];
    int prev = mxg;
    while(!q.empty())
    {
        long long i=q.top().second;
        //cout<<i<<'h'<<h[i]<<' ';
        //if (mxg>h[i] and ml>=h[i])
        //{
        //        mxg = ml;
        //        ml = h[i];
        //}
        if (i == goal) return;
        q.pop();
        for(auto j:graf[i])
        {
            if(visited[j]) continue;
            visited[j]=1;
            //cout<<"add:"<<j<<'w'<<h[j]<<' ';
            q.push({h[j],j});
        }
    }
    mxg=-1;
    return;
}

int main ()
{
        int x, y, bx, by, px, py;
        cin>>x>>y;
        cin>>bx>>by>>px>>py;
        goal=((py-1)*x)+px-1;
        for(int i=0; i<y; i++)
        {
                //cout<<'s';
                for(int j=0; j<x; j++)
                {
                        //cout<<'w';
                        int w;
                        cin>>w;
                        h.push_back(w);
                        if(j+1<x) { graf[(x*i)+j].push_back((x*i)+j+1); graf[(x*i)+j+1].push_back((x*i)+j); }
                        if(i+1<y) { graf[(x*i)+j].push_back((x*i)+x+j); graf[(x*i)+x+j].push_back((x*i)+j); }
                        //cout<<'p'<<h[(x*i)+j]<<' ';

                }
        }
        //cout<<'!'<<h[3];
        kolejki((x*(by-1))+bx-1);
        cout<<mxg;
}
