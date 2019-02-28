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

	int n, k;
	char s[111];
	scanf("%d", &n );
	scanf("%s",  s );
	scanf("%d", &k );
	
	rep( i, 0, n ){
		if( s[i] >= 'a' && s[i] <= 'z' ){
			int u = s[i] - 'a';
			int v = ( u + k )%26;
			printf("%c", char( 'a' + v ) );
		}
		else if( s[i] >= 'A' && s[i] <= 'Z' ){
			int u = s[i] - 'A';
			int v = ( u + k )%26;
			printf("%c", char( 'A' + v ) );
		}
		else printf("%c", s[i] );
	}
	printf("\n");
	
}

