#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

char mat[5005][5005];
int aux[5005][5005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m );
	rep( i, 0, n ) scanf("%s", mat[i] );
	rep( i, 0, n ) rep( j, 0, m ) if( mat[i][j] == '1' ) aux[i][j] = 1 + (j? aux[i][j-1]:0);
	int ans = 0, cnt[5005];
	rep( j, 0, m ){
		rep( i, 0, m+1 ) cnt[i] = 0;
		rep( i, 0, n ) cnt[ aux[i][j] ]++;
		int t = 0;
		for( int i = m; i > 0; i-- ) t += cnt[i], ans = max( ans, i * t );
	}
	
	
	cout << ans << endl;
	
}

