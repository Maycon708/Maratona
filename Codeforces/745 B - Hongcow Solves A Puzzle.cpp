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

char s[1010][1010];
int l1, l2, c1, c2;

bool check(){
	rep( i, l1, l2+1 ){
		rep( j, c1, c2+1 ){
			if( s[i][j] != 'X' ) return 0;
		}
	}
	return 1;
}

int main(){
	int n, m;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ){
			scanf("%s", s[i] );
		}
		l1 = INF, c1 = INF, l2 = 0, c2 = 0;
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( s[i][j] != 'X' ) continue;
				l1 = min( l1, i );
				l2 = max( l2, i );
				c1 = min( c1, j );
				c2 = max( c2, j );
			}
		}
		if( check() ) printf("YES\n");
		else printf("NO\n");
	}
}

