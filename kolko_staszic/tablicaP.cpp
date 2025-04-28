#include <iostream>
#include <string>

using namespace std;

int tab[200000];
int i;

/*int find(int s, int pi, string n)
{
	if(s==0) return 0;
	if(n[pi]==n[tab[s-1]]) return tab[s-1]+1;
	else return find(tab[s-1],pi,n);
}*/

int find (int s, int pi, string n)
{
	while(s>0)
	{
		if(n[pi]==n[tab[s-1]]) return tab[s-1]+1;
		s=tab[s-1];
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout<<'7';
	string n;
	int c;
	cin>>n;
	c=n.size();
	//cout<<'!';
	//tab[0]=0;
	for(i=0;i<c;i++)
	{
		tab[i]=find(i,i,n);
		cout<<tab[i]<<' ';
	}
	return 0;
}
