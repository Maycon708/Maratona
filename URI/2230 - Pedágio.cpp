#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define MAXV 51

using namespace std;

typedef vector<int> vec;

vec adj[MAXV];
int vis[MAXV];
int N, C;

void bfs( int ini ){
	queue < int > q;
	q.push( ini );
	vis[ini] = 0;
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		if( vis[u] == C ) continue;
		int t = adj[u].size();
		for( register int i = t; i > 0; i-- ){
			int v = adj[u][t-i];
			if( vis[v] != -1 ) continue;
			vis[v] = vis[u]+1;
			q.push( v );
		}
	}
	rep( i, 1, N+1 ){
		if( vis[i] > 0 && vis[i] <= C ) printf("%d ", i );
	}
}

#define gc getchar_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ); c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int main(){

	int ini, m, t = 1, a, b;
	while( 42 ){
		scan(N), scan(m), scan(ini), scan(C);
		if( !N ) break;
		
		for( register int i = N; i > 0; i-- )
			vis[i] = -1, adj[i].clear();
		
		for( register int i = m; i > 0; i-- ){
			scan(a), scan(b);
			adj[a].pb( b );
			adj[b].pb( a );
		}
		printf("Teste %d\n", t++ );
		bfs( ini );
		printf("\n\n");
	}

}


