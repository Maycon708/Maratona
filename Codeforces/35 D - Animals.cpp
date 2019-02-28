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

int pd[110][10010], c[110], n, k;

int solve( int p, int t ){
	if( p == n ) return 0;
	int &ans = pd[p][t];
	if( ans == -1 ){
		ans = solve(p+1, t);
		if( t >= c[p] ) ans = max( ans, 1+solve(p+1, t-c[p] ) );
	}
	return ans;
}

int main(){
	freopen("input.txt", "r", stdin );
	freopen("output.txt", "w", stdout );
	while( scanf("%d%d", &n, &k ) != EOF	 ){
		rep( i, 0, n ) scanf("%d", &c[i] ), c[i] *= (n-i);
		memset( pd, -1, sizeof pd );
		printf("%d\n", solve(0, k) );
	}
}
