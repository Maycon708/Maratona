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

#define N 101010

vector<int> adj[N];
int aux;

int dfs( int u ){
	int last, atual, t = 1;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		atual = dfs(v);
		if( !i ) last = atual;
		else if( last != atual ) aux = 0;
		t += atual; 
	}
	return t;
}

int main(){
	
	int n, u, v;
	while( scanf("%d", &n ) != EOF ){
		
		rep( i, 0, n+1 ) adj[i].clear();
		
		rep( i, 0, n ){
			scanf("%d%d", &u, &v );
			adj[v].pb(u);
		}
		aux = 1;
		dfs(0);
		if( aux ) puts("bem");
		else puts("mal");
	}
}

