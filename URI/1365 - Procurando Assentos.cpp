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

	int n, m, k, mat[330][330], sum[330];
	char aux[330][330];
	while( scanf("%d%d%d", &n, &m, &k ) != EOF ){
		if( !n ) break;
		rep( i, 0, n ) scanf("%s", aux[i] );
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( aux[i][j] == '.' ) mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}
	
		int resp = INF;
		rep( l, 0, m ){
			rep( i, 0, n ) sum[i] = 0;
			rep( r, l, m ){
				rep( i, 0, n ) sum[i] += mat[i][r];
				int s = 0, i = 0, j = 0;
				while( j != n ){
					s += sum[j];
					while( s >= k && i <= j ){
						resp = min( resp, ( r - l + 1 ) * ( j - i + 1 ) );
						s -= sum[i++];
					}
					j++;
				}
			}
		}
		printf("%d\n", resp );
	}
}

