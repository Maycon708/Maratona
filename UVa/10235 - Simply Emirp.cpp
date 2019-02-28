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

int p[1000100];

void crivo(){
	memset( p, 1, sizeof p );
	p[0] = p[1] = 0;
	for( int i = 2; i <= 1000000; i++ ){
		if( !p[i] ) continue;
		for( int j = i+i; j <= 1000000; j += i ) p[j] = 0;
	}
}

int R( int n ){
	int ans = 0;
	while( n ){
		ans *= 10;
		ans += ( n%10 );
		n /= 10;
	}
	return ans;
}

int main(){
	crivo();
	int n;
	while( scanf("%d", &n ) != EOF ){
		if( !p[n] ) printf("%d is not prime.\n", n );
		else if( p[R(n)] && n != R(n) ) printf("%d is emirp.\n", n );
		else printf("%d is prime.\n", n );
	}
}

