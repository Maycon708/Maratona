#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int mod = 1e9+7;
ll pd[12][12][51], qttd[10];

ll C[102][102];
 
void calc_pascal(){
	memset(C, 0, sizeof(C));
    rep( i, 0, 102 ){
        C[i][0] = C[i][i] = 1;   
        rep( j, 1, i ){
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
		}
    }
}

ll solve( int pos, int resto, int pares, int impares ){
	if( pos == 10 ) return !resto;
	if( pd[pos][resto][pares] != -1 ) return pd[pos][resto][pares];
	ll ans = 0;
	rep( i, 0, qttd[pos]+1 ){
		int a = i, b = qttd[pos] - i;
		
		if( pares >= a && impares >= b ){
			ll aux = ( resto + ( ( a * pos )%11 - ( b * pos )%11 + 11 )%11 )%11;
			ans += ((( C[pares][a] * C[impares][b] )%mod ) * solve( pos+1, aux, pares - a, impares - b ) )%mod;
			ans%=mod;
		}
	}
	return pd[pos][resto][pares] = ans;
}

int main(){
	char s[1001];
	calc_pascal();

	while( scanf("%s", s ) != EOF ){
		memset( qttd, 0, sizeof qttd );

		int t = strlen(s);
		rep( i, 0, t ){
			int u = s[i] - '0';
			qttd[u]++;
		}
		
		ll ans = 0;
		rep( i, 1, 10 ){
			if( !qttd[i] ) continue;
			memset( pd, -1, sizeof pd );
			qttd[i]--;
			
			if( t&1 ) ans += solve( 0, 11-i, t/2, t/2 );
			else ans += solve( 0, i, (t-1)/2, t/2 );
			if( ans > mod ) ans %= mod;
			qttd[i]++;	
		}
		
		printf("%lld\n", ans );
	}
	
}

