#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int n, m;
char mat[505][505];
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

bool dentro( int x, int y ){
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main(){
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ){
			scanf("%s", mat[i] );
			rep( j, 0, m ) if( mat[i][j] == '.') mat[i][j] = 'D';
		}
		bool cant = 0;
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( mat[i][j] == 'W' ){
					rep( k, 0, 4 ){
						int x = i+dx[k], y = j + dy[k];
						if( dentro(x, y) && mat[x][y] == 'S') cant = 1;
						
					}
				}
			}
		}
		if( cant ) puts("No");
		else{
			puts("Yes");
			rep( i, 0, n ) printf("%s\n", mat[i] );
		}
	}
	
	
	return 0;
}
