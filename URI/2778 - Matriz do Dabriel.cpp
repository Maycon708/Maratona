#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
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

int pd[100][100][21][21][2], n, m, x, y, mat[100][100];
int memo[100][100][21][21][2], cnt;

int solve( int i, int j, int c1, int c2, int e ){
	if( !c1 && !mat[i][j] || !c2 && mat[i][j] < 0 ) return INF;	
	if( i == n-1 && j == m-1 ) return mat[i][j];
	int &ans = pd[i][j][c1][c2][e];
	if( memo[i][j][c1][c2][e] != cnt ){
		memo[i][j][c1][c2][e] = cnt;
		ans = INF;
		if( !mat[i][j] ) c1--;
		if( mat[i][j] < 0 ) c2--;
		if( e && j ) ans = min( ans, solve( i, j-1, c1, c2, e ) + mat[i][j] );
		if( !e && j < m-1 ) ans = min( ans, solve( i, j+1, c1, c2, e ) + mat[i][j] );
		if( i < n-1 ) ans = min( ans, min( solve( i+1, j, c1, c2, 0 ), solve( i+1, j, c1, c2, 1 ) ) + mat[i][j] );
	}
	return ans;
}

int main(){
	while( scanf("%d%d%d%d", &n, &m, &x, &y ) != EOF ){
		rep( i, 0, n ){
			rep( j, 0, m ){
				scanf("%d", &mat[i][j] );
			}
		}
		cnt++;
		int ans = solve(0, 0, x, y, 0);
		if( ans < 100*100*100+1 ) printf("%d\n", ans );
		else printf("Impossivel\n");
	}
}
