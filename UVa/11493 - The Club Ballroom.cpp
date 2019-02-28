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

#define gc getchar_unlocked

void scanint( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ); c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}


typedef pair <int, int> ii;
typedef long long int ll;

int v[10001];

int solve( int c, int t ){
	int j = c-1;
	int i = 1;
	int ans = min( v[c], t );
	int cnt = ans;
	t -= ans;
	if( !t ) return cnt;
	while( i <= j ){
		if( i == j ) ans = min( t, ( v[i] >> 1 ) );
		else ans = min( t, min( v[i], v[j] ));
		t -= ans;
		cnt += ( ans << 1 );
		if( !t ) return cnt;
		i++, j--;
	}
	return INF;
}

int main(){
	
	int l, m, k, n, u;
	while( 42 ){
		scanint(l), scanint(m);
		if( !l && !m ) break;
		rep( i, 0, max( l, m )+1 ) v[i] = 0;
		l *= 100, m *= 100;
		
		scanint(k);
		
		scanint(n);
		rep( i, 0, n ){
			scanint(u);
			v[u]++;
		}
		if( !k ) break;
		int ans = INF;
		if( l%k == 0 ) ans = min( ans, solve( m/100, l/k ) );
		if( m%k == 0 ) ans = min( ans, solve( l/100, m/k ) );
		if( ans == INF ) puts("impossivel");
		else printf("%d\n", ans );
	}

}

