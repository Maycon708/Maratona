#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	int n, m, K;
	char mat[303][303];
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	
	scanf("%d%d%d", &n, &m, &K );
	rep( i, 0, n ) scanf("%s", mat[i] );
	
	rep( tam, 1, min(n,m)/2+1 ){
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( mat[i][j] != '*' ) continue;
				bool check = 1;
				rep( k, 0, 4 ){
					int x = i + dx[k]*tam, y = j + dy[k]*tam;
					if( x < 0 || x >= n || y < 0 || y >= m || mat[x][y] != '*' ) check = 0;
				}
				if( check ) K--;
				if( K ) continue;
				printf("%d %d\n", i+1, j+1 );
				rep( k, 0, 4 ){
					int x = i + dx[k]*tam, y = j + dy[k]*tam;
					printf("%d %d\n", x+1, y+1 );
				}
				return 0;
			}
		}
	}
	printf("-1\n");
	
}

