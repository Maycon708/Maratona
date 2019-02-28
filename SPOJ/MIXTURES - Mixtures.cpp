#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

ii pd[111][111];	
int v[111];

ii solve( int i, int  j ){
	if( i == j ) return ii( v[i], 0 );
	if( pd[i][j] != ii(-1, -1) ) return pd[i][j];
	ll ans = INF;
	ii resp = ii( INF, INF );
	rep( k, i, j ){
		ii a = solve( i, k );
		ii b = solve( k+1, j );
		ll aux = a.F * b.F + a.S + b.S;
		if( aux < ans ){
			ans = aux;
			resp = ii( ( a.F + b.F )%100, aux );
		}
	}
	return pd[i][j] = resp;
}

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) scanf("%d", &v[i] );
		rep( i, 0, n )
			rep( j, 0, n )
				pd[i][j] = ii( -1, -1 );
		ii ans = solve( 0, n-1 );
		printf("%d\n", ans.S );	
	}
}

