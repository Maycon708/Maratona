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

int main(){
	int n, m, mat[501][501];
	while( cin >> n >> m ){
		rep( i, 0, n ){ rep( j, 0, m ) cin >> mat[i][j]; mat[i][m] = 1; }
		int ans = 1, last = -1;
		rep( i, 0, n ){
			rep( j, 0, m+1 ){
				if( mat[i][j] ){
					if( j <= last && j != m ) ans = 0;
					last = j;
					break;
				}
			}
		}
		
		printf("%c\n", ans ? 'S' : 'N' );
	}
}

