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
typedef vector< int > vec;

vec v, u;
bool aux;

// Compara se o vector a é igual a u
inline bool C( vec a ){
	if( a.size() != u.size() ) return 0;
	rep( i, 0, a.size() ){
		if( a[i] != u[i] ) return 0;
	}
	return 1;
}

// Dobra o vector a na posição pos
vec dobra( vec a, int pos ){
	vec b;
	int k = a.size() - pos;
	if( pos > k ){
		rep( i, 0, pos ){
			b.pb( a[i] );
		}
		rep( j, 1, k+1 ){
			int u = b.size() - j;
			b[u] += a[pos+j-1]; 
		}
	}
	else{
		rep( i, pos, a.size() ) b.pb( a[i] );
		rep( i, 0, pos ){
			int u = pos - i - 1;
			b[i] += a[u];
		}
		reverse( all( b ) );
	}
	return b;
}

//Salva se um estado ja foi visitado, pq se sim eu ja sei a resposta
map< vec, bool > vis;
void D( vec c ){
	printf("////////////////");
	rep( i, 0, c.size() ) printf("%d ", c[i] );
	printf("\n");
}

void solve( vec a ){	
	if( vis[a] || a.size() < u.size() ) return;
	vis[a] = 1;
	if( C( a ) || aux ){	// Se meu vector é igual ao desejado ou eu ja achei a resposta retorna a recursão
		aux = 1;
		return;
	}
	rep( i, 0, a.size() ){		// Senão, tenta dobrar o vector em todas as posições e chama a recursão
		vec b = dobra( a, i );
		solve( b );
	}
}


int main(){
	int n, m;
	while( scanf("%d", &n ) != EOF ){
		u.clear(), v.clear(), vis.clear();
		aux = 0;
		int a = 0, b = 0;
		rep( i, 0, n ){
			int k;
			scanf("%d", &k );
			v.pb( k );
			a += k;
		}
		
		scanf("%d", &m );
		rep( i, 0, m ){
			int k;
			scanf("%d", &k );
			u.pb( k );
			b += k;
		}	
			
		if( a != b ){
			puts("N");
			continue;
		}
		solve( v );
		if( aux ) puts("S");
		else puts("N");
		
	}

}
