#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for( int i = a; i < b; i++ )
#define mod 1000000007

typedef long long int ll;

int n, m, v[10010];
ll pd[10010];

ll solve( int p ){
	if( p >= n ) return 1;
	if( pd[p] != -1 ) return pd[p];
	ll ans = 0;
	rep( i, 0, m ){
		ans = ( ans + solve( p+v[i] ) )%mod;
	}
	return pd[p] = ans;
}

int main(){
    int t;
    scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &m );
		rep( i, 0, m ) scanf("%d", &v[i] );
		rep( i, 0, n ) pd[i] = -1;
		printf("%lld\n", solve(0) );	
	}
}
