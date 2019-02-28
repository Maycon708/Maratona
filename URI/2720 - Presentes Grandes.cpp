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

bool cmp( ii a, ii b ){
	if( a.F != b.F ) return a.F > b.F;
	return a.S < b.S;
}

int main(){
	
	ll t, n, k, id, l, h, d;
	ii v[100010];
	
	cin >> t;
	while( t-- ){
		scanf("%lld%lld", &n, &k );
		rep( i, 0, n ) {
			scanf("%lld%lld", &id, &l );
			scanf("%lld%lld", &h, &d );
			v[i] = ii( l*h*d, id );
		}
		sort( v, v+n, cmp );
		vector<ll> ans;
		rep( i, 0, k ) ans.pb(v[i].S);
		sort(all(ans));
		rep( i, 0, k ) printf("%lld%s", ans[i], (i+1==k)? "\n" : " " );
	}
	
}


