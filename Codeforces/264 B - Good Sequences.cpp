#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

vector<int> adj[100100];
int done[100100];
int has[100100];
int pd[100100];

void crivo( int n ){
	pd[0] = pd[1] = -1;
	for( int i = 2; i <= n; i++ ){
		pd[i] = -1;
		int last = 0;
		if( done[i] ) continue;
		for( int j = i; j <= n; j+= i ){
			if( has[j] ){
				adj[last].pb(j);
				last = j;
			}
			done[j] = 1;
		}
	}
}

int solve( int u ){
	int &ans = pd[u];
	if( ans == -1 ){
		ans = 0;
		for( auto x : adj[u] ) ans = max( ans, solve(x) + 1 );
	}
	return ans;
}

int main(){
	int n, good, mx = 0;
	scanf("%d", &n );
	rep( i, 0, n ){
		scanf("%d", &good );
		if( good == 1 ) adj[0].pb(1);
		has[good] = 1;
		mx = max( mx, good );
	}
	crivo(mx);
	cout << solve(0) << endl;
}
