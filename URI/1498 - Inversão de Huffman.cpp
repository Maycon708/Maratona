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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	
	ll n, a, cnt[55], mx;
	vector<ll> v[55];
	
	while( scanf("%lld", &n ) != EOF ){
		rep( i, 0, 55 ) v[i].clear(), cnt[i] = 0;
		mx = 0;
		rep( i, 0, n ){
			scanf("%lld", &a );
			cnt[a]++;
			mx = max( mx, a );
		}
		ll ans = 0, gt = 1;
		for( int i = mx; i > 0; i-- ){
			rep( j, 0, cnt[i] ) v[i].pb(gt), ans += gt;
			for( int j = 0; j < v[i].size(); j+=2 ){
				v[i-1].pb( v[i][j] + v[i][j+1] );
				gt = max( gt, max( v[i][j], v[i][j+1] ));
			}
		}
		cout << v[0][0] << endl;
	} 
	
}
