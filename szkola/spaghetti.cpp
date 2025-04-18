#include <iostream>
#include <cstdio>

using namespace std;

int mapka[1002][1002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y,ilosc=0,i,j,kratka_p=0,x1,y1,x2,y2;
    cin>>y>>x>>ilosc;
    for(i=0;i<ilosc;i++){
        cin>>y1>>x1>>y2>>x2;
        mapka[x1][y1] += 1;
        mapka[x2+1][y1] -= 1;
        mapka[x1][y2+1] -= 1;
        mapka[x2+1][y2+1] += 1;
    }
    //cout<<endl;
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++) mapka[i][j]+=mapka[i][j-1];
    }
    for(i=1;i<=y;i++)
    {
        for(j=1;j<=x;j++)
        {
            mapka[j][i]+=mapka[j-1][i];
            printf("%d",mapka[j][i]);
            printf(" ");
        }
        printf("\n");
    }
}
