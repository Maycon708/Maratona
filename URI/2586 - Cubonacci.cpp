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

int dentro( int x, int y, int z ){
	return x >= 0 && x < 3 && y >= 0 && y < 3 && z >= 0 && z < 3;
}

int main(){
	ll t, mat[2][3][3][3], n;
	int dx[] = {  1,  0, -1,  1,  0, -1,  1,  0, -1,  1,  0, -1,  1,  0, -1,  1,  0, -1,  1,  0, -1,  1,  0, -1,  1,  0, -1 };
	int dy[] = {  1,  1,  1,  0,  0,  0, -1, -1, -1,  1,  1,  1,  0,  0,  0, -1, -1, -1,  1,  1,  1,  0,  0,  0, -1, -1, -1 };
	int dz[] = {  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	scanf("%lld", &t );
	while( t-- ){
		scanf("%lld", &n );
		rep( i, 0, 3 ){
			rep( j, 0, 3 ){
				rep( k, 0, 3 ){
					scanf("%lld", &mat[0][i][j][k] );
				}
			}
		}
		int a = 0, b = 1;
		while( n-- ){
			swap( a, b );
			rep( i, 0, 3 ){
				rep( j, 0, 3 ){
					rep( k, 0, 3 ){
						mat[a][i][j][k] = 0;
						rep( l, 0, 27 ){
							int x = i + dx[l], y = j + dy[l], z = k + dz[l];
							if( dentro( x, y, z ) ) mat[a][i][j][k] += mat[b][x][y][z];
						}
					}
				}
			}
		}
		rep( i, 0, 3 ){
			rep( j, 0, 3 ){
				rep( k, 0, 3 ){
					if( k ) printf(" ");
					printf("%lld", mat[a][i][j][k] ); 
				}
				printf("\n");
			}
		} 
	}	
}
