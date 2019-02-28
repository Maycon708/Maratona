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

int main(){
	
	int t;
	scanf("%d", &t );
	while( t-- ){
		string resp;
		char mat[10][1000];
		rep( i, 0, 10 ) scanf("%s", mat[i] );
		int tam = strlen( mat[0] );
		rep( i, 1, tam-1 ){
			int a = 0;
			for( int j = 8; j > 0; j-- ){
				a <<= 1;
				a ^= ( mat[j][i] == '/' )? 0 : 1;
			}
			resp += char( a );
		}
		printf("%s\n", resp.c_str() );
	}
	
}

