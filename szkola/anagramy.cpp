#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a,b;
    cin>>a>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for (int i=0; i<a.size(); i++) {
        if(a[i]!=b[i]){
            cout<<"NIE";
            return 0;
        }
    }
    cout<<"TAK";
    return 0;
}