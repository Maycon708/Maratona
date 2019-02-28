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

int main(){
	ll n, m;
	while( cin >> n >> m ){
		vector<ll> d(n), p(n);
		rep( i, 0, n ){
			cin >> d[i];
			d[i] *= d[i];
			p[i] = n - i;
		}
		ll cnt = 0, x, y, far = d[n-1];
		while( m-- ){
			cin >> x >> y;
			ll u = x * x + y * y;
			if( u > far ) continue;
			ll i = lower_bound( all(d), u ) - d.begin();
			cnt += p[i];
		}
		printf("%lld\n", cnt );
	}
}

