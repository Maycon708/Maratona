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

#define N 5000

vector<int> adj[N];
bool vis[N];

int bfs( int ini, int fim ){
	queue<ii> q;
	q.push( ii( ini, 0 ) );
	while( !q.empty() ){
		int u = q.front().F;
		int d = q.front().S;
		q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		if( u == fim ) return d;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			q.push( ii( v, d+1 ) );
		}
	}
}

int main(){
	int n;
	string a, b;
	while( scanf("%d", &n ) != EOF ){
		map<string, int> mp;
		map<string, int> :: iterator it;
		int cnt = 0;
		rep( i, 0, N ) adj[i].clear(), vis[i] = 0;
		rep( i, 0, n ){
			cin >> a >> b;
			if( !mp.count(a) ) mp[a] = cnt++;
			if( !mp.count(b) ) mp[b] = cnt++;
			adj[mp[a]].pb( mp[b] );
		}
		int aux = 1, f, l;
		for( it = mp.begin(); it != mp.end(); it++ ){
			if(aux) f = l = it -> S;
			else{
				int u = it -> S;
				adj[l].pb(u);
				adj[u].pb(l);
				l = u;
			}
			aux = 0;
		}
		cin >> a >> b;
		printf("%d\n", bfs( mp[a], mp[b] ) );
	}
}

