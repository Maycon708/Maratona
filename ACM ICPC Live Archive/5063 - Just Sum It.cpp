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

const int mod = 1e9+7;

ll C[100][100], pd[10][100];
int q[10];

ll solve( int p, int t ){
	if( t == 0 ) return 1;
	if( p == 10 ) return 0;
	if( pd[p][t] != -1 ) return pd[p][t];
	ll ans = 0;
	for( int i = 0; i <= min( t, q[p] ); i++ ) ans = ( ans + ( solve( p+1, t-i ) * C[t][i] )%mod )%mod;
	return pd[p][t] = ans;	
}

void pre(){
	C[0][0] = 1;
	rep( i, 1, 100 ){
		C[i][0] = C[i][i] = 1;
		rep( j, 1, i  ){
			C[i][j] = ( C[i-1][j] + C[i-1][j-1] )%mod;
		}
	}
}

int main(){
	
	pre();
	
	int t;
	scanf("%d", &t );
	while( t-- ){
		ll ans = 0, sum = 0;
		rep( i, 1, 10 ) scanf("%d", &q[i] ), sum += q[i];
		rep( i, 1, 10 ){
			if( !q[i] ) continue;
			memset( pd, -1, sizeof pd );
			q[i]--;
			ll p = i;
			for( int j = 1; j <= sum; j++ ){
				ans = ( ans + solve(1, j-1) * p )%mod;
				p = ( p * 10 + i )%mod;
			}
			q[i]++;
		}
		printf("%lld\n", ans );
	}
	
}

