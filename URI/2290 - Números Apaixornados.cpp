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
	int n, u;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		vector<ll> v( n, 0 ), ans;
		rep( i, 0, n ) scanf("%lld", &v[i] );
		sort( all(v) );
		ll last = 1 << 30, cnt = 0;
		rep( i, 0, n ){
			if( v[i] == last ) cnt++;
			else{
				if( cnt&1 ) ans.pb(last);
				last = v[i], cnt = 1;
			}
		}
		if( cnt&1 ) ans.pb(last);
		ans.pb(0), ans.pb(0);
		printf("%lld %lld\n", ans[0], ans[1] );
	}
}

