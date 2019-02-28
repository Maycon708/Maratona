#include <bits/stdc++.h>

#define INF 200*18+10
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
#define EPS 1e-12

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
typedef long double ld;

const ll mod = 1e9+7;

ll pd[100100][2], n, m, s1[100100], s2[100100], mmi;

ll solve( int p, int check ){
	if( p == n ) return check;
	ll &ans = pd[p][check];
	if( ans == -1 ){
		if( check == 1 ){
			if( s1[p] == 0 ){
				if( s2[p] == 0 ){
					ans = ((m*m)%mod*solve(p+1, 1))%mod;
				}
				else ans = (m*solve(p+1, 1))%mod;
			}
			else{
				if( s2[p] == 0 ){
					ans = (m*solve(p+1, 1))%mod;
				}
				else ans = solve(p+1, 1);
			}
		}
		else{
			if( s1[p] == 0 ){
				if( s2[p] == 0 ){
					ans = (( m * solve(p+1, 0) )%mod + (mmi * solve(p+1, 1))%mod )%mod;
				}
				else{
					ans = (solve(p+1, 0) + (solve(p+1, 1) * (m-s2[p]))%mod )%mod;
				}
			}
			else{
				if( s2[p] == 0 ){
					ans = (solve(p+1, 0) + (solve(p+1, 1) * (s1[p]-1))%mod )%mod;
				}
				else{
					if( s1[p] < s2[p] ) return 0;
					else ans = solve(p+1, s1[p] > s2[p] );
				}
			}
		}
	}
	return ans;
}

ll fastExp( ll b, ll e ){
	ll ans = 1	;
	while( e ){
		if( e&1 ) ans = (ans * b)%mod;
		b = ( b * b )%mod;
		e >>= 1;
	}
	return ans;
}

int main(){
	
	while( cin >> n >> m ){
		mmi = 0;
		for( int i = 1 ; i < m; i++ ){
			mmi = ( mmi + (m-i) )%mod;
		}
		ll c1 = 0, c2 = 0;
		rep( i, 0, n ) scanf("%lld", &s1[i] ), c1 += (s1[i] == 0);
		rep( i, 0, n ) scanf("%lld", &s2[i] ), c2 += (s2[i] == 0);
		
		
		ll dem = ( fastExp(m, c1) * fastExp(m, c2) )%mod;
		dem = fastExp( dem, mod-2 );
		memset( pd, -1, sizeof pd );
		ll num = solve(0, 0);
		
		printf("%lld\n", (num*dem)%mod );
		
	}
		
	
}
