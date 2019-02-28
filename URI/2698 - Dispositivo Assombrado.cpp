#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
typedef pair <ii, ll> iii;

int main(){
	
	ll n, c, q, p, x, a, b, cnt[100010], at, s;
	
	while( scanf("%lld%lld%lld", &n, &c, &q ) != EOF ){
		rep( i, 0, c+1 ) cnt[i] = 0;
		cnt[1] = n;
		set<iii> st;
		st.insert( iii( ii( n-1, 0 ), 1 ));
		while( q-- ){
			scanf("%lld%lld%lld%lld", &p, &x, &a, &b );
			ll s = cnt[p];
			ll a1 = ( a + s*s )%n;
			ll a2 = ( a + (s+b)*(s+b) )%n;	
			ll l = min( a1, a2 ), r = max( a1, a2 );
			set<iii> :: iterator it = st.lower_bound( iii(ii(l, 0), 0) );
			while( it != st.end() ){
				ii  aux = it->F;
				int cor = it->S;
				if( aux.S <= l ){
					if( aux.F <= r ){
						cnt[cor] -= (aux.F-l+1);
						st.insert(iii(ii(l-1, aux.S), cor));
					}
					else{
						cnt[cor] -= (r-l+1);
						st.insert(iii(ii(l-1, aux.S), cor));
						st.insert(iii(ii(aux.F, r+1), cor));
					}
				}
				else if( aux.S <= r ){
					if( aux.F <= r ){
						cnt[cor] -= (aux.F-aux.S+1);
					}
					else{
						cnt[cor] -= ( r-aux.S+1);
						st.insert(iii(ii(aux.F, r+1), cor));
					}
				}
				else break;
				st.erase(it);
				
				it = st.lower_bound( iii(ii(l, 0), 0) );
			}
			cnt[x] += r-l+1;
			st.insert(iii(ii(r, l), x ));
		}
		ll ans = 0;
		rep( i, 1, c+1 ) ans = max( ans, cnt[i] );
		printf("%lld\n", ans );
	}	
	
}
