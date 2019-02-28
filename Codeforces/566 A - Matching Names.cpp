#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXL 1000008
#define cc 26
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;
typedef vector<int> vi;

int sig[MAXL][cc], cnt, total, black[MAXL], white[MAXL];
vi b[MAXL], w[MAXL];

void add( string s, int cor, int id ){
	
	int x = 0;
	rep( i, 0, s.size() ){
		
		if( cor ) w[x].pb(id);
		else b[x].pb(id);	
		
		int u = s[i] - 'a';
		if( !sig[x][u] ) sig[x][u] = cnt++;
		x = sig[x][u];
	}
	if( cor ) w[x].pb(id);
	else b[x].pb(id);	
}

int n, matched;

void dfs( int v, int h ){
	if( w[v].empty() || b[v].empty() ) return;
	rep( i, 0, cc )
		if( sig[v][i] )
			dfs( sig[v][i], h+1 );
	
	if( matched == n ) return;
	
	for( int i = 0, j = 0; i < b[v].size() && j < w[v].size(); ){
		int bi = b[v][i], wj = w[v][j];
		if( black[bi] ) i++;
		else if( white[wj] ) j++;
		else{
			total += h;
			black[bi] = wj;
			white[wj] = bi;
			i++, j++;
			matched++;
		}
	}
}

char nome[MAXL];
int main(){
	scanf("%d", &n );
	cnt = 1; total = matched = 0;
	rep( j, 0, 2 ){
		rep( i, 0, n ){
			scanf("%s", nome );
			add( nome, j, i+1 );
		}
	}
	dfs( 0, 0 );
	printf("%d\n", total );
	for( int i = 1; i <= n; i++ ) printf("%d %d\n", i, black[i] );
}

