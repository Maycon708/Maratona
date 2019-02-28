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

int pd[1000][51], memo[1000][51], t = 1, n, w[1000], v[1000];

int solve( int p, int c ){
	if( p == n ) return 0;
	if( memo[p][c] == t ) return pd[p][c];
	memo[p][c] = t;
	int ans = 0;
	if( c >= w[p] ) ans = max( ans, solve( p+1, c-w[p] ) + v[p] );
	ans = max( ans, solve( p+1, c ) );
	return pd[p][c] = ans;  
}

int main(){
	int m;
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		rep( i, 0, n ){
			scanf("%d%d", &w[i], &v[i] );
		}
		printf("Caso %d: %d\n", t++, solve( 0, m ) );
	}
}

