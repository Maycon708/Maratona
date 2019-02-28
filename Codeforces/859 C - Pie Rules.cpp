#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int n, v[100], pd[111][2];

int solve( int i, bool b ){
	if( i == n ) return 0;
	int &ans = pd[i][b];
	if( ans != -1 ) return ans;
	if( b )	ans = max( v[i] + solve( i+1, 0 ), solve( i+1, 1 ) );
	else ans = min( solve(i+1, 1 ), v[i] + solve( i+1, 0 ));
	return ans; 
}

int main(){
	while( scanf("%d", &n ) != EOF ){
		int sum = 0;
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			sum += v[i];
		}
		memset( pd, -1, sizeof pd );
		int ans =  solve( 0, 1 );
		printf("%d %d\n", sum - ans, ans );
	}
}
