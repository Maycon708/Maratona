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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

const int N = 5000010;

int v[N];
ll bit[2][N];

void update( int b, int x, int v ){
	for( int i = x; i < N; i += (i&-i) ) bit[b][i] += v;
}

ll query( int b, int x ){
	ll ans = 0;
	for( int i = x; i > 0; i -= (i&-i) ) ans += bit[b][i];
	return ans;
}

int main(){
	
	int t, n, q, op, a, b;
	
	scanf("%d", &t );
	
	while( t-- && scanf("%d", &n ) != EOF ){
		memset( bit, 0, sizeof bit );
		scanf("%d", &q );
		multiset<int> st;
		rep( i, 1, n+1 ){
			update( 0, i, 1 );
			update( 1, i, i );
			st.insert(i);
			v[i] = i;
		}
		while( q-- ){
			scanf("%d", &op );
			if( op == 1 ){
				scanf("%d%d", &a, &b );
				st.erase( st.find(v[a]) );
				st.insert(b);
				update(0, v[a], -1);
				update(1, v[a], -v[a]);
				update(0, b, 1);
				update(1, b, b);
				v[a] = b;
			}
			else{
				int lo = *(st.begin());
				int hi = *(--st.end());
				int mid = (lo+hi)/2;
				ll aa = query(0, mid), bb = query(1, mid), cc = query(1, n);
				ll ans = (hi-mid)*aa+(mid*aa-bb)+(mid-lo)*(n-aa)+(cc-bb-mid*(n-aa))-(hi-lo);
				printf("%lld\n", ans );
			}
		}
	}
		
}
