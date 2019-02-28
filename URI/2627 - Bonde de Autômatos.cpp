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
#define N 250000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int bit[30];

void update( int x, int v ){
	for( int i = x; i < 30; i += (i&-i) ){
		bit[i] = max( bit[i], v );
	}
}

int query( int x ){
	int ans = 0; 
	for( int i = x; i > 0; i -= (i&-i) ){
		ans = max( bit[i], ans );
	}
	return ans;
}

int main(){
	int n, k;
	char s[N];
	
	while( scanf("%d%d", &n, &k ) != EOF ){
		SET(bit, 0);
		scanf("%s", s );
		int ans = 0;
		rep( i, 0, n ){
			int p = s[i]-'a'+1;
			int a = 'z' - s[i] + 1;
			int b = query(p);
			update( p, a + b );
			ans = max( ans, a + b );
		}
		printf("%s\n", ans >= k ? "Aceita" : "Rejeita" );
	}
	
}