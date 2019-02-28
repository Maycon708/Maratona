#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

bool vis[10001];
vector <int> adj[10001];
vector <string> v;
map<int, string> mp1;
int g;

void bfs(int ini){
	
	queue <ii> q;
	
	q.push(ii(ini,0));
	vis[ini] = true;
	
	while(!q.empty()){
		
//		cout << "ha" << endl;
		
		int u = q.front().F;
		int c = q.front().S;
		q.pop();
		
		if(c==g) return;
		
		rep(i, 0, adj[u].size()){
			
			int w = adj[u][i];
			
			if(!vis[w]){
				vis[w] = true;
				q.push(ii(w, c+1));
				v.pb(mp1[w]);
			}
			
		}
		
	}
	return;
}

int main(){

	string n1, n2;
	map<string, int> mp;
	
	int n;

	while(scanf("%d%d", &n, &g) != EOF){
		
		int k = 0;
		
		rep(i,0,10001){
			adj[i].clear();
			vis[i] = false;
		}
		
		rep(i,0,n){
			
			cin >> n1 >> n2;
			
			if(!mp.count(n1)){
				mp1[k] = n1;
				mp[n1] = k++;
			}
			if(!mp.count(n2)){
				mp1[k] = n2;
				mp[n2] = k++;
			}
			
			adj[mp[n1]].pb(mp[n2]);
			adj[mp[n2]].pb(mp[n1]);
			
		}
		
		bfs( mp["Rerisson"]);
		
		sort(all(v));
		
		int tam = v.size();
		printf("%d\n", tam);
		rep(i, 0, tam) cout << v[i] << endl;
		
		mp.clear();
		mp1.clear();
		v.clear();
		
	}

	return 0;
}

