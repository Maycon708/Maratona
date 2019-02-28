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

bool C( int a, int b, int c, int d ){
	int aa = __gcd( a, b );
	int bb = __gcd( c, d );
	a /= aa, b /= aa, c /= bb, d /= bb;
	return ( a == c && b == d ) || ( a == d && c == b );
}

int main(){
	int a, b, c, d;	
	while( scanf("%d%d%d%d", &a, &b, &c, &d ) != EOF ){
		if( C( a, b, c, d ) || C( a, c, b, d ) || C( a, d, b, c ) ) puts("S");
		else puts("N");
	}
}

