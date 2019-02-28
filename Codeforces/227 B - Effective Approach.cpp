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
	ll n, q, local[100100], a, b, c;
	while( scanf("%lld", &n ) != EOF ){
		rep( i, 0, n ){
			scanf("%lld", &a );
			local[a] = i;
		}
		a = b = 0;
		scanf("%lld", &q );
		while( q-- ){
			scanf("%lld", &c );
			a += local[c] + 1;
			b += ( n - local[c] );
		}
		printf("%lld %lld\n", a, b );
	}
}

