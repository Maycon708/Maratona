#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

ll busca( ll n, ll m, ll k ){
	ll low = 1, high = n*m, ans;
	
	while( low <= high ){
		ll middle = (low+high)/2;
		ll cnt = 0;
		rep( i, 1, m+1 ){
			cnt += min( middle/i, n );
		}
		if( cnt >= k ){
			ans = middle;
			high = middle-1;
		}
		else{
			low = middle+1;
		}
	}
	return ans;
}

int main(){
	ll n, m, k;
	cin >> n >> m >> k;
	if( n > m ) swap( n, m );
	ll a = busca(n, m, k);
	ll b = busca(n, m, k+1);
	if( a == b ){
		cout << a << "\n";
		return 0;
	}
	if( k == 1 ){
		puts("1"); return 0;
	}	
	if( k == n * m ){
		cout << n*m << endl;
	}
	
	for( ll i = 1; i <= m; i++ ){
		ll x = (b-1)/i*i;
		if( x >= a && x < b && x/i <= n ){
			cout << x << "\n";
			break;
		}
	}
	
}
