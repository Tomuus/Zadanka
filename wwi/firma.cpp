#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair <ll, int> para;

para sumrng (para tree[], int a, int b, int currLeft, int currRight, int root)
{
        if (a > currRight or b < currLeft) return 0;
        if (a <= currLeft and b >= currRight) return tree[root];
        int mid = (currLeft + currRight)/2;
        return sumrng(tree, a, b, currLeft, mid, root*2) + sumrng(tree, a, b, mid+1, currRight, root*2+1);
}

int main(){
        int n, leaf;
        cin>>n;
        while(leaf<n) leaf*=2;
        para tree[leaf*2];
        para hired[leaf*2];
        fill(hired, hired+ leaf*2, {0,0});
        for (ll tmp, i=0; i<n; i++) {
                cin>>tmp;
                tree[i+leaf] = {tmp, i};
        }
        for (int i = leaf - 1; i>0; i--) tree[i]=min(tree[i*2], tree[i*2 + 1]);
        int m;
        cin>>m;
        tuple<int, int, int, int> changes[m];
        for(int i=0; i<m; i++)
        {
                int a, b, count;
                changes[i]={b-a, a, b, count};
        }
        sort(changes, changes+m);
        vector <int> hired;
        for(auto [d,a,b,count]: changes)
        {
                count-=    
        }
}
