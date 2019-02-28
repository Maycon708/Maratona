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

int t, n, m, mat[111][111], pd[111][111];

int solve( int x, int y ){
	if( x == n || y == m || y == -1 ) return 0;
	int &ans = pd[x][y];
	if( ans == -1 ){
		ans = mat[x][y] + max( solve( x+1, y-1 ), max( solve( x+1, y ), solve( x+1, y+1 ) ) ); 
	}
	return ans;
}

int main(){
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &m );
		memset( pd, -1, sizeof pd );
		rep( i, 0, n ){
			rep( j, 0, m ){
				scanf("%d", &mat[i][j] );
			}
		}
		int ans = 0;
		rep( i, 0, m ) ans = max( ans, solve( 0, i ) );
		printf("%d\n", ans );
	}
}
