#include<iostream>
#include <string>

using namespace::std;

int tabn[26],tabm[26];

int main()
{
    string n,m;
    cin>>n>>m;
    int i=0,w=0;
    for(i=0;i<n.length();i++) tabn[n[i]-'a']++;
    for(i=0;i<m.length();i++) tabm[m[i]-'a']++;
    for(i=0;i<26;i++) w+=min(tabn[i],tabm[i]);
    cout<<w;
}
