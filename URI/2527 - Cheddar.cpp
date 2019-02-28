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

double pd[1000][6001];
int n, m;

double solve( int p, int v ){
	if( v <= 0 ) return 1;
	if( p == n ) return 0;
	if( pd[p][v] > -1 ) return pd[p][v];
	double ans = 0;
	rep( i, 1, 7 )
		ans += ( 1.0/6.0 * solve( p+1, v - i ) );
	return pd[p][v] = ans;
}

int main(){
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ) rep( j, 0, m+1 ) pd[i][j] = -10;
		printf("%.4f\n", solve( 0, m ) );
	}
}

