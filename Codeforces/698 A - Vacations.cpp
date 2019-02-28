#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 450

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	int n, v[1000], dp[1000][4];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) scanf("%d", &v[i] ), dp[i][0] = dp[i][1] = dp[i][2] = 0;
		dp[n][0] = dp[n][1] = dp[n][2] = 0;
		for( int i = n-1; i >= 0; i-- ){
			dp[i][0] = max( dp[i+1][0], max( dp[i+1][1], dp[i+1][2] ) ); 
			if( v[i]&1 ) dp[i][1] = 1 + max( dp[i+1][0], dp[i+1][2] ) ;
			if( v[i] >= 2 ) dp[i][2] = 1 + max( dp[i+1][0], dp[i+1][1] );
		}
		
		printf("%d\n", n -  max( dp[0][0], max( dp[0][1], dp[0][2] ) ) );
	}
}
