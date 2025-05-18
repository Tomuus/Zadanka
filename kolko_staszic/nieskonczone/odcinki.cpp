#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    int i,n;
    int a,b,c,d,e,f,g,h;
    int w,x,y,z;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d>>e>>f>>g>>h;
        w=abs(a-c);
        x=abs(b-d);
        y=abs(e-g);
        z=abs(f-h);
        if(w==0 and y==0) {cout<<"NIE"; continue;}
        if(x==0 and z==0) {cout<<"NIE"; continue;}
        if(w==0 and y!=0) {cout<<"TAK"; continue;}
        if(w!=0 and y==0) {cout<<"TAK"; continue;}
        if(x==0 and z!=0) {cout<<"TAK"; continue;}
        if(x!=0 and z==0) {cout<<"TAK"; continue;}
        cout<<w<<' '<<x<<' '<<y<<' '<<z;
        if((w%y==0 || y%w==0) and (z%x==0 || x%z==0)) cout<<"NIE";
        else cout<<"TAK";
        cout<<"\n";
    }
}
