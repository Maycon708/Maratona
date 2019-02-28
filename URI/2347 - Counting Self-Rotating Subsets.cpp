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

const int mod = 1e9 + 7;
const int N = 2016;

ll C[N][N];
void pre_calc(){
	rep( i, 0, N ){
		C[i][i] = C[i][0] = 1;
		rep( j, 1, i ){
			C[i][j] = ( C[i-1][j] + C[i-1][j-1] )%mod;
		}
	}
}

int main(){
	
	ll n, x, y;
	pre_calc();
	
	while( scanf("%lld", &n ) != EOF ){
		
		set<ii> st;
		map<ii, int> mp;
		map<ii, int> :: iterator it;
		vector<ii> v;
		vector<int> odd(N, 0), even(N, 0), ans(N, 0);

		rep( i, 0, n ){
			scanf("%lld%lld", &x, &y );
			x <<= 1, y <<= 1;
			v.pb( ii( x, y ) );
			st.insert( ii( x, y ) );
		}
		
		rep( i, 0, n ){
			rep( j, i+1, n ){
				x = ( v[i].F + v[j].F ) >> 1; 
				y = ( v[i].S + v[j].S ) >> 1;
				mp[ ii(x,y) ]++; 
			}
		}
		for( it = mp.begin(); it != mp.end(); it++ ){
			ii aux = it -> F;
			int qttd = it -> S;
			if( st.count(aux) ) odd[qttd]++;
			even[qttd]++;
		}
		
		rep( P, 1, n+1 ){
			rep( p, 0, P+1 ){
				ans[2*p] = ( ans[2*p] + C[P][p] * even[P] )%mod;
				ans[2*p + 1] = ( ans[2*p + 1] + C[P][p] * odd[P] )%mod;
			}
		}
		
		printf("%lld", n );		
		rep( i, 2, n+1 ){
			printf(" %lld", ans[i] );
		}
		printf("\n");
	}
	
}

