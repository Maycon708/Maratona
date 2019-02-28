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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef unsigned long long int ll;

int main(){

	ll ans = 0, v[50], p[50];
	char s[30];
	while( scanf("%s", s ) != EOF ){
		p[0] = strtol( s, NULL, 2 );
		rep( i, 1, 32 ){
			scanf("%s", s );
			p[i] = strtol( s, NULL, 2 );
		}
		int ans = 0, pos = 0;
		while( 1 ){
			int op = p[pos] >> 5, x = p[pos]%32;
			pos = ( pos+1 )%32;
			switch( op ){
				case 0: p[x] = ans; continue;
				case 1: ans = p[x]; continue;
				case 2: if( !ans ) pos = x; continue;
				case 3: continue;
				case 4: ans = ( ans + 255 )%256; continue;
				case 5: ans = ( ans + 1 )%256; continue;
				case 6: pos = x; continue;
			}
			break;
		}
		for( int i = 7; i >= 0; i-- )
			printf("%d", ( ans & ( 1 << i ) ) ? 1 : 0 );
		printf("\n");
	}
}
