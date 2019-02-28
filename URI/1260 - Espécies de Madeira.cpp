#include<bits/stdc++.h>
   
using namespace std;

map<string, double> mp;

int main(){
	
	cout<<fixed<<setprecision(4);
	
	int n;
	char c[100];
	string v[10000];
	
	cin >> n;
	cin.ignore();
	cin.ignore();
	for(int j=0; j<n; j++){
		if(j!=0)cout<<endl;
		int i=0, cont=0;
		while(gets(c) && c[0]!='\0'){
			if(mp[c]==0){
				v[i]=c;
				i++;
			}
			mp[c]++;
			cont++;
		}
		
		sort(v, v+i);
		for(int k=0; k<i; k++)
		cout<< v[k] << " " << mp[v[k]]/cont*100 << endl;
		mp.clear();
	}
	return 0;
}

