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

typedef long long int ll;
typedef pair <ll, ll> ii;

ii pd[110][110];
ll s[110];
int n;

ii solve( int i, int j ){
	if( i == j ){
		ll a = s[i];
		return ii( a, a );
	}
	if( pd[i][j] != ii( -1, -1 ) ) return pd[i][j];
	ll a = ( 1 << 31 );
	ii resp = ii( 0, a*a );
	rep( k, i, j ){
		if( k&1 ){
			ii a = solve( i, k-1 );
			ii b = solve( k+1, j );
			if( s[k] ){
				resp.F = max( resp.F, a.F + b.F );
				resp.S = min( resp.S, a.S + b.S );
			}
			else{
				resp.F = max( resp.F, a.F * b.F );
				resp.S = min( resp.S, a.S * b.S );
			}
		}
	}
	return pd[i][j] = resp;
}

int main(){
	int t;
	scanf("%d", &t );
	while( t-- ){
		char c[100];
		scanf("%s", c );
		n = strlen( c );
		int k = 0, num = 0;
		rep( i, 0, n ){
			if( c[i] == '+' ){
				s[k++] = num;
				num = 0;
				s[k++] = 1;
			}
			else if( c[i] == '*' ){
				s[k++] = num;
				num = 0;
				s[k++] = 0;
			}
			else{
				num *= 10;
				num += ( c[i] - '0' );
			}
		}
		s[k++] = num;
		rep( i, 0, k ){
			rep( j, 0, k ){
				pd[i][j] = ii( -1, -1 );
			}
		}
		ii ans = solve( 0, k-1 );
		printf("The maximum and minimum are %lld and %lld.\n", ans.F, ans.S );
	}
}

