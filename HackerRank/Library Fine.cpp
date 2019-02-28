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

int main(){

	int d1, m1, y1, d2, m2, y2;
	
	scanf("%d%d%d", &d1, &m1, &y1 );
	scanf("%d%d%d", &d2, &m2, &y2 );
	
	if( y1 > y2 ) printf("10000\n");
	else if( y1 < y2 ) printf("0\n");
	else if( m1 > m2 ) printf("%d\n", 500 * ( m1 - m2 ) );
	else if( m1 < m2 ) printf("0\n");
	else if( d1 > d2 ) printf("%d\n", 15  * ( d1 - d2 ) );
	else printf("0\n");
	
	return 0;
}

