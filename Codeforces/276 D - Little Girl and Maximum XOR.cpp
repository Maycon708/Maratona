#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	ll a = 0, b = LLONG_MAX;
	ll l, r;
	cin >> l >> r;
	for( int i = 62; i >= 0; i-- ){
		b &= ~(1LL<<i);
		a |= (1LL<<i);
		if( b < l ) b |= (1LL<<i);
		if( a > r ) a &= ~(1LL<<i);
		if( b >= l  && b <= r && a >= l && a <= r ) break;
	}
	cout << (a^b) << "\n";
	
}
