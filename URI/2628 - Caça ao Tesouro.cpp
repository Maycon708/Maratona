#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 100010
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

bitset<N> prime;

void crivo(){
	prime.set();
	prime[0] = prime[1] = 0;
	for( int i = 2; i < N; ++i ){
		if( !prime[i] ) continue;
		for( int j = i+i; j < N; j += i ) prime[j] = 0;
	}
}


int n, dist[111][111], pd[110][1<<15];
vector<int> V;


int solve( int p, int mask, int cnt = 0 ){
	if(cnt == V.size() ) return dist[p][n];
	int &ans = pd[p][mask];
	if( ans == -1 ){
		ans = INF;
		rep( i, 0, V.size() ){
			if( (mask&(1<< i)) ) continue;
			ans = min( ans, dist[p][V[i]] + solve( V[i], mask | ( 1 << i ), cnt+1));
		}
	}
	return ans;
}


int main(){
	int m, u, v, d;
	crivo();
	while( scanf("%d%d", &n, &m ) != EOF ){
		V.clear();
		SET( dist, INF );
		dist[n][n] = 0;
		rep( i, 0, n ){
			scanf("%d", &v );
			if( prime[v] ) V.pb(i);
			dist[i][i] = 0;
			SET( pd[i], -1 );
		}
		SET( pd[n], -1 );
		while( m-- ){
			scanf("%d%d%d", &u, &v, &d );
			u--, v--;
			dist[u][v] = dist[v][u] = min( dist[u][v], d );
		}
		rep( k, 0, n+1 )
			rep( i, 0, n+1 )
				rep( j, 0, n+1 )
					dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
								
		printf("%d\n", solve( n, 0 ) );			
				
	}
}