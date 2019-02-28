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
#define wait system("PAUSE");

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define N 110

int flow[N][N];
int aux[N][N];
int pai[N]; 
int vis[N];
int votes[N];
int source, sink;
vector<int> adj[N];

bool bfs(){
	queue<int> q;
	q.push( source );
	rep( i, 0, N ){
		vis[i] = 0;
		pai[i] = -1;
	}
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			if( !flow[u][v] || vis[v] ) continue;
			pai[v] = u;
			q.push(v);
		}
	}
	return vis[sink];
}

int maxFlow(){
	memcpy( flow, aux, sizeof aux );
	int maxF = 0;
	while( bfs() ){
		int minF = 1 << 30;
		for( int u = sink; pai[u] != -1; u = pai[u] )
			minF = min( minF, flow[pai[u]][u] );
		
		for( int u = sink; pai[u] != -1; u = pai[u] )
			flow[pai[u]][u] -= minF,
			flow[u][pai[u]] += minF;
		maxF += minF;
	}
	return maxF;
}

int L( int u ){
	return u << 1;
}
int R( int u ){
	return 1 ^ L(u);
}

void addEdge( int u, int v, int cap = 1 ){
	aux[u][v] += cap;
	adj[u].pb(v);
	adj[v].pb(u);
}

void init(){
	source = 0, sink = 1;
	rep( i, 0, N ){
		adj[i].clear();
		votes[i] = 0;
		memset( aux[i], 0, sizeof aux[i] );
	}
}

int main(){
	int n, a[N], b[N];
	while( scanf("%d", &n ) != EOF ){
		init();
		rep( i, 1, n+1 ){
			addEdge( source, L(i) );
			addEdge( R(i), sink );
		}
		rep( i, 1, n+1 ){
			scanf("%d%d", &a[i], &b[i] );
			addEdge( L(i), R(a[i]) );
			addEdge( L(i), R(b[i]) );
			votes[a[i]]++, votes[b[i]]++;
		}
		int cnt = 0;
		for( int i = 1; i <= n; i++ ){
			if( votes[i] <= 1 ){
				cnt++;
				continue;
			}
			rep( j, 1, n+1 ){
				aux[R(j)][sink] = votes[i]-1;
			}
			aux[R(a[i])][sink]--;
			aux[R(b[i])][sink]--;
			aux[R(i)][sink] = votes[i];
			aux[source][L(i)] = 0;
			
			int ans = maxFlow();
			if( ans != n-1 ) cnt++;
			aux[source][L(i)] = 1;
		}
		printf("%d\n", cnt );
	}
}

