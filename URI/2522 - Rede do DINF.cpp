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

int pai[505];

typedef pair<int,int> ii;

priority_queue<pair<int,ii> > pq;

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
    
    int n, x[505], y[505];
    while( scanf("%d", &n ) != EOF ){
    	init(n);
		rep( i, 0, n ) scanf("%d%d", &x[i], &y[i] );
    	priority_queue< pair<double, ii> > pq;
    	rep( i, 0, n ){
    		rep( j, i+1, n ){
    			pq.push( mk( -hypot( x[i] - x[j], y[i] - y[j] ), ii( i, j ) ) );
			}
		}
		double ans = 0;
		while( !pq.empty() ){
			double d = -pq.top().F;
			int u = pq.top().S.F;
			int v = pq.top().S.S;
			pq.pop();
			if( !sameset( u, v ) ){
				unionset( u, v );
				ans += d;
			}
		}
		printf("%.2f\n", ans );
	}
    
    return 0;
}
