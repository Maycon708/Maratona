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

int mx[111111], v[111111], pai[111111];

void init( int n ){
	rep( i, 0, n ) pai[i] = i;
}

int findset( int u ){
	return ( u == pai[u] ) ? u : pai[u] = findset( pai[u] );
}

void unionset( int u, int v ){
	u = findset(u);
	v = findset(v);
	mx[u] = mx[v] = max( mx[u], mx[v] );
	pai[v] = u;
}

int main(){
	
	int n, m, q;
	char n1[1111], n2[1111];
	
	while( scanf("%d%d%d", &n, &m, &q ) != EOF ){
		map<string, int> mp;
		rep( i, 0, n ){
			scanf("%s%d", n1, &v[i] );
			mx[i] = v[i];
			mp[n1] = i;
		}
		init(n);
		while(m--){
			scanf("%s%s", n1, n2 );
			unionset(mp[n1], mp[n2]);	
		}
		while(q--){
			scanf("%s", n1 );
			int u = mp[n1];
			int w = findset(u);
			if( v[u] >= 5 ) puts("S");
			else if( mx[w] > 5  ) puts("N");
			else puts("S");
		}
	}
	
	return 0;
}
