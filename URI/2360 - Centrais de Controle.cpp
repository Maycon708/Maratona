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

#define N 1005

const int mod = 1e9+7;

vector<int> adj[N];

ll pd[N][N][3];
int memo[N][N][3], cnt;

ll solve( int u, int k, int p, int op ){
	if( k == adj[u].size() ) return op != 0;
	ll &ans = pd[u][k][op];
	int v = adj[u][k];
	if( memo[u][k][op] != cnt ){
	    memo[u][k][op] = cnt;
		if( v != p ){
			ans = ( solve( v, 0, u, 2 ) * solve( u, k+1, p, max(op, 1) ) )%mod;
			ans = ( ans + solve( v, 0, u, op == 2 ) * solve( u, k+1, p, op ) )%mod;
		}
		else ans = solve( u, k+1, p, op);
	}
	return ans;
}

int main(){
	int t, n, a, b;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n+1 ) adj[i].clear();
		rep( i, 1, n ){
			scanf("%d%d", &a, &b );
			adj[a].pb(b);
			adj[b].pb(a);
		}
		cnt++;
		printf("%lld\n", ( solve(1, 0, 0, 0) + solve(1, 0, 0, 2) )%mod );
	}
}
