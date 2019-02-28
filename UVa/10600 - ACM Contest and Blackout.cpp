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

vector< pair<int, ii > > edges;
vector<int> id;
int pai[111];

void init( int v ){
    for( int i = 0; i <= v; i++ )
        pai[i] = i;
}
 
int findset( int i ){
    if( i != pai[i] ) 
        pai[i] = findset( pai[i] );
    return pai[i];
}
  
void unionset( int a, int b ){
    int aa = findset(a); 
    int bb = findset(b);
    pai[bb] = aa;
}
 
bool sameset( int a, int b ){
    return findset(a) == findset(b); 
}
int n;
int kruskal( int op ){
	init(n);
	int ans = 0;
	rep( i, 0, edges.size() ){
		if( i == op ) continue;
		int u = edges[i].S.F;
		int v = edges[i].S.S;
		int c = edges[i].F;
		if( !sameset( u, v ) ){
			ans += c;
			unionset( u, v );
			if( op == -1 ) id.pb(i);
		}
	}
	if( op != -1 ){
		int u = edges[op].S.F;
		int v = edges[op].S.S;
		int c = INF;
		if( !sameset( u, v ) ) ans += c;
	}
	return ans;
}

int main(){
	int t, u, v, c, m;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &m );
		while( m-- ){
			scanf("%d%d%d", &u, &v, &c );
			edges.pb( mk( c, ii( u, v ) ));
		}
		sort( all( edges ));
		int a = kruskal(-1), b = kruskal( id[0] );
		rep( i, 1, id.size() ){
			b = min( b, kruskal( id[i] ));
		}
		printf("%d %d\n", a, b );
		edges.clear();
		id.clear();
	}
}

