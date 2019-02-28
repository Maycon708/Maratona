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

int n, m, mat[606][606], lis[606][606];

int main(){
	int q, a, b, t = 1;
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		rep( i, 0, n ){
			rep( j, 0, m ){
				scanf("%d", &mat[i][j] );
			}
		}
		int ans = 0;
		rep( j, 0, m ){
			stack<ii> s;
			rep( i, 0, n ){
				int k, u;
				for( k = j+1; k < m && mat[i][k] > mat[i][k-1]; k++ );
				if( i+1 != n )
					for( u = j; u < k && mat[i][u] < mat[i+1][j]; u++ ); 
				else u = k;
				u -= j;	k -= j;
				int id = i;
				ans = max( ans, k );
				while( s.size() && s.top().S >= u ){
					ii a = s.top(); s.pop();
					ans = max( ans, ( i - a.F ) * a.S );
					ans = max( ans, ( i - a.F + 1 ) * min( a.S, k ) );
					id = a.F;
				}
				s.push( ii( id, u ) );	
			}
			while( !s.empty() ){
				ii a = s.top(); s.pop();
				ans = max( ans, ( n - a.F ) * a.S );
			}
		}
		printf("%d\n", ans );
	}
}

