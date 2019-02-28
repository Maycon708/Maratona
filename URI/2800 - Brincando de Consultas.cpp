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

map<int, int> tree[400400];
int v[100400], P[400400], pos[100400];

void build( int no, int i, int j ){
	if( i == j ){
		pos[i] = no;
		tree[no][v[i]]++;
		return;
	}
	int mid = (i+j)/2, L = 2*no, R = L+1;
	build(L, i, mid );
	build(R, mid+1, j );
	P[R] = P[L] = no;
	tree[no] = tree[L]; 
	for( auto x : tree[R] ) tree[no][x.F] += x.S;
}

void update( int i, int v, int last ){
	for( int x = pos[i]; x != -1; x = P[x] ){
		tree[x][last]--;
		tree[x][v]++;
	}
}

int query( int no, int i, int j, int a, int b, int v ){
	if( j < a || i > b || !tree[no].count(v) ) return 0;
	if( i >= a && j <= b ) return tree[no][v];
	int mid = (i+j)/2, L = 2*no, R = L+1;
	int v1 = query( L, i, mid, a, b, v );
	int v2 = query( R, mid+1, j, a, b, v );
	return v1+v2;
}

int main(){
	int n, m, op, a, b, c;
	scanf("%d%d", &n, &m );
	rep( i, 1, n+1 ){ 
		scanf("%d", &v[i] );
	}
	build(1, 1, n);
	P[1] = -1;
	while( m-- ){
		scanf("%d", &op );
		if( op == 1 ){
			scanf("%d%d", &a, &b );
			update( a, b, v[a] );
			v[a] = b;
		}
		else{
			scanf("%d%d%d", &a, &b, &c );
			printf("%d\n", b-a+1-query( 1, 1, n, a, b, c ));
		}
	}
}
