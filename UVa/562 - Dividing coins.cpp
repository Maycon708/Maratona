#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int pd[110][50100], n, v[110];

int solve( int pos, int dif ){
	if( pos == n ) return dif;
	if( pd[pos][dif] != -1 ) return pd[pos][dif];
	int ans = min( solve( pos+1, dif + v[pos] ), solve( pos+1, abs( dif - v[pos] )));
	return pd[pos][dif] = ans;
}

int main(){
	int t;
	cin >> t;
	while( t-- ){
		cin >> n;
		rep( i, 0, n ) cin >> v[i];
		memset( pd, -1, sizeof pd );
		printf("%d\n", solve( 0, 0 ));
	}	
}
