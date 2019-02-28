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

int pd[1001][1001]; 
string s1, s2;

int solve( int i, int j ){
	if( i == s1.size() ) return ( s2.size() - j ) * 30;
	if( j == s2.size() ) return ( s1.size() - i ) * 15;
	if( pd[i][j] != -1 ) return pd[i][j];
	int ans = min( solve( i+1, j ) + 15, solve( i, j+1 ) + 30 );
	if( s1[i] == s2[j] ) ans = min( ans, solve( i+1, j+1 ) );
	return pd[i][j] = ans; 
}

int main(){
	while( cin >> s1 ){
		if( s1 == "#" ) break;
		cin >> s2;
		memset( pd, -1, sizeof pd );
		printf("%d\n", solve( 0, 0 ) );
	}
}

