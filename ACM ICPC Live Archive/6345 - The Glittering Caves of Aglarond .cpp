#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

int main(){
	
	int t, n, m, k;
	char mat[55][55];
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d%d", &n, &m, &k );
		rep( i, 0, n ) scanf("%s", mat[i] );
		int ans = 0;
		priority_queue<int> pq;
		rep( i, 0, n ){
			int l = 0;
			rep( j, 0, m ){
				l += ( mat[i][j] == '.' );
			}
			ans += ( m - l );
			pq.push( l );
		}
		while( k-- ){
			int a = pq.top();
			pq.pop();
			ans -= ( m - a );
			ans += a;
			pq.push( m - a );
		}
		printf("%d\n", ans );
	}
	return 0;
}
