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

int n, teste = 1, memo[1001][1001], v[1001], q[1001];
double pd[1001][1001];

double solve( int p, int k ){
	if( p == n ) return 0;
	if( memo[p][k] == teste ) return pd[p][k];
	memo[p][k] = teste;
	double ans = (v[p]/100.0) * ( q[p] + solve( p+1, k ) ) ;
	if( k ) ans = max( ans, q[p] + solve( p+1, k-1 ) );
	return pd[p][k] = ans;
}

int main(){
	int k;
	while( scanf("%d%d", &n, &k ) != EOF ){
		rep( i, 0, n ) scanf("%d", &q[i] );
		rep( i, 0, n ) scanf("%d", &v[i] );	
		printf("%.2f\n", solve( 0, k ) );	
		teste++;
	}
}
