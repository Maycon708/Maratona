#include<bits/stdc++.h>
   
using namespace std;

map<string, int> mp;

int main(){
	char c[100];
	int n, m, aux;
	cin>>m >> n;
	
	while(m--){
		cin>>c;
		cin>>mp[c];
	}
	while(n--){
		int t=0;
		while(cin>>c && c[0]!='.'){
			t+=mp[c];
		}
		cout<<t<<endl;
	}
	
	return 0;
}
