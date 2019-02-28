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

#define mod 100000000

map<ii, int> pd;
int s[111], f[111], m, n;

int solve( int pos, int last ){
	if( pos == m ) return 1;
	ii aux = ii( pos, last );
	if( pd.count(aux) ) return pd[aux];
	int ans = 0;
	rep( i, 0, n ){
		if( s[i] <= pos && f[i] > pos && s[i] > last ) ans = ( ans + solve( f[i], pos ) )%mod;
	}
	return pd[aux] = ans;
}

int main(){
	while( scanf("%d%d", &m, &n ) != EOF && n+m ){
		rep( i, 0, n ) scanf("%d%d", &s[i], &f[i] );
		pd.clear();
		printf("%d\n", solve( 0, -1 ) ); 
	}
}

