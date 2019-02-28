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

int pd[300], n, t;
char s[300];

int solve( int pos ){
	if( pos == n ) return 0;
	if( pd[pos] != -1 ) return pd[pos];
	int ans = 0, cnt = 0;
	for( int i = pos; i < n; i++ ){
		cnt += ( s[i] == '1' );
		ans = max( ans, solve( i+1 ) + ( ( cnt*2 > ( i-pos+1 ) )? (i-pos+1) : 0 ) );
	}
	return pd[pos] = ans;
}

int main(){
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		scanf("%s", s );
		memset( pd, -1, sizeof pd );
		printf("%d\n", solve(0) );
	}
}

