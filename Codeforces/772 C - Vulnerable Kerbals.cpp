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

ll fastExp( ll b, ll e, ll mod ){
	ll ans = 1;
	while( e ){
		if( e&1 ) ans = ( ans * b )%mod;
		b = ( b * b )%mod;
		e >>= 1;
	}
	return ans;
}

int n, m, cant[200200];
vector<int> ans, v[200200];
int nxt[200200], g[200200];

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
	if( b == 0 ){
		x = 1; y = 0;
		return a;
	}
	else{
		ll r = extend_gcd(b, a % b, y, x);
		y -= x * (a / b);
		return r;
	}
}

void dfs( int u, int last ){
	
	if( !u ) return;
	rep( i, 0, v[u].size() ){
		ll x, y;
		int k = extend_gcd( last, m, x, y );
		int aux = ((x*v[u][i]/k)%(m/k) + m/k )%m;
		ans.pb(aux);
		last = v[u][i];
	}
	
	dfs( nxt[u], last );
}


int main(){
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ){
			int x;
			scanf("%d", &x );
			cant[x] = 1;
		}
		rep( i, 1, m ){
			if( cant[i] ) continue;
			int k = __gcd(i, m);
			v[k].pb(i);
		}
		int best = 0, id = 0;
		for( int i = m-1; i > 0; i-- ){
			g[i] = 0;
			for( int j = i+i; j < m; j += i ){
				if( g[j] > g[i] ){
					g[i] = g[j];
					nxt[i] = j;
				}
			}
			g[i] += v[i].size();
			if( g[i] > best ){
				best = g[i];
				id = i;
			}
		}
		dfs( id, 1 );
		if( !cant[0] ) ans.pb(0);
		printf("%d\n", ans.size() );
		rep( i, 0, ans.size() ) printf("%d%c", ans[i], i+1 == ans.size() ? '\n':' ' );
	}
}
