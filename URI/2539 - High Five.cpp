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

#define N 100010

ll bit[N], n;

void update( int x, int v = 1 ){
	for( int i = x; i <= n; i += ( i&-i ))
		bit[i] += v;
}

ll query( int x ){
	ll sum = 0;
	for( int i = x; i > 0; i -= ( i&-i ))
		sum += bit[i];
	return sum;
}

int main(){
	int a;
	while( scanf("%lld", &n ) != EOF ){
		rep( i, 0, n+1 ) bit[i] = 0;
		ll ans = 0;
		rep( i, 0, n ){
			scanf("%d", &a );
			ans += query(a);
			update(a);
		}
		printf("%lld\n", ans );
	}
}
