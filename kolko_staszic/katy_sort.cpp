#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define ld (long double)

int main()
{
    long long n,i,x,y;
    cin>>n;
    pair <long long, long long> pkt={9200000000000000000,9200000000000000000};
    vector <tuple<long double, long long, long long>> punkty;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        if((x<pkt.first) or (x==pkt.first and y<pkt.second)) pkt={x,y};
        punkty.push_back({0,x,y});
    }
    for(i=0;i<n;i++)
    {
        if(get<1>(punkty[i])==pkt.first and get<2>(punkty[i])==pkt.second) {get<0>(punkty[i])=-9200000000000000000; continue;}
        get<0>(punkty[i])=ld(get<2>(punkty[i])-pkt.second)/ld(get<1>(punkty[i])-pkt.first);
    }
    sort(punkty.begin(),punkty.end());
    for(auto [a,x,y]: punkty) cout<<x<<' '<<y<<endl;
}
