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

bool p[1000100];

void crivo(){
	memset( p, 1, sizeof p );
	p[0] = p[1] = 0;
	for( int i = 2; i <= 1000; i++ ){
		if( !p[i] ) continue;
		for( int j = i+i; j <= 1000000; j += i ) p[j] = 0;
	}
}

int main(){
	int n, u;
	crivo();
	while( scanf("%d", &n ) != EOF ){
		bool aux = 1;
		rep( i, 0, n ){
			scanf("%d", &u );
			if( !p[u] ) continue;
			if( !aux ) printf(" ");
			aux = 0;
			printf("%d", u );
		}
		if( aux ) printf("*");
		printf("\n");
	}
}

