#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int n, m, ans, cor[1000];
vector<int> adj[1000];

void addEdge( int u, int v ){
	adj[u].pb(v);
	adj[v].pb(u);
}

inline bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool bfs( int n ){
	queue<int> q;
	q.push(0); cor[0] = 0;
	bool bipartido = true;
	while(!q.empty() && bipartido){
		int u = q.front(); q.pop();
		int tam = adj[u].size();
		rep(i,0,tam){
			int v = adj[u][i];
			if(cor[v] == -1){
				cor[v] = 1 - cor[u];
				q.push(v);
			}
			else if(cor[v] == cor[u])
				return false;
		}
	}
	int cnt = 0;
	rep( i, 0, n ) cnt += cor[i];
	return 2*cnt == n;
}

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main(){
	char mat[22][22];
	ii aux[22][22];
	while( scanf("%d%d",&n, &m ) != EOF ){
		rep( i, 0, n ) scanf("%s", mat[i] );
		int cnt = 0;
		rep( i, 0, n ){
			rep( j, 0, m ){ 
				if( mat[i][j] == 'o' ) aux[i][j] = ii( cnt++, -1 );
				else{
					aux[i][j] = ii( cnt++, cnt++ );
					addEdge( aux[i][j].F, aux[i][j].S );
				}
			}
		}
		if( n == 1 && m == 1 ){
			puts("N");
			continue;
		}
		rep( i, 0, cnt ) adj[i].clear(), cor[i] = -1;
		rep( i, 0, n ){
			rep( j, 0, m ){
				rep( k, 0, 4 ){
					int x = i + dx[k], y = j + dy[k];
					if( dentro(x, y) ){
						addEdge( aux[i][j].F, aux[x][y].F);
						if( aux[x][y].S != -1 )
							addEdge( aux[i][j].F, aux[x][y].S);
						if( aux[i][j].S != -1 ){
							addEdge( aux[i][j].S, aux[x][y].F);
							if( aux[x][y].S != -1 )
								addEdge( aux[i][j].S, aux[x][y].S);
						}
					}
				}
			}
		}
		puts(bfs(cnt)?"Y":"N");
	}
}
