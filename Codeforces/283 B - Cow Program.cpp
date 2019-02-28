#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

ll cor[200018][2], n, a[200018], ans[200018][2];

void dfs( int u, int t ){
	int v = u + a[u] * (t ? -1 : 1);
	cor[u][t] = -1;
	if( v <= 0 || v > n ){
		cor[u][t] = 1;
		ans[u][t] = a[u];
		return;
	}
	if( v == 1 || cor[v][t^1] == -1 ){
		cor[u][t] = 1;
		ans[u][t] = -1;
		return;
	}
	if( !cor[v][t^1] ) dfs( v, t^1 );
	if( ans[v][t^1] == -1 ) ans[u][t] = -1;
	else ans[u][t] = ans[v][t^1] + a[u];
	cor[u][t] = 1;
}

int main(){
	
	scanf("%I64d", &n );
	rep( i, 2, n+1 ) scanf("%I64d", &a[i] );
	rep( i, 2, n+1 ) if( !cor[i][1] ) dfs(i, 1);
	rep( i, 1, n ) printf("%I64d\n", ans[1+i][1] == -1? -1 : i+ans[1+i][1] );
		
}

