#include<bits/stdc++.h>

#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;

const int MAXV = 110;
const int INF = 0x3f3f3f3f;

int m[MAXV][MAXV], V;
 
void floyd(){
    rep(k,0,V)
    	rep(i,0,V)
    		rep(j,0,V){
    			m[i][j] = min(m[i][j], max(m[i][k], m[k][j])); 
    }
}

vector<int> v;

int main(){
	
	int M, i, j, h, k, aux=1;
	
	while(cin >> V >> M && V+M){
		
		memset(m, INF, sizeof(m));
		
		while(M--){
			cin >> i >> j >> h;
			m[i-1][j-1] = h;
			m[j-1][i-1] = h;
		}
		
		floyd();
		
		cin >> k;
		while(k--){
			cin >> i >> j;
			if(i==j) v.push_back(0);
			else v.push_back(m[i-1][j-1]);
		}
		
		printf("Instancia %d\n", aux);
		aux++;
		rep(i, 0, v.size()){
			cout << v[i] << endl;
		}
		cout << endl;
		v.clear();
	}
	
}
