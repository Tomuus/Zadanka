#include <iostream>

using namespace std;

typedef long long ll; 

//ll leaf = 1;
//bool tree[(1<<21)+2]; //Nah robimy bez globalnych

//Dobra kod wyszedl kinda clean jak zmienne nie sa 1 literowe

void apdejt(bool tree[], ll leaf, int a, int b, ll currLeft, ll currRight, ll root) //Shit juz zaluje
{
        if(currLeft > b or currRight < a) return;
        if(currLeft >= a and currRight <= b) {tree[root] = !tree[root]; return;}
        ll mid = (currRight +currLeft) / 2;
        apdejt(tree, leaf, a, b, currLeft, mid, root * 2);
        apdejt(tree, leaf, a, b, mid+1, currRight, root * 2 + 1);
}

bool val (bool tree[], ll leaf, ll index) 
{
        index += leaf;
        bool ans = false;
        for(; index; index /= 2) if(tree[index]) ans=!ans;
        return ans;
}

int main (){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n, m;
        cin>>n>>m;
        ll leaf = 1;
        while (leaf<n) leaf*=2;
        bool tree[leaf * 2];
        fill (tree, tree + (leaf * 2), false);
        for (int i=0; i<n; i++) {
                char tmp; 
                cin>>tmp;
                if(tmp == 'o') tree[leaf + i] = true;
        }
        for (int i=0; i<m; i++)
        {
                char tmp;
                cin>>tmp;
                if (tmp == 'Q') {
                        int index;
                        cin>>index;
                        if(val(tree, leaf, index-1)) cout<<"ON"<<endl;
                        else cout<<"OFF"<<endl;
                }
                else {
                        int a, b;
                        cin>>a>>b;
                        apdejt(tree, leaf, a-1, b-1, 0, leaf-1, 1);
                }
        }
}
