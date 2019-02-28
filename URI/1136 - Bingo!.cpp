#include<iostream>
#include<cmath>
#include<map>

using namespace std;

int main(){
	map<int,bool> mp;
	
	int n, b, v[100];
	bool aux;
	
	cin >> n >> b;
	
	while(n && b){
		aux=true;
		for(int i=0; i<b; i++){
			cin>> v[i];
		}
		
		for(int i=0; i<b; i++){
			for(int j=i+1; j<b; j++){
				int k=abs(v[i]-v[j]);
				mp[k]=true;
			}
		}
		
		for(int i=1; i<=n; i++){
			if(!mp[i]) aux=false;
		}
		
		if(aux) cout << "Y" << endl;
		else cout << "N" << endl;
		mp.clear();
		cin>> n >>b;
	}
	return 0;
}
