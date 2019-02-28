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

double pd[65540], dist[20][20];
int n;

double solve( int mask ){
	int k = __builtin_popcount(mask);
	if( k == n ) return 0;
	if( pd[mask] > -1 ) return pd[mask];
	double ans = 1LL << 40;
	rep( i, 0, n ){
		if( mask & ( 1 << i ) ) continue;
		rep( j, i+1, n ){
			if( mask & ( 1 << j ) ) continue;
			ans = min( ans, solve( mask | ( 1 << i ) | ( 1 << j ) ) + dist[i][j] ); 
		}
	}
	return pd[mask] = ans;
}


#define gc getchar//_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int main(){
	int t, x[20], y[20];
	scan(t);
	for( register int k = t; k > 0; k-- ){
		scan(n);
		for( register int i = 1 << n; i >= 0; i-- ) pd[i] = -10;
		for( register int i = n; i > 0; i-- ){
			scan( x[n-i] ), scan( y[n-i] );
		}
		for( register int i = n; i > 0; i-- )
			for( register int j = i; j > 0; j-- )
				dist[n-i][n-j] = dist[n-j][n-i] = hypot( x[n-i] - x[n-j], y[n-i] - y[n-j] ); 
		printf("%.2f\n", solve(0) );
	}
}
