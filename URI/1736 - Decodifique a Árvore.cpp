#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

vector<int> adj[55];
bool vis[55];

void dfs( int u ){
	vis[u] = 1;
	printf("(%d", u );
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( vis[v] ) continue;
		printf(" ");
		dfs(v);
	}
	printf(")");
}

int main(){
	string s;
	while( getline( cin, s ) ){
		if( s == "" ){
			printf("(1)\n");
			continue;
		}
		rep( i, 0, 55 ){
			adj[i].clear();
			vis[i] = 0;
		}
		stringstream ss;
		vector<int> g(55, 1), u;
		ss << s;
		int aux;
		while( ss >> aux ){
			u.pb(aux);
			g[aux]++;
		}
		int n = u.size()+1;
		rep( i, 0, u.size() ){
			rep( j, 1, n+1 ){
				if( g[j] == 1 ){
					g[j]--;
					g[u[i]]--;
					adj[j].pb(u[i]);
					adj[u[i]].pb(j);
					break;
				}
			}
		}
		dfs(aux);
		printf("\n");
	}
}

