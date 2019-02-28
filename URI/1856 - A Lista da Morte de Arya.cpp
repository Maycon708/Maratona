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
#define MAX 500050

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int cnt, p[MAX], bit[MAX];
vector<int> adj[MAX];

void dfs( int u ){
	if( p[u] != -1 ) return;
	p[u] = cnt++;
	for( int i = adj[u].size()-1; i >= 0; i-- ) 
		dfs( adj[u][i] );
}

void update( int x, int v ){
	for( int i = x; i < MAX; i += i&-i ) 
		bit[i] += v;
}

int query( int x ){
	int ans = 0;
	for( int i = x; i > 0; i -= i&-i ) 
		ans += bit[i];
	return ans;
}


int n, v[MAX], a[MAX], b[MAX], q;
char op[MAX];

int main(){
	
	while( scanf("%d", &n ) != EOF ){
		map<int, int> mp;
		cnt = 1;
		rep( i, 0, n ) scanf("%d", &v[i] ), mp[v[i]] = cnt++;
		scanf("%d", &q );
		rep( i, 0, q ){
			scanf(" %c%d", &op[i], &a[i] );
			if( op[i] != 'R' ) scanf("%d", &b[i] );
			if( op[i] == 'I' ){
				if( !mp.count(a[i])) mp[a[i]] = cnt++;
				adj[mp[b[i]]].pb(mp[a[i]]);
			}
		}
		cnt = 1;
		memset( p, -1, sizeof p );
		rep( i, 0, n ) dfs( mp[v[i]] );
		rep( i, 0, n ) update( p[mp[v[i]]], +1 );
		rep( i, 0, q ){
			int x = p[mp[a[i]]];
			int y = p[mp[b[i]]];
			switch(op[i]){
				case 'R':
					update( x, -1 );
					break;
				case 'I':
					update( x, +1 );
					break;
				default:
					if( x > y ) swap( x, y );
					printf("%d\n", query(y-1) - query(x)); 
			}
		}
	}
	
	return 0;
}
