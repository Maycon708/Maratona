#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i <= int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 1, l ){ rep( j, 1, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define N 201

long double f[N][N], w[N][N];
int k[N][N], n;

void Knuth(){
	rep( i, 1, n ){
		f[i][i] = w[i][i];
		k[i][i] = i;
	}
	rep( l, 2, n ){
		rep( i, 1, n-l+1 ){
			int j = i + l - 1;
			f[i][j] = INF;
			rep( t, k[i][j-1], k[i+1][j] ){
				long double tmp = w[i][j] + f[i][t-1] + f[t][j];
				if( tmp < f[i][j] ) f[i][j] = tmp, k[i][j] = t;
			} 
		}
	}
}

char ans[N];
void dfs( int i, int j, int d ){
	if( i >= j ){
		ans[d] = '\0';
		printf("%s\n", ans );
		return;
	}
	ans[d] = '0';
	dfs( i, k[i][j]-1, d+1 );
	ans[d] = '1';
	dfs( k[i][j], j, d+1 );
}

int main(){
	int aux;
	while( scanf("%d", &n ) != EOF && n ){
		for( int i = 1; i <= n; i++ ){
			cin >> w[i][i];
		}
		for( int i = 1; i <= n; i++ ){
			for( int j = i+1; j <= n; j++ ){
				w[i][j] = w[i][j-1] + w[j][j];
			}
		}
		
		Knuth();
		cout << fixed << setprecision(4) << f[1][n] - w[1][n] << "\n";
		dfs( 1, n, 0 );
		printf("\n");
	}
}

