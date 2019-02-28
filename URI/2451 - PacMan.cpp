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
	int n; char mat[101][101];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) cin >> mat[i];
		int ans = 0, cnt = 0;
		for( int i = 0; i < n; i ++ ){
			if( !(i&1) )
				for( int j = 0; j < n; j++ ){
					if( mat[i][j] == 'o' ) cnt++;
					if( mat[i][j] == 'A' ) cnt = 0;
					ans = max( ans, cnt );
				}
			else
				for( int j = n-1; j >= 0; j-- ){
					if( mat[i][j] == 'o' ) cnt++;
					if( mat[i][j] == 'A' ) cnt = 0;
					ans = max( ans, cnt );
				}
		} 
		printf("%d\n", ans );
	}
}

