#include <iostream>
#include <set>

using namespace std;

int main()
{
        int n, m;
        set<int> on;
        cin>>m>>n;
        on.insert(0);
        on.insert(m + 1);
        for(int tmp, i=0; i<n; i++) 
        {
                cin>>tmp;
                if (!on.count(tmp)) on.insert(tmp);
                else {
                        on.erase(tmp);
                        cout<<*on.upper_bound(tmp) - *--on.upper_bound(tmp) - 1<<endl;
                        //on.erase(tmp);
                }
        }
}
