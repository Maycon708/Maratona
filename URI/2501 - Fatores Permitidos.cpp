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

	ll n, m, p[111], f[111];
	
	while( scanf("%lld%lld", &n, &m ) != EOF && n){
		rep( i, 0, n ) scanf("%lld", &f[i] ), p[i] = 0;
		vector<ll> v( 1, 1 );
		while( v.size() != m+1 ){
			ll menor = 1ULL << 63 -1, pos;
			rep( i, 0, n ){
				if( f[i] * v[p[i]] < menor ){
					menor = f[i] * v[p[i]];
					pos = i;
				}
			}
			v.pb(menor);
			rep( i, 0, n ) if( f[i] * v[p[i]] == menor ) p[i]++;
		}
		printf("%lld\n", v[m] );
		
	}

}
