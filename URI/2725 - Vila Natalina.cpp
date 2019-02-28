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

int pai[1010];

void init(int v){
    for (int i=0; i <= v; i++)
        pai[i] = i; // inicialmente cada vertice esta no seu proprio conjunto
}
 
int findset(int i){ // retorna o conjunto que o elemento i pertence
    if (i != pai[i]) 
        pai[i] = findset(pai[i]); // i esta no mesmo conjunto de pai[i]
    return pai[i];
}
  
void unionset(int a, int b){
    int aa = findset(a); 
    int bb = findset(b);
    pai[bb] = aa; // aa se torna o pai do conjunto bb
 
}
 
bool sameset(int a, int b){
    return findset(a) == findset(b); // retorna true se os conjuntos que contem os elementos A e B é o mesmo
}

int main(){
	
	int t, n, c, x[1010], y[1010];
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &c );
		rep( i, 0, n ){
			scanf("%d%d", &x[i], &y[i] );
		}
		init(n);
		vector< pair< int, ii > > edges;
		rep( i, 0, n ){
			rep( j, i+1, n ){
				int dx = abs( x[j] - x[i] );
				int dy = abs( y[j] - y[i] );
				int gcd = __gcd( dx, dy );
				edges.pb( mk( gcd-1, ii( i, j ) ) );
			}
		}
		sort( all(edges) );
		ll s = 0;
		rep( i, 0, edges.size() ){
			int u = edges[i].S.F;
			int v = edges[i].S.S;
			if( !sameset( u, v ) ){
				s += edges[i].F;
				unionset(u, v);
			}
		}
		printf("%lld\n", s * c );
	}
	
}
