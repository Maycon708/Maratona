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

inline bool C( char a, char b ){
	if( a > b ) swap( a, b );
	return ( a == 'B' && b == 'S' ) || ( a == 'C' && b == 'F');
}

int main(){

	char c[500];
	while( gets( c ) ){
		int tam = strlen( c );
		stack < char > s;
		int cnt = 0;
		rep( i, 0, tam ){
			if( s.empty() ) s.push( c[i] );
			else if( C( s.top(), c[i] ) ){
				s.pop(); cnt++;
			}
			else s.push( c[i] );
		}
		printf("%d\n", cnt );
	}
}

