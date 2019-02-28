#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int N = 10010; // numero de elementos do conjunto base (arestas)

struct UnionFind { // estrutura union find para matroid grafico (florestas)
	int p[N], comp_sz[N];
	void clear( int m ){
		memset( p, -1, m * sizeof( int ) );
		memset( comp_sz, 0, m * sizeof( int ) );
	}
	int find( int x ) {
		while( p[x] != -1 ) x = p[x];	
		return x;
	}
	void union_set( int x, int y ) {
		int u = find(x), v = find(y);
		if( u != v ) {
			if ( comp_sz[u] < comp_sz[v] ){ 
				p[u] = v; comp_sz[v] += comp_sz[u]; 
			}
			else{ 
				p[v] = u; comp_sz[u] += comp_sz[v]; 
			}
		}
	}
};
UnionFind ufs;

int n, m, K;		// vertices, arestas, cores
int x[N], y[N]; 	// i-esima aresta = (x[i],y[i])
int maxcor[N]; 		// maxcor[i] - numero de vezes que a cor i pode ainda ser
int cor[N]; 		// cor[i] - cor da i-esima aresta
vector<int> g[N]; 	// grafo auxiliar
bool base[N]; 		// base[i] - se a i-esima aresta pertence ao conjunto
bool X1[N], X2[N]; 	// X1 = {x \in S \ I : {I + x} \in I1},
int Prev[N]; 		// para bfs que encontra caminho minimo em g de X1 para X2
bool vis[N];
int bfs() {
	rep( i, 0, m ) if( X1[i] && X2[i] ) return i;
	memset( Prev, -1, m * sizeof( int ) );
	memset( vis, false, m * sizeof( bool ) );
	queue<int> q;
	rep( i, 0, m )
		if( X1[i] ){
			q.push(i); 
			vis[i] = true; 
		}
	while( !q.empty() ){
		int u = q.front(); 
		q.pop();
		rep( j, 0, g[u].size() ) {
			int v = g[u][j];
			if( vis[v] ) continue;
			vis[v] = 1;
			Prev[v] = u;
			if( X2[v] ) return v;
			q.push(v); 
		}
	}
	return -1;
}
int matroid_intersection(){
	memset( base, false, m * sizeof( bool ) );
	int res;
	for( res = 0; true; res++ ){
		rep( i, 0, m ) g[i].clear(); 
		rep( i, 0, 1 ) 
			if( base[i] ){ 
				ufs.clear(n); 
				rep( j, 0, m ) if( base[j] && i != j ) ufs.union_set( x[j], y[j] );
				rep( j, 0, m ) if( !base[j] && ufs.find(x[j]) != ufs.find( y[j] )) g[i].pb(j);
				rep( j, 0, m ) if( !base[j] ){ 
					maxcor[cor[i]]++;
					if( maxcor[cor[j]] >= 1 ) g[j].pb(i);
					maxcor[cor[i]]--;
				}
			}
		ufs.clear(n);
		rep( i, 0, m ) if( base[i] ) ufs.union_set( x[i], y[i] );
		rep( i, 0, m ){ 
			X1[i] = X2[i] = false;
			if( !base[i] ){
				if( ufs.find(x[i]) != ufs.find(y[i]) ) X1[i] = true;
				if( maxcor[cor[i]] >= 1 ) X2[i] = true;  			
			}
		}
		int v = bfs(); 
		if( v == -1 ) break; 
		while( true ){
			maxcor[cor[v]] += ( base[v] ? 1 : -1 ); base[v] = !base[v];
			if( X1[v] ) break; v = Prev[v];
		}
	}
	return res;
}

int main(){
	int t = 1;
	while ( scanf("%d%d%d", &n, &m, &K ) != EOF ) {
		rep( i, 0, K ) maxcor[i] = 1; 
		rep( i, 0, m ){
			scanf("%d%d%d", &x[i], &y[i], &cor[i] );
			x[i]--; y[i]--; cor[i]--;
		}
		int res = matroid_intersection();
		
		printf( "Instancia %d\n", t++ );
		if( res == n-1 ) printf("sim\n");
		else printf("nao\n");
		printf("\n");
	}
}

