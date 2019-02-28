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

int mp( string s ){
	char c = s[0];
	if( s == "10" || c == 'J' || c == 'Q' || c == 'K' ) return 10;
	if( c == 'A' ) return 11;
	return c-'0';
}

int main(){

	int n, m, x;
	char c[3];
	int aux[] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		vector<long double> dp;
		vector<bool> check;
		rep( i, 0, m ) dp.pb(0), check.pb(0);
		rep( i, 0, n ){
			scanf("%s", c );
			x = mp(c);
			dp.pb(1), check.pb(1);
			rep( i, 1, x ) dp.pb(0), check.pb(0);
		}
		for( int i = dp.size()-1; i >= 0; i-- ){
			if( check[i] ) continue;
			for( auto j : aux ){
				if( i+j >= dp.size() ) continue;
				dp[i] += (dp[i+j]/13);
			}
		}	
		long double ans = 0;
		rep( i, 1, 11 ) ans += dp[i]/10;
		printf("%.15LF\n", ans );
	}

}

