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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	int m, n, u, v, c, e[1010], s[1010];
	while( scanf("%d%d", &m, &n ) != EOF ){
		rep( i, 1, n+1 ) e[i] = s[i] = 0;
		int ans = 0, check = 0;
		while( m-- ){
			scanf("%d%d%d", &u, &c, &v );
			ans += c; s[u] += c; e[v] += c;
		}
		rep( i, 1, n+1 ){
			if( e[i] && s[i] ) ans -= min(e[i], s[i]), check = 1;
		}
		printf("%c\n%d\n", check? 'S':'N', ans );
	}
}
