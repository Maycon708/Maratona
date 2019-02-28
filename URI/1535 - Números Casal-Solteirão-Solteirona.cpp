#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ii check( ll n ){
	if( !n ) return ii(2, 2);
	bool aux = 0;
	if( n < 0 ) aux = 1, n *= -1;
	for( ll i = sqrt(n); i > 0; i-- ){
		if( n%i || (i+n/i)&1 ) continue;
		ll a = ( i + n/i )/2;
		ll b = ( n/i - i )/2;
		if( !aux ) return ii( a, b );
		else return ii( b, a );
	}
	return ii(-1, -1);
}

ll sum( int n ){
	if( n < 0 ) n *= -1;
	if( n < 2 ) return 0;
	return (n-2)/4+1;
}

int main(){
	ll a, b;
	string s;
	
	while( getline( cin, s ) ){
		stringstream ss;
		ss << s;
		ss >> a;
		if( ss >> b ){
			if( a * b > 0 ) printf("%lld\n", sum(b) - sum(a-1) );
			else printf("%lld\n", sum(a) + sum(b) );
		}
		else{
			ii ans = check(a);
			if( ans.F == -1 ) printf("%s\n", a&1? "Spinster Number.":"Bachelor Number.");
			else printf("%d %d\n", ans.F, ans.S );
		}
	}
}

