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

long double dist[20][20], pd[400][20][20];

void D(){
	int mat[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
	rep( i, 0, 4 ){
		rep( j, 0, 3 ){
			rep( k, 0, 4 ){
				rep( l, 0, 3 ){
					int a = mat[i][j], b = mat[k][l];
					dist[b][a] = dist[a][b] = hypot( i - k, j - l )/30.0;
				}
			}
		}
	}
}

int C( char c ){
	int aux[] = { 2,2,2, 3,3,3, 4,4,4, 5,5,5, 6,6,6, 7,7,7,7, 8,8,8, 9,9,9,9 };
	
	if(c == '#') return 12;
	if(c == ' ') return 11;
	return aux[ c-'a' ];
}

int Q( char c ){
	int aux[] = { 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4 };
	
	if( c == '#' || c == ' ') return 1;
	return aux[c-'a'];
}

string s;

long double solve( int pos, int a, int b ){
	if( pos == s.size() ) return 0;
	if( pd[pos][a][b] > -1 ) return pd[pos][a][b];
	
	int c = C( s[pos] );
	int qttd = Q( s[pos] );
	
	long double ans = solve( pos+1, c, b ) + dist[a][c];
	ans = min( ans, solve( pos+1, a, c ) + dist[b][c] ) + qttd * 0.2;
	return pd[pos][a][b] = ans;
}

inline bool same( char a, char b ){
	int aa = C( a ), bb = C( b );
	return aa == bb;
}

int main(){
	
//	freopen( "out.txt", "w", stdout );
	char aux[10000];
	D();
	while( gets( aux ) ){
		int tam = strlen( aux );
		s.clear();
		s += aux[0];
		rep( i, 1, tam ){
			if( same( aux[i], aux[i-1] ) ) s += '#';
			s += aux[i];
		}
		memset( pd, -INF, sizeof pd );
		long double ans = solve( 0, 4, 6 );
		cout << fixed << setprecision(2) << ans << "\n";
	}
}
