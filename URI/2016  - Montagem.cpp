#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
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

int pd[18][1<<18];
int n, m[20][20];

int solve( int pos, int mask ){
	if( pos == n ) return 0;
	if( pd[pos][mask] != -1 ) return pd[pos][mask];
	int ans = INF;
	rep( i, 0, n ){
		if( mask & 1 << i ) continue;
		ans = min( ans, solve( pos+1, mask | 1 << i ) + m[pos][i] );
	} 
	return pd[pos][mask] = ans;
}

int main(){
	
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		rep( i, 0, n ){
			rep( j, 0, n ){
				scanf("%d", &m[i][j] );
			}
		}
		rep( i, 0, n )
			rep( j, 0, 1 << n )
				pd[i][j] = -1;
		printf("%d\n", solve( 0, 0 ) );
	}

}
