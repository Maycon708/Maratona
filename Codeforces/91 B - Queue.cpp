#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

#define N 100100

int bit[N];

void update( int x, int v ){
	for( int i = x; i < N; i += (i&-i) ) bit[i] = max( bit[i], v );
}

int query( int x ){
	int ans = 0;
	for( int i = x; i > 0; i -= (i&-i) ) ans = max( ans, bit[i] );
	return ans;
}

int main(){
	map<int, int> mp;
	int n, v[N], aux[N];
	cin>> n;
	rep( i, 0, n ) scanf("%d", &v[i] ), aux[i] = v[i];
	int cnt = 1;
	sort( aux, aux+n );
	rep( i, 0, n ) if( !mp.count(aux[i]) ) mp[aux[i]] = cnt++;
	rep( i, 0, n ) v[i] = mp[v[i]];
	for( int i = n-1; i >= 0; i-- ){
		aux[i] = max( -1, query(v[i]-1)-i-1 );
		update( v[i], i );
		
	}
	rep( i, 0, n ) printf("%d%s", aux[i], (i+1==n)? "\n":" ");
}

