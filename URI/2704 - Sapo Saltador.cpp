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
	
	char s[100010];
	bool can[100010];
	while( scanf("%s", s ) != EOF ){
		memset( can, 0, sizeof can );
		int n = strlen(s);
		vector<int> div;
		int lim = ceill(sqrt(n));
		rep( i, 1, lim ) if( n%i == 0 ) div.pb(i), div.pb(n/i);
		if( lim*lim == n ) div.pb(lim);
		rep( i, 0, div.size() ){ // 2*sqrt(N)z
			rep( j, 0, div[i] ){// d
				if( s[j] == 'P') continue;
				int k;
				for( k = j+div[i]; k != j; k = (k+div[i])%n ) if(s[k] == 'P') break;	// n/d
				if( k == j ){
					can[div[i]] = 1;
					break;
				}
			}
		}
		int ans = 0;
		rep( i, 1, n ) if( can[__gcd(i, n)] ) ans++;
		printf("%d\n", ans );
	}
	
}
