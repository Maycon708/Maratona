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

int main(){
	
	ll n, k, v;
	
	while( scanf("%lld%lld", &n, &k ) != EOF ){
		ll left = n, t = 0, id = 1;
		rep( i, 0, k ){
			scanf("%lld", &v );
			if( n%v < left ){
				id = i+1;
				t = n/v;
				left = n%v;
			}
		}
		printf("%lld %lld\n", id, t );
	}
	
	
}
