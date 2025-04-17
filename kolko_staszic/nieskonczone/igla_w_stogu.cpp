#include <iostream>
#include <string>
#include<vector>

using namespace std;

int tab[200000], mps[200000];
int i;

int find(int s, int pi, string n)
{
	if(s==0) return 0;
	if(n[pi]==n[tab[s-1]] and pi-tab[s-1]>tab[s-1]) return tab[s-1]+1;
	else return find(mps[s-1],pi,n);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout<<'7';
	vector <int> odp;
	string n,a;
	int c,l=0,s;
	cin>>a>>n;
	n=a+'$'+n;
	c=n.size();
	s=a.size();
	//cout<<'!';
	//tab[0]=0;
	for(i=0;i<c;i++)
	{
		tab[i]=find(i,i,n);
		mps[i]=max(tab[i],mps[i-1]);
		//cout<<tab[i]<<' ';
		if(tab[i]==s){
			l++;
			odp.push_back(i-s-2);
		}
	}
	cout<<l<<endl;
	for(i=0;i<odp.size();i++) cout<<odp[i]<<' ';
	return 0;
}