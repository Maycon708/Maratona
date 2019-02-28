#include<bits/stdc++.h>
  
using namespace std;

vector<int> v1;
vector<vector<int> > servers, apps;

bool cmp(vector<int> a, vector<int> b){
	for(int i=0; i<a.size(); i++){
		if(binary_search(b.begin(), b.end(), a[i])) return true;
	}
	return false;
}

map < string, int> mp;
 
int main(){
 
 	int n, m, aux, k;
 	string a;
 	
	while(cin >> n >> m && n+m){
		k=1;
		while(n--){
			cin >> aux;
			while(aux--){
				cin >> a;
				if(!mp[a]){
					mp[a] = k;
					k++;
				}
				v1.push_back(mp[a]);
			}
			sort(v1.begin(), v1.end());
			servers.push_back(v1);
			v1.clear();
		}
		
		while(m--){
			cin >> aux;
			while(aux--){
				cin >> a;
				if(!mp[a]){
					mp[a] = k;
					k++;
				}
				v1.push_back(mp[a]);
			}
			sort(v1.begin(), v1.end());
			apps.push_back(v1);
			v1.clear();
		}
		
		int cont = 0;	
		//cout << servers.size() << " " << apps.size() << endl;
		for(int i=0; i<servers.size(); i++){
			for(int j=0; j<apps.size(); j++){
				//cout << i <<" " << j << endl;
				//system("pause");
				if(cmp(servers[i], apps[j])) cont++;
			}
		}
		
		servers.clear();
		apps.clear();
		mp.clear();
		cout << cont << endl;
		//cout <<endl << "SAIDA : " <<endl << cont << endl<<endl;
	}
	     
    return 0;
}
