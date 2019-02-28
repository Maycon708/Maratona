#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define F first
#define S second

using namespace std;

typedef long long int ll;
const int mod = 1e9+7;
ll sum[200202];
vector<int> adj[200202];

int main(){
	int n, m, a[100100], b[100100];
	map<int, int> mp;
	cin >> n >> m;
	mp[0]  = mp[n] = 0;
	rep( i, 0, m ){
		scanf("%d%d", &a[i], &b[i] );
		mp[a[i]] = mp[b[i]] = 0;
	}
	n = 1;
	for( auto x : mp ){
		mp[x.F] = n++;
	}
	rep( i, 0, m ){
		adj[mp[b[i]]].pb( mp[a[i]] );
	}
	sum[1] = 1;
	for( int i = 2; i < n; i++ ){
		ll aux = 0;
		for( auto v : adj[i] ){
			aux = ( aux + sum[i-1] - sum[v-1] )%mod;
		}
		sum[i] = sum[i-1]+aux;
	}
	cout << sum[n-1]-sum[n-2] << "\n";
}

