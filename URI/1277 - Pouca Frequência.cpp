#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int t, n;
	char e[100][100], f[100][100];
	
	cin >> t;
	
	while(t--){
		bool aux=false;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> e[i];
		}
		for(int i=0;i<n;i++){
			cin >> f[i];
			int cont=strlen(f[i]), cont2=0;
			for(int j=0; j<strlen(f[i]);j++){
				if(f[i][j]=='M') cont--;
				if(f[i][j]=='A') cont2++;
			}
			if(cont2>cont/4){
				if(aux){
					cout << " ";
				}
				else aux=true;
				cout << e[i];
			}
		}
		cout << endl;
		
	}
	return 0;
}
