#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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

int pd[1001][101], n, m;
char s1[1001], s2[1001];

int solve( int i, int j ){
	if( j == m ) return 1;
	if( i == n ) return 0;
	if( pd[i][j] != -1 ) return pd[i][j];
	int ans = solve( i+1, j );
	if( s1[i] == s2[j] ) ans += solve( i+1, j+1 );
	return pd[i][j] = ans;
}

int main(){
	int t = 1;
	while( scanf("%d%d", &m, &n ) != EOF ){
		if( !n && !m ) break;
		scanf("%s", s2 );
		scanf("%s", s1 );
		memset( pd, -1, sizeof pd );
		printf("Instancia %d\n", t++ );
		printf("%d\n", solve( 0, 0 ) );
		printf("\n");
	}
}

