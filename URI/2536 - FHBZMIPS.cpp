#include <bits/stdc++.h>

#define INF 30
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int mod( int a ){
	return ((a%256)+256)%256;
}

int main(){
	int n, id, a[111], b[111], vis[111][300];
	char s[111][111];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 1, n+1 ){
			scanf("%d%s", &id, s[i] );
			if( s[i][0] != 'h' ) scanf("%d", &a[i] );
			if( s[i][0] == 'g' ) scanf("%d", &b[i] );
		}
		int ans = 0, aux = 0, i = 1;
		memset( vis, 0, sizeof vis );
		for( ; ; ++i ){
			if( s[i][0] == 'h' || vis[i][ans] ){
				aux = vis[i][ans];
				break;
			}
			vis[i][ans] = 1;
			switch( s[i][0] ){
				case 'a':
					if( s[i][1] == 'd' ) ans = mod( ans + a[i] );
					else ans = mod( ans & a[i] );
					break;
				case 's':
					ans = mod( ans - a[i] );
					break;
				case 'm':
					ans = mod( ans * a[i] );
					break;
				case 'd':
					ans = mod( ans / a[i] );
					break;
				case 'o':
					ans = mod( ans | a[i] );
					break;
				case 'x':
					ans = mod( ans ^ a[i] );
					break;
				case 'g':
					if( ans >= a[i] ) i = b[i]-1;
					break;
			}
		}
		if( aux ) puts("execucao infinita");
		else printf("%d\n", ans );
	
	}
}
