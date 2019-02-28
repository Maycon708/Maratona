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

#define N 1000010

ll bit[N][2], n;

void update( int x, int y, int v ){
	for( int i = x; i <= n; i += ( i&-i ))
		bit[i][y] += v;
}

ll query( int x, int y ){
	ll sum = 0;
	for( int i = x; i > 0; i -= ( i&-i ))
		sum += bit[i][y];
	return sum;
}

int main(){
	while( scanf("%lld", &n ) != EOF ){
		ll aux, ans = 0;
		rep( i, 0, n+1 ) bit[i][0] = bit[i][1] = 0; 
		rep( i, 0, n ){
			scanf("%lld", &aux );
			aux = ( n - aux + 1 );
			ans += query( aux, 1 );
			update( aux, 1, query( aux, 0 ) );
			update( aux, 0, 1 );
		}
		printf("%lld\n", ans );
	}
}

