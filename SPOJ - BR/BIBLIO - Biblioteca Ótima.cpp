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

#define N 100

int n, P[N][N], F[N][N], sum[N][N];

int solve(){
	rep( i, 1, n ){
		rep( j, 1, n ) F[i][j] = INF * ( i < j );
		P[i][i] = i;
	}
	rep( l, 2, n ){	
		rep( i, 1, n-l+1 ){
			int j = i + l - 1;
			rep( p, P[i][j-1], P[i+1][j] ){
				int w = F[i][p-1] + sum[i][p-1] + F[p+1][j] + sum[p+1][j];
				if( w < F[i][j] ) F[i][j] = w, P[i][j] = p;
			} 
		}
	}
	return F[1][n];
}

int main(){
	int t, v, test = 1;
	while( scanf("%d", &n ) != EOF && n ){
		rep( i, 1, n ) scanf("%d", &sum[i][i] );
		rep( i, 1, n ) rep( j, i+1, n ) sum[i][j] = sum[i][j-1] + sum[j][j];
		printf("Teste %d\n%d\n\n", test++, solve() );
	}
}

