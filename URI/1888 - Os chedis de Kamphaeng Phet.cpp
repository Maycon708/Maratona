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

#define N 3003

int n, m, k;
double dp[N][N], sum[N][N];
char s1[N], s2[N];

void solve(){
	dp[n][m] = 0;
	sum[n][m] = 0;
	
	for( int i = n-1; i >= 0; i-- ){
		dp[i][m] = min( 1 + dp[i+1][m], k + sum[i+1][m]/( n-i ));
		sum[i][m] = dp[i][m] + sum[i+1][m];
	}
	for( int j = m-1; j >= 0; j-- ){
		dp[n][j] = min( 1 + dp[n][j+1], k + sum[n][j+1]/( m-j ));
		sum[n][j] = dp[n][j] + sum[n][j+1];
	}
	for( int i = n-1; i >= 0; i-- ){
		for( int j = m-1; j >= 0; j-- ){
			sum[i][j] = sum[i+1][j] + sum[i][j+1] - sum[i+1][j+1];
			if( s1[i] == s2[j] ) dp[i][j] = dp[i+1][j+1];
			else dp[i][j] = min( 1 + min( dp[i+1][j], dp[i][j+1] ), k + sum[i+1][j+1]/(( n-i )*( m-j )));
			sum[i][j] += dp[i][j];
		}
	}
}

int main(){
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d%d", &n, &m, &k );
		scanf("%s", s1 );
		scanf("%s", s2 );
		solve();
		printf("%.3f\n", dp[0][0] );
	}
}

