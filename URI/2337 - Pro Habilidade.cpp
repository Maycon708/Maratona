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

ll pd[50][2][2];
int n;

ll solve( int pos, int l, int a ){
	if( pos == n ) return a;
	if( pd[pos][l][a] != -1 ) return pd[pos][l][a];
	ll ans = solve( pos+1, 0, a );
	if( l ) ans += solve( pos+1, 1, 1 );
	else ans += solve( pos+1, 1, a );
	return pd[pos][l][a] = ans;
}

int main(){
	while( scanf("%d", &n ) != EOF ){
		memset( pd, -1, sizeof pd );
		int k = n;
		ll a = 1;
		rep( i, 0, n ) a *= 2LL;
		ll num = a - solve(0, 0, 0);
		ll gcd = __gcd(num, a);
		printf("%lld/%lld\n", num/gcd, a/gcd );
	}
}

