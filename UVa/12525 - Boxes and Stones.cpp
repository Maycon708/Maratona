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

const int mod = 1e9+7;

int s, pd[110][210][105];

int solve( int pos, int p, int k ){
	if( pos == 0 ) return k+p == 0;
	if( pd[pos][p][k] != -1 ) return pd[pos][p][k];
	int ans = 0;
	rep( i, 0, p+1 ){
		ans += solve( pos-1, p-i, ( k + i )/2 );
		if( ans >= mod ) ans %= mod;
	}
	return pd[pos][p][k] = ans;
}

int main(){
	int b;
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	memset( pd, -1, sizeof pd );
	while( scanf("%d%d", &b, &s ) != EOF ){
		printf("%d\n", solve( s-1, b, 0 ) );
	}
}

