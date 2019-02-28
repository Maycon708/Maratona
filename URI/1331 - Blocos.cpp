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

vector<ii> V;
int pd[202][202][202];

int solve( int i, int j, int t ){
	
	if( i > j ) return 0;
	if( pd[i][j][t] != -1 ) return pd[i][j][t];
	int ans = solve( i+1, j, 0 ) + ( V[i].F + t ) * ( V[i].F + t );
	
	for( int k = i+1; k <= j; k++ )
		if( V[k].S == V[i].S )
			ans = max( ans, solve( i+1, k-1, 0 ) + solve( k, j, t + V[i].F ) );	
	
	return pd[i][j][t] = ans;
}

int main(){
	
	int t, n, v[202], test = 1;
	scanf("%d", &t );
	while( t-- ){
		V.clear();
		scanf("%d%d", &n, &v[0] );
		int cnt = 1, last = v[0];
		for( int i = 1; i < n; i++ ){
			scanf("%d", &v[i] );
			if( v[i] != last ) V.pb( ii( cnt, last ) ), last = v[i], cnt = 1;
			else cnt++;
		}
		V.pb( ii( cnt, last ));
		memset( pd, -1, sizeof pd );
		printf("Case %d: %d\n", test++, solve( 0, V.size()-1, 0 ) );
	}

}

