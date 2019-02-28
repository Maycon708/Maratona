#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;

vector<int> vis[11][111];
int n, m, nxt[11][111], s[11];
ii eq[11][111];

void dfs( int i, int u, int t = 0 ){
	if( vis[i][u].size() == 2 ) return;
	vis[i][u].pb(t);	
	dfs( i, nxt[i][u], t+1 );
}

ll myGcd( ll a, ll b, ll &x, ll &y ){
	if( !a ){
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll c = myGcd( b%a, a, x1, y1 );
	y = x1;
	x = y1 - b/a * x1;
	return c;
}

ii solve( ii a, ii b ){
	if( a.F == -1 || b.F == -1 ) return ii(-1, -1);
	if( !a.S ) return ii((a.F-b.F)%b.S == 0 ? a.F : -1, 0);
	if( !b.S ) return ii((b.F-a.F)%a.S == 0 ? b.F : -1, 0);
	while( b.F+b.S < a.F ) b.F += b.S;
	ll c = b.F-a.F, x, y;
	ll gcd = myGcd( a.S, -b.S, x, y );
	if( c%gcd ) return ii( -1, -1 );
	ll xx = b.S/__gcd(a.S, b.S), yy = a.S/__gcd(a.S, b.S);
	x *= c/gcd; y *= c/gcd;
	while( x < 0 || y < 0 ) x += xx, y += yy;
	return ii( a.F+a.S*x, a.S/__gcd(a.S, b.S)*b.S );
}

int main(){
	
	scanf("%d%d", &n, &m );
	rep( i, 0, n ){
		scanf("%d", &s[i] );
		rep( j, 1, m+1 ) scanf("%d", &nxt[i][j] );
	}
	
	rep( i, 0, n ){
		dfs( i, s[i] );
		rep( j, 1, m+1 ){
			if( vis[i][j].empty() ) eq[i][j] = ii(-1, -1);
			else if( vis[i][j].size() == 1 ) eq[i][j] = ii( vis[i][j][0], 0 );
			else eq[i][j] = ii( vis[i][j][0], vis[i][j][1] - vis[i][j][0] );
		}
	}
	ll ans = -1, id;
	rep( i, 1, m+1 ){
		ii eqf = eq[0][i];
		rep( j, 1, n ){
			eqf = solve( eqf, eq[j][i] );
			if( eqf.F == -1 ) break;
		}
		if( eqf.F != -1 ){
			if( ans == -1 || ans < eqf.F ) ans = eqf.F, id = i;
		}
	}
	if( ans != -1 )
		cout << id << " " << ans << "\n";
	else
		puts("*");
}

