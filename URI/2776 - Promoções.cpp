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

int pd[1111][1111];

int main(){
	
	int n, m, q[1111], v[1111];
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ){
			scanf("%d%d", &q[i], &v[i] );
		}
		FOR( i, 1, m ) pd[n][i] = -INF;
		pd[n][0] =  0;
		for( int i = n-1; i >= 0; i-- ){
			for( int j = 0; j <= m; j++ ){
				pd[i][j] = pd[i+1][j];
				if( j >= q[i] ) pd[i][j] = max( pd[i][j], pd[i][j-q[i]]+v[i] );
			}
		}
		printf("%d\n", pd[0][m]);
	}
}
