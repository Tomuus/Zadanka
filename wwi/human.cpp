#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp (string a, string b)
{
       return a+b < b+a;
}

int main()
{
        int n;
        cin>>n;
        vector<string> v;
        for (int i=0; i<n; i++)
        {
                string tmp;
                cin>>tmp;
                v.push_back(tmp);
        }
        sort(v.begin(), v.end(), cmp);
        for(auto i : v) cout<<i;
}
