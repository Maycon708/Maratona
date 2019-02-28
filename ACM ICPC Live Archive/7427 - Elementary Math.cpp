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
#define N 10010

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

vector<ll> adj[N];
map<ll, ll> match;
map<ll, bool> vis;

int aug( int v ){
	if( vis[v] ) return 0;
	vis[v] = true;
	int tam = adj[v].size();
	rep( j, 0, tam ){
		ll r = adj[v][j];
		if( !match.count(r) || aug(match[r])){
			match[r] = v;
			return 1;
		}
	}
	return 0;
}

int main(){
	ll n, a[N], b[N];
	while( scanf("%lld", &n ) != EOF ){
		match.clear();
		rep( i, 0, n ){
			scanf("%lld%lld", &a[i], &b[i] );
			adj[i].clear();
			adj[i].pb(a[i]+b[i]);
			adj[i].pb(a[i]-b[i]);
			adj[i].pb(a[i]*b[i]);
		}
		int mcbm = 0;
		rep( i, 0, n ){
			vis.clear();
			mcbm += aug(i);
		}
		if( mcbm != n ) puts("impossible");
		else{
			rep( i, 0, n ){
				if( match[a[i] + b[i]] == i ) printf("%lld + %lld = %lld\n", a[i], b[i], a[i]+b[i] );
				else if( match[a[i] - b[i]] == i ) printf("%lld - %lld = %lld\n", a[i], b[i], a[i]-b[i] );
				else if( match[a[i] * b[i]] == i ) printf("%lld * %lld = %lld\n", a[i], b[i], a[i]*b[i] );
			}
		}
	}
}
