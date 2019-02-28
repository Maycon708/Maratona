#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	ll n, v[505], ans[505];
	ll dist[505][505];
	ll has[505];
	cin >> n;
	rep( i, 0, n )
		rep( j, 0, n )
			cin >> dist[i][j];
	
	rep( i, 0, n ){
		has[i] = 0;
		cin >> v[n-i];
	}
	
	for( int k = 1; k <= n; k++ ){
		ans[k] = 0;
		int x = v[k]-1;
		has[x] = 1;
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ ){
				dist[i][j] = min( dist[i][j], dist[i][x] + dist[x][j] );
				if( has[i] && has[j] ) ans[k] += dist[i][j];
			}
	}
	rep( i, 0, n ){
		printf("%I64d%s", ans[n-i], i+1 == n ? "\n" : " ");
	}
}
