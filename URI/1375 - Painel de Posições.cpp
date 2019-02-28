#include<bits/stdc++.h>
  
using namespace std;
 
int main(){
	
	int n, c, p, v[1010];
	bool aux;
	
	while(cin >> n && n){
		aux = false;
		
		for(int i=1; i<=n; i++) v[i] = 0;
		
		for(int i=1; i<=n; i++){
			cin >> c >> p;
			if(i+p>0 && i+p<=n){
				if(v[i+p]==0){
					v[i+p] = c;
				}
				else aux = true;
			}
			else aux = true;
		}
		
		if(aux) cout << "-1" << endl;
		else{
			for(int i=1; i<=n; i++){
				if(i!=1) cout << " ";
				cout << v[i];
			}
			cout << endl;
		}
		
	}
	 
    return 0;
}
