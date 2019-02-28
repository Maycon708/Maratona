#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int pai[MAXV];

void init(int v){
    for (int i=0; i <= v; i++)
        pai[i] = i; // inicialmente cada vertice esta no seu proprio conjunto
}

int findset(int i){ // retorna o conjunto que o elemento i pertence
    if (i != pai[i]) 
        pai[i] = findset( pai[i] ); // i esta no mesmo conjunto de pai[i]
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

	int n, m, t = 1;
	while( scanf("%d%d", &n, &m ) != EOF ){
		vector < ii > v[3];
		init( n );
		while( m-- ){
			int u, w, c;
			scanf("%d%d%d", &u, &w, &c );
			if( c == 1235 ) v[0].pb( ii( u, w ) );
			else if( c == 8977 ) v[1].pb( ii( u, w ));
			else v[2].pb( ii( u, w ));
		}
		ll s = 0;
		rep( i, 0, 3 ){
			rep( j, 0, v[i].size()){
				int u = v[i][j].F;
				int w = v[i][j].S;
				int c;
				if( !i ) c = 1235;
				else if( i == 1 ) c = 8977;
				else c = 10923;
				if( !sameset( u, w ) ){
					s += c;
					unionset( u, w );
				}
			}
		}
		printf("Instancia %d\n", t++ );
		printf("%lld\n", s );
		printf("\n");
	}

}
