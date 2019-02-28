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

const int mod = 1e9 + 7;

ll pd[100100], n, m;

char s[100100], t[110];

ll solve( int pos ){
	if( pos == n ) return 1;
	if( s[pos] == '0' ) return 0;
	if( pd[pos] != -1 ) return pd[pos];
	ll ans = 0;
	for( int i = pos; i < min( n, pos + m - 1 ); i++ ){
		ans = ( ans + solve( i+1 ) )%mod;
	}
	if( pos + m <= n ){
		bool aux = 1;
		rep( i, 0, m ){
			if( s[pos+i] != t[i] ){
				aux = ( s[pos+i] < t[i] );
				break;
			}
		}
		if( aux ) ans = ( ans + solve( pos+m ) )%mod;
	}
	return pd[pos] = ans;
}

int main(){
	while( scanf("%s", t ) != EOF ){
		scanf("%s", s );
		memset( pd, -1, sizeof pd );
		n = strlen(s);
		m = strlen(t);
		printf("%lld\n", solve(0) );
	}
}

