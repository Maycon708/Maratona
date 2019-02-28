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

#define gc getchar_unlocked

void scan( ll &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int main(){
	ll t, n, m, u, v[10001], q, op, a, b, ans;
	
	scan(t);
	while( t-- ){
		scan(n);
		for( int i = n; i > 0; i-- ){
			scan(m);
			v[n-i] = 0;
			for( int j = m; j > 0; j-- ){
				scan(u); u--;
				v[n-i] |= ( ll(1) << u );
			}
		}
		scan(q);
		for( int i = q; i > 0; i-- ){
			scan(op);
			scan(a); a--;
			scan(b); b--;
			if( op == 1 ) u = v[a] & v[b];
			else u = v[a] | v[b];
			for( ans = 0; u; u >>= 1 ) ans += ( u & 1 );
			printf("%lld\n", ans );
		}
	}
} 

