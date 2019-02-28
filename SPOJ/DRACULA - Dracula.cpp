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

ll pd[20][2][200];
string s;

ll solve( int p, int pref, int k ){
	if( p == s.size() ) return !k;
	ll &ans = pd[p][pref][k];
	if( ans == -1 ){
		ans = 0;
		for( int i = 0; i < 10; i++ ){
			if( pref && i > s[p]-'0' || i > k ) break;
			ans += solve( p+1, pref && (i == s[p]-'0'), k-i );	
		}
	}
	return ans;
}

void S( ll a ){
	stringstream ss;
	ss << a;
	ss >> s;
}

int main(){
	ll a, b, x;
	ll aa[200], bb[200];
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%lld%lld%lld", &a, &b, &x );
		if( a > b ) swap( a, b );
		S(a-1);
		rep( i, 1, 200 ){
			memset( pd, -1, sizeof pd );
			aa[i] = solve(0, 1, i);
		}
		S(b);
		rep( i, 1, 200 ){
			memset( pd, -1, sizeof pd );
			bb[i] = solve(0, 1, i);
		}
		ll cnt = 0;
		rep( i, 1, 200 ){
			ll aux = min( bb[i]-aa[i], x/i );
			cnt += aux;
			x -= aux*i;
		}
		cout << cnt << "\n";
	}
}

