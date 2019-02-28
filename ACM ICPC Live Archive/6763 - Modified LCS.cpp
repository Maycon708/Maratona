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

ll myGcd( ll a, ll b, ll &x, ll &y ){
	if( !a ){
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll c = myGcd( b%a, a, x1, y1 );
	y = x1;
	x = y1 - b/a * x1;
	return c;
}

int main(){
	int t;
	
	scanf("%d", &t );
	ll n1, f1, d1, n2, d2, f2;
	while( t-- ){
		scanf("%lld%lld%lld%lld%lld%lld", &n1, &f1, &d1, &n2, &f2, &d2 );
		ll gcd, x, y, c = f2-f1;
		gcd = myGcd( d1, -d2, x, y );
		if( c%gcd ){
			puts("0");
			continue;
		}
		if( !c ) x = y = 0;
		ll xx = d2/__gcd(d1, d2), yy = d1/__gcd(d1, d2);
		x *= c/gcd;
		y *= c/gcd;
		while( x >= xx && y >= yy ) x -= xx, y -= yy;
		while( x < 0 || y < 0 ) x+=xx, y+=yy;
		ll a1 = (n1-x+(xx-1))/xx, a2 = (n2-y+(yy-1))/yy;
		cout << min(a1, a2) << "\n";
	}
}

