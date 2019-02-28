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

int main(){
	
	int x[4], y[4], a = 0, b = 0;
	
	rep( i, 0, 4 ) scanf("%d%d", &x[i], &y[i] );
	
	if( x[3] >= x[0] && x[3] <= x[1] || x[2] >= x[0] && x[2] <= x[1] || x[0] >= x[2] && x[0] <= x[3] || x[1] >= x[2] && x[1] <= x[3]  ) a = 1;
	if( y[3] >= y[0] && y[3] <= y[1] || y[2] >= y[0] && y[2] <= y[1] || y[0] >= y[2] && y[0] <= y[3] || y[1] >= y[2] && y[1] <= y[3] ) b = 1;
	
	printf("%d\n", a*b );
//	return main();	
}
