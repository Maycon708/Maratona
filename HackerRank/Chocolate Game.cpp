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

ll chocolateGame( vector<int> v ){
	ll n = v.size();
	ll ans = 0, xr = 0;
	map<int, int> mp;
	mp[0] = 1;
	for( int i = n-1; i >= 0; i -= 2 ){
		int t = v[i];
		ans += mp[xr^t];
		if( i ) t -= v[i-1], ans += mp[xr^t];
		xr ^= t;
		mp[xr]++;
	}
	mp.clear();
	mp[0] = 1;
	xr = 0;
	for( int i = n-2; i >= 0; i -= 2 ){
		int t = v[i];
		ans += mp[xr^t];
		if( i ) t -= v[i-1], ans += mp[xr^t];
		xr ^= t;
		mp[xr]++;
	}
	return n * (n-1)/2 - ans;
}

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		vector<int> v(n);
		rep( i, 0, n ) scanf("%d", &v[i] );
		cout << chocolateGame(v) << endl;
	}
}
