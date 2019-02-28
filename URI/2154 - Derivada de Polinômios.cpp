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
typedef long long int ll;

int main(){

	int n, c[111], e[111];
	char s[111];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			if( i ) cin >> s[i];
			scanf("%dx%d", &c[i], &e[i] );
		}
		rep( i, 0, n ){
			if( i ) printf(" %c ", s[i] );
			printf("%dx", c[i] * e[i] );
			if( e[i] > 2 ) printf("%d", e[i]-1 );
		}
		printf("\n");
	}

}
