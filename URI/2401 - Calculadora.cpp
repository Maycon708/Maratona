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

ll eleva( ll b, ll e ){
	ll ans = 1;
	while( e ){
		if( e&1 ) ans *= b;
		b *= b;
		e >>= 1;
	}
	return ans;
}

int main(){
	int n, v, p[] = { 2, 3, 5, 7 };
	char op;
	while( cin >> n ){
		int cnt[] = { 0, 0, 0, 0 };
		rep( i, 0, n ){
			cin >> v >> op;
			rep( i, 0, 4 ){
				while( v%p[i] == 0 ){
					v /= p[i];
					cnt[i] += ( op == '*' ) ? 1 : -1;
				}
			}
		}
		ll ans = 1;
		rep( i, 0, 4 ) ans *= eleva( p[i], cnt[i] );
		printf("%lld\n", ans );
	}
}

