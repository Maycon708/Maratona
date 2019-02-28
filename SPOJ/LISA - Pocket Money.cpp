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

ii pd[110][110];
char s[110];
int n;

ii solve( int i, int j ){
	if( i == j ){
		int a = s[i] - '0';
		return ii( a, a );
	}
	if( pd[i][j] != ii( -1, -1 ) ) return pd[i][j];
	ii resp = ii( 0, INF );
	rep( k, i, j ){
		if( k&1 ){
			ii a = solve( i, k-1 );
			ii b = solve( k+1, j );
			if( s[k] == '+' ){
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
		scanf("%s", s );
		n = strlen( s );
		rep( i, 0, n ){
			rep( j, 0, n ){
				pd[i][j] = ii( -1, -1 );
			}
		}
		ii ans = solve( 0, n-1 );
		printf("%d %d\n", ans.F, ans.S );
	}
}

