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
	int mat[111][111], n, a, b, c, d;
	
	while( scanf("%d", &n ) != EOF ){
		memset( mat, 0, sizeof mat );
		while( n-- ){
			scanf("%d%d%d%d", &a, &c, &b, &d );
			rep( i, a, c )
				rep( j, b, d )
					mat[i][j] = 1;
		}
		int cnt = 0;
		rep( i, 0, 111 ){
			rep( j, 0, 111 ){
				cnt += mat[i][j];
			}
		}
		printf("%d\n", cnt );
	}
}

