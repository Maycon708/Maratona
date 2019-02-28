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

const int N = 1e5+5;
int vet[N], tree[N<<2];

void build( int no, int i, int j ){
	if( i == j ){
		tree[no] = vet[i];
		return;
	}
	int m = ( i + j ) >> 1;
	int l = no << 1, r = l ^ 1;
	build( l, i, m );
	build( r, m+1, j );
	tree[no] = tree[l] + tree[r];
}

void update( int no, int i, int j, int x, int v ){
	if( x < i || x > j ) return;
	if( i == j && i == x ){
		tree[no] = v;
		return;
	}
	int m = ( i + j ) >> 1;
	int l = no << 1, r = l ^ 1;
	update( l, i, m, x, v );
	update( r, m+1, j, x, v );
	tree[no] = tree[l] + tree[r];
}

int query( int no, int i, int j, int a, int b ){
	if( b < i || a > j ) return 0;
	if( i >= a && j <= b ) return tree[no];
	int m = ( i + j ) >> 1;
	int l = no << 1, r = l ^ 1;
	int aa = query( l, i, m, a, b );
	int bb = query( r, m+1, j, a, b );
	return aa + bb;
}

struct Q{
	int a, b, k, id, ans;
	Q(){};
	Q( int _a, int _b, int _k, int _id ){
		a = _a; b = _b; k = _k; id = _id;
	}
};

inline bool cmp1( Q a, Q b ){
	return a.k < b.k;
}
inline bool cmp2( Q a, Q b ){
	return a.id < b.id;
}

#define gc getchar//_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int main(){
	int t, n, q, op, a, b, c;
	scan(t);
	while( t-- ){
		vector<Q> querys;
		vector<ii> updates;
		scan(n);
		rep( i, 0, n ) scan( vet[i] );
		build( 1, 0, n-1 );
		scan(q);
		int k = 0;
		while( q-- ){
			scan(op);
			if( op == 1 ){
				scan(a), scan(b), scan(c);
				querys.pb( Q( a-1, b-1, c, k++ ) );
			}
			else{
				scan(a), scan(b);
				updates.pb( ii( a-1, b ) );
			}
		}
		sort( all( querys ), cmp1 );
		int j = 0;
		rep( i, 0, querys.size() ){
			Q aux = querys[i];
			while( j < aux.k ){
				ii u = updates[j++];
				update( 1, 0, n-1, u.F, u.S );
			}
			int aa = query( 1, 0, n-1, aux.a, aux.b );
			querys[i].ans = aa;
		}
		sort( all( querys ), cmp2 );
		rep( i, 0, querys.size() ) printf("%d\n", querys[i].ans );
	}
}

