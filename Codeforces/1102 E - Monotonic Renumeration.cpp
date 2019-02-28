#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( ll i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

const ll mod = 998244353;

int main(){
	ll n, a[200010], last;
	scanf("%I64d", &n );
	map<ll, ll> fst, lst;
	rep( i, 0, n ){
		scanf("%I64d", &a[i] );
		lst[a[i]] = max( i, lst[a[i]] ); 
		if( !fst.count(a[i])) fst[a[i]] = i;
	}
	ll ans = 0; last = -1;
	rep( i, 0, n ){
		if( fst[a[i]] > last ) ans++;
		last = max( last, lst[a[i]] );
	}
	ll exp = ans-1, b = 2; ans = 1;
	while( exp ){
		if( exp&1 ) ans = ( ans * b )%mod;
		b = (b*b)%mod;
		exp >>= 1;
	}
	cout << ans << "\n";
}

