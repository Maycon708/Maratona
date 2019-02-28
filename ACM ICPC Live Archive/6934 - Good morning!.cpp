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

vector<int> adj[11];
int ans, resp, k; 

void back( int last, int p, int r ){
	if( ans >= abs( k-r ) ) ans = abs(k-r), resp = r;
	if( p == 3 ) return;
	rep( i, 0, adj[last].size() ){
		int v = adj[last][i];
		back( v, p+1, r*10 + v );
	}
}

int main(){
	adj[0].pb(0);
	rep( i, 1, 10 ){
		if( i%3 != 0 ) adj[i].pb(0);
		adj[i].pb(i);
		rep( j, i+1, 10 ){
			if( i%3 == 1 ) adj[i].pb(j);
			if( i%3 == 2 && j%3 != 1 ) adj[i].pb(j);
			if( i%3 == 0 && j%3 == 0 ) adj[i].pb(j);
		}
	}
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &k );
		ans = INF;
		rep( i, 0, 10 ) back( i, 1, i );
		printf("%d\n", resp );
	}
}

