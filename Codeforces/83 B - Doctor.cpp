#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	ll n, k, t[100100], sum = 0;
	
	scanf("%I64d%I64d", &n, &k );
	rep( i, 0, n ){
		scanf("%I64d", &t[i] );
		sum += t[i];
	}
	
	if( sum < k ){
		puts("-1");
		return 0;
	}
	ll lo = 1, hi = 1e9, mid, x;
	while( lo <= hi ){
		mid = (lo+hi)/2;
		sum = 0;
		rep( i, 0, n ) sum += min( t[i], mid );
		if( sum > k ) hi = mid-1;
		else{
			x = mid;
			lo = mid+1;
		}
	}
	
	rep( i, 0, n ){
		k -= min( t[i], x );
		t[i] -= x;
	}
	int p;
	for( p = 0; k; p++ ){
		if( t[p] > 0 ) k--, t[p]--;
	}
	rep( i, p, n ) if( t[i] > 0 ) printf("%d ", i+1 );
	rep( i, 0, p ) if( t[i] > 0 ) printf("%d ", i+1 );
	printf("\n");
}

