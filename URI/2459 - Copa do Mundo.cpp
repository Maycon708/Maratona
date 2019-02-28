#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 101000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

int pai[MAXV];

typedef pair<int,int> ii;

int S = 0;


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
    
    int n, k, x, y, m, op;
    
    while( scanf("%d%d%d", &n, &k, &m ) != EOF ){
	    init(n);
	    priority_queue< pair<int, ii > > pq;
		int ans = 0;
	
	    while( k-- ){
	    	scanf("%d%d%d", &x, &y, &op );
	    	pq.push( mk( -op, ii( x, y ) ) );
		}
		
		while( !pq.empty() ){
			int u = pq.top().S.F;
			int v = pq.top().S.S;
			int c = -pq.top().F;
			pq.pop();
			if( !sameset( u, v ) ){
				ans += c;
				unionset( u, v );
			}
		}
		
	    while( m-- ){
	    	scanf("%d%d%d", &x, &y, &op );
	    	pq.push( mk( -op, ii( x, y ) ) );
		}
		
		
		while( !pq.empty() ){
			int u = pq.top().S.F;
			int v = pq.top().S.S;
			int c = -pq.top().F;
			pq.pop();
			if( !sameset( u, v ) ){
				ans += c;
				unionset( u, v );
			}
		}
		
		printf("%d\n", ans );
		
	}
    return 0;
}
