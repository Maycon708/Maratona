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

vector<int> d[110], p;

const ll mod = 1e9+7;

ll eleva( ll b, ll e ){
	ll ans = 1;
	while( e ){
		if( e&1 ) ans = ( ans * b )%mod;
		b = ( b * b )%mod;
		e >>= 1;
	}
	return ans;
}

long double best;
vector<int> e, ans;

void solve( int valor, int i = 0, int menor = 111 ){
	if( i == p.size() ) return;
	if( valor == 1 ){
		long double x = 0;
		rep( i, 0, e.size() ) x += e[i] * log(p[i]);
		if( x+1e-9 <= best ) 
			ans = e, best = x;
		return;
	}
	for( auto x : d[valor] ){
		if( x > menor ) break;
		e[i] = x-1;
		solve( valor/x, i+1, x );
		e[i] = 0;
	}
}

int main(){
		
	rep( i, 1, 101 ){
		rep( j, 2, i+1 ){
			if( i%j == 0 ){
				d[i].pb(j);
			}
		}
		if( d[i].size() == 1 ) p.pb(i), e.pb(0);
	}
	int t, n;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		if( n == 1 ){
			puts("1");
			continue;
		}
		if( d[n].size() == 1 ){
			cout << eleva(2, n-1) << "\n";
			continue;
		}
		ans.pb(n);
		best = n*log(2);
		solve(n);
		ll aux = 1;
		rep( i, 0, ans.size() ){
			if( !ans[i] ) break;
			aux = ( aux * eleva(p[i], ans[i]) )%mod;
		}
		cout << aux << "\n";
	}
}

