#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { FOR( i, 1, l ){ FOR( j, 1, c ) cout << x[i][j] << " "; printf("\n");}}
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

double prob[333][333];
double win[777][777];
int n, vis[777], L[777], R[777];

void dfs( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	dfs( L[u] );
	dfs( R[u] );
	
	FOR( i, 1, n ){
		double x = 0;
		FOR( j, 1, n ){
			x += ( prob[i][j] * win[R[u]][j] );
		}
		x *= win[L[u]][i];
		win[u][i] += x;
	}
	
	FOR( i, 1, n ){
		double x = 0;
		FOR( j, 1, n ){
			x += ( prob[i][j] * win[L[u]][j] );
		}
		x *= win[R[u]][i];
		win[u][i] += x;
	}
}

int main(){
	
	int g[1000];
	while( scanf("%d", &n ) != EOF && n ){
		FOR( i, 0, 2*n ){
			FOR( j, 0, 2*n ) win[i][j] = 0;
			g[i] = 0;
			vis[i] = 0;
		}
		FOR( i, 1, n ){
			FOR( j, 1, n ) scanf("%lf", &prob[i][j] );
			vis[i] = 1;
			win[i][i] = 1;
		}
		rep( i, n+1, 2*n ){
			scanf("%d%d", &L[i], &R[i] );
			g[L[i]]++;
			g[R[i]]++;
		}
		rep( i, n+1, 2*n ){
			if( !g[i] ){
				dfs( i );
				printf("%.6f\n", win[i][1] );
				break;
			}
		}
		
	}
	
}
