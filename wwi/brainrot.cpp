//SKIBIDI
//Tresc zadania jest najbardziej sigmastyczna na swiecie, widac ze tworca to alpha male

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

using namespace std;
typedef vector<vector<int>> vii;

vector <int> graf [100'007];
vii odl (200,  vector<int> (100007));

void bfs (int n, int s){
        bool visited[100'007];
        fill(visited, visited+100'007, false);
        visited[s] = true;
        queue<int> q;
        q.push(s);
        odl[n][s]=0;
        while (!q.empty())
        {
                for (auto i: graf[q.front()]) { if(!visited[i]){
                        odl[n][i] = odl[n][q.front()] +1;
                        visited[i] = true;
                        q.push(i);
                }}
                q.pop();
        }
        return;
}

int main()
{
        mt19937 rand(6922113377420); //Skibidi seed
        int n, m, q;
        cin>>n>>m>>q;
        for (int a, b, i=0; i<m; i++){
                cin>>a>>b;
                graf[a].push_back(b);
                graf[b].push_back(a);
        }
        for (int i=0; i<200; i++) bfs(i, rand()%n + 1);

        for (int a, b, i=0; i<q; i++){
                cin>>a>>b;
                int ans = 200'000;
                for (int j=0; j<200; j++) ans = min(ans, odl[j][a]+odl[j][b]);
                cout<<ans<<endl;
        }
}
