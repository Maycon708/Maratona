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

struct sede{
	int p, m, t, id;
	void scan( int i ){
		scanf("%d%d%d", &p, &m, &t );
		id = i+1;
	}
	bool operator < ( sede A ) const{
		if( m != A.m ) return m > A.m;
		if( t != A.t ) return t > A.t;
		return p < A.p;
	}
};

sede v[N];
int l, s, q, a, best[N];
vector<int> adj[N];
	
void bfs(){
	queue<ii> q;
	rep( i, 0, s ) q.push( ii( v[i].p, v[i].id ) );
	while( !q.empty() ){
		int u = q.front().F;
		int v = q.front().S;
		q.pop();
		if( best[u] != -1 ) continue;
		best[u] = v;
		rep( i, 0, adj[u].size() ){
			int w = adj[u][i];
			q.push( ii( w, v ) ); 
		}
	}
}

void addEdge(){
	int u, v;
	scanf("%d%d", &u, &v );
	adj[u].pb(v);
	adj[v].pb(u);
}

void init(){
	rep( i, 0, l+1 ){
		adj[i].clear();
		best[i] = -1;
	}
}

int main(){
	
	while( scanf("%d%d%d%d", &l, &s, &q, &a ) != EOF ){
		init();
		rep( i, 0, s ) v[i].scan(i);
		sort( v, v+s );
		while( a-- ) addEdge();
		bfs();
		rep( i, 0, q ){
			scanf("%d", &a );
			if( best[a] != -1 ) printf("%d\n", best[a] );
			else printf("Noic\n");
		}
	}
	
}
