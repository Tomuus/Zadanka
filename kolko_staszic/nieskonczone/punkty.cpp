#include<iostream>

using namespace::std;

void sort (int tab[][3], int n)
{
    bool flag=true;
    while(flag)
    {
        flag=false;
        for (int i = 0; i < n - 1; i++)
        {
            if (tab[i][0] > tab[i + 1][0] ||
                (tab[i][0] == tab[i + 1][0] && tab[i][1] > tab[i + 1][1]) ||
                (tab[i][0] == tab[i + 1][0] && tab[i][1] == tab[i + 1][1] && tab[i][2] > tab[i + 1][2]))
            {
                for (int j = 0; j < 3; j++)
                {
                    swap(tab[i][j], tab[i + 1][j]);
                }
                flag = true;
            }
        }
    }
    return;
}

int main()
{
    int n,i;
    cin>>n;
    int tab[n][3];
    for(i=0;i<n;i++) cin>>tab[i][0]>>tab[i][1]>>tab[i][2];
    sort(tab,n);
    for(i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<tab[i][j]<<' ';
        }
        cout<<endl;
    }
}