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

#define N 100010

map<string, int> mp;
int cnt, tam[N];
int sub[N], vis[N], vis2[N];
int ans, n;
vector<int> adj[N];

int mapeia( string& s ){
	if( !mp.count(s) ){
		mp[s] = cnt;
		tam[cnt] = s.size() + 1;
		cnt++;
	}
	return mp[s];
}

void quebra( string s ){
	int ini = 0, last = 0;
	rep( i, 0, s.size() ){
		if( s[i] != '/' ) continue;
		string aux = s.substr( ini, i - ini );
		int u = mapeia(aux);
		ini = i+1;
		adj[last].pb(u);
		last = u;
	}
	sub[last]++;
}

void dfs( int u ){
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( vis[v] ) continue;
		dfs(v);
		vis[v] = 1;
		sub[u] += sub[v];
	}
}

void solve( int u, int aux ){
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( vis2[v] ) continue;
		int cost = aux - ( tam[v] * sub[v] ) + 3 * ( n - sub[v] );
		ans = min( ans, cost );
		solve( v, cost );
		vis2[v] = 1;
	}
}

int main(){
	char s[N];
	while( scanf("%d", &n ) != EOF ){
		mp.clear(), cnt = 1;
		int T = 0;
		rep( i, 0, n ){
			scanf("%s", s );
			T += strlen(s);
			quebra(s);
		}
		dfs(0);
		ans = T;
		solve( 0, T );
		printf("%d\n", ans );
	}
}

