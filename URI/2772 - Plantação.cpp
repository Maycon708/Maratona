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
#define N 100100
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int tree[4*N], cnt, dead[4*N], tempo, k, ans[N];
vector<ii> lazy[4*N];

void propagate( int no, int i, int j ){
	if( lazy[no].empty() ) return;
	int last = tree[no];
	rep( k, 0, lazy[no].size() ){
		if( last + tempo < lazy[no][k].F ){
			dead[no] = 1;
			return;
		}
		last = lazy[no][k].S;
	}
	tree[no] = last;
	if( i != j ){
		lazy[2*no].pb( ii( lazy[no][0].F, last) );
		lazy[2*no+1].pb( ii( lazy[no][0].F, last) );
	}
	lazy[no].clear();
}

void build( int no, int i, int j ){
	tree[no] = 0;
	lazy[no].clear();
	dead[no] = 0;
	if( i == j ) return;
	int L = 2*no, R = L+1, mid = (i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
}

void update( int no, int i, int j, int a, int b, int v ){
	propagate( no, i, j );
	if( a > j || b < i || dead[no] ) return;
	if( i >= a && j <= b ){
		lazy[no].pb( ii(v, v) );
		propagate(no, i, j);
		return;
	}
	int L = 2*no, R = L+1, mid = (i+j)/2;
	update(L, i, mid, a, b, v);
	update(R, mid+1, j, a, b, v);
	dead[no] = dead[L] & dead[R];
	tree[no] = max(tree[L], tree[R]);
}

void query( int no, int i, int j ){
	propagate(no, i, j);
	if( dead[no] ) return;
	if( i == j ){
		if( tree[no]+tempo > k )
			ans[cnt++] = i;
		return;
	}
	int L = 2*no, R = L+1, mid = (i+j)/2;
	query( L, i, mid );
	query( R, mid+1, j );
}

int main(){
	int n, l, r;
	while( scanf("%d%d%d", &n, &k, &tempo ) != EOF ){
		cnt = 0;
		build(1, 1, n);
		rep( i, 0, k ){
			scanf("%d%d", &l, &r );
			update(1, 1, n, l, r, i+1);
		}
		cnt = 0;
		query(1, 1, n);
		printf("%d", cnt );
		rep( i, 0, cnt ) printf(" %d", ans[i] );
		printf("\n");
	
	}
}
