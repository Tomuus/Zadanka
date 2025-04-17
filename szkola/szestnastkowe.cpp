#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string a;
    int i;
    cin>>a;
    i=stoi(a, nullptr, 16);
    cout<<i<<endl<<static_cast<char>(i);
}