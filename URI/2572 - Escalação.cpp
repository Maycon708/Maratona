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

#define N 200010
#define mod 1000000007

vector<int> tree[4*N], v;
int a[N];

void build( int no, int i, int j, int k ){
	tree[no].clear();
	if( i == j ){
		if( a[i] )
			tree[no].pb( -a[i] );
		return;
	}
	int L = no << 1, R = L+1, mid = (i+j) >> 1;
	build( L, i, mid, k );
	build( R, mid+1, j, k );
	
	merge( tree[L].begin(), tree[L].end(), tree[R].begin(), tree[R].end(), back_inserter(tree[no]) );	
	while( tree[no].size() > k ) tree[no].pop_back();
}


vector<int> query( int no, int i, int j, int a, int b, int k ){
	vector<int> aa, bb, cc;
	if( i > b || j < a ) return cc;
	if( i >= a && j <= b ) return tree[no];
	
	int L = no << 1, R = L+1, mid = (i+j) >> 1;
	
	aa = query( L, i, mid, a, b, k );
	bb = query( R, mid+1, j, a, b, k );
	merge( aa.begin(), aa.end(), bb.begin(), bb.end(), back_inserter(cc) );
	while( cc.size() > k ) cc.pop_back();	
	return cc;
}

int main(){
	int n, k, x, y, q;
	while( scanf("%d%d%d", &n, &k, &q ) != EOF ){
		for( int i = 0; i < n; i++ ){
			scanf("%d", &a[i] );
		}
		build( 1, 0, n-1, k );
		while( q-- ){
			scanf("%d%d", &x, &y );
			vector<int> ans = query( 1, 0, n-1, x-1, y-1, k );
			ll resp = !ans.empty();
			rep( i, 0, (int)ans.size() ){
				resp = ( resp * (ll)-ans[i] )%mod;
			}
			printf("%lld\n", resp );
		}
	}
}
