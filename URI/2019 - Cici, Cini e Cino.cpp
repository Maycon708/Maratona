#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define EPS 1e-9
#define mk make_pair
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

ll readInt();

const int SS = 2; 	//Qtdd de sequencias
const int V = 1100; 	// Max de Vertices
const int E = 51; 	// Maximo de arestas

ll adj[SS][V][E], s[SS][V];
ll K, l[2];
ll dist[V][V]; // distancia percorrida ate chegar aqui e matriz de visitados
ll cam[V][V]; // Quantidade de caminhos para e chegar at e aqui

struct T{
	int a, b;
	T(){};
	T( int _a, int _b ){
		a = _a; b = _b;
	}
};

ii bfs(){
	queue< T > q;
	memset( dist, 0, sizeof dist );
	memset( cam, 0, sizeof cam );
	q.push( T( 0, 0 ) );
	cam[0][0] = 1;
	ii resp = ii( INF, 0 );
	while( !q.empty() ){
		int a = q.front().a;
		int b = q.front().b;
		q.pop();
		if( resp.F <= dist[a][b] ) break;
		rep( i, 1, K+1 ){
			int A = adj[0][a][i], B = adj[1][b][i]; 
			if( A == l[0]+1 || B == l[1]+1 ){
				resp.F = dist[a][b] + 1;
				resp.S += cam[a][b];
			}
			if( resp.S ) continue;
			if( !dist[A][B] ){
				dist[A][B] = dist[a][b] + 1;
				cam[A][B] = cam[a][b];
				q.push( T( A, B ) );
			}
			else{
				if( dist[A][B] == dist[a][b] + 1 )
					cam[A][B] += cam[a][b];
			}
		}
	}
	return resp;
}

int main(){
	while( scanf("%lld", &K ) != EOF ){
		rep( i, 0, 2 ) l[i] = readInt();
		
		rep( i, 0, 2 )
			rep( j, 1, l[i]+1 )
				s[i][j] = readInt();
		
		rep( i, 0, 2 )
			rep( j, 0, l[i]+1 )
				rep( k, 0, K+1 )
					adj[i][j][k] = l[i] + 1;
		
		rep( i, 0, 2 ){
			rep( j, 0, l[i]+1 ){
				for( int k = j-1; k >= 0; k-- ){
					adj[i][k][ s[i][j] ] = j;
					if( s[i][j] == s[i][k] ) break;
				}
			}
		}
		ii ans = bfs();
		printf("%lld %lld\n", ans.F, ans.S );
	}
}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}



