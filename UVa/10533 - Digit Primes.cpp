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

#define N 1000100

int p[N], sum[N];

void crivo(){
	memset( p, 1, sizeof p );
	p[0] = p[1] = 0;
	for( int i = 2; i < N; i++ ){
		if( !p[i] ) continue;
		for( int j = i+i; j < N; j += i ) p[j] = 0; 
	}
}

void pre(){
	crivo();
	sum[0] = sum[1] = 0;
	for( int i = 2; i < N; i++ ){
		sum[i] = sum[i-1];
		if( !p[i] ) continue;
		int a = 0;
		for( int j = i; j; j /= 10 )  a += ( j%10 );
		sum[i] += ( p[a] != 0 );
	}
}

int main(){
	
	int t, a, b;
	
	pre();
	
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &a, &b );
		printf("%d\n", sum[b] - sum[a-1] );
	}
	
}

