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

int main(){
	int x, y, l, c;
	char s[100];
	while( scanf("%d%d%s", &x, &y, s ) != EOF ){
		if( !x || !y ) break;
		switch(s[0]){
			case 'N': l = 0, c = 0; break;
			case 'S': l = 1, c = 1; break;
			case 'O': l = 1, c = 0; break;
			case 'L': l = 0, c = 1; break;
		}
		int gcd = __gcd( x, y );
		int p = 100/gcd;
		if( 100.0/gcd - p > 0.5 ) p++;
		printf("%3d%%%10d", p, x/gcd + y/gcd -2 );
		
		for( ; !(x&1) && !(y&1); y >>= 1, x >>= 1 );
		if( x&1 ) c ^= 1;
		if( y&1 ) l ^= 1;
		if( c ) printf(" %s\n", l? "Sul" : "Leste");
		else printf(" %s\n", l? "Oeste" : "Norte");
	}
}

