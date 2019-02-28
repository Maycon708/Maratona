#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

ll tree[4*MAXV];
ll child[4*MAXV], N, B, P;

ll fastexp( int e ){
	ll resp = 1, aux = B;
	while( e ){
		if( e&1 ) resp = ( resp * aux )%P;
		aux = ( aux * aux )%P;
		e >>= 1;
	}
	return resp;
}

void build( int no, int i, int j ){
	if( i == j ){
		tree[no] = 0;
		child[no] = 1;
		return;
	}
	
	int left = no << 1, right = left^1;
    int mid = (i+j)/2;
	
	build( left, i, mid );
	build( right, mid+1, j );
	
	child[no] = child[left] + child[right];
    tree[no] = 0;
}

void update( int no, int i, int j, int a, ll val ){
	
	int left = no << 1, right = left^1;
    int mid = (i+j)/2;
	
	if( j < a || i > a ) return;
	
	if( i == a && j == a ){
        tree[no] = val;
        return;
    }

    update( left, i, mid, a, val );
    update( right, mid+1, j, a, val );

    ll k  = fastexp( child[right] );
    tree[no] = ( tree[left] * k + tree[right] )%P;
}


ii query( int no, int i, int j, int a, int b ){
	
	if( j < a || i > b ) return ii( 0, 0 );

	if( i >= a && j <= b ){
		return ii( tree[no], child[no] );
	}
	int left = no << 1, right = left^1;
	int mid = (i+j)/2;

    ii aa = query( left, i, mid, a, b );
    ii bb = query( right, mid+1, j, a , b );
	ll k  = fastexp( bb.S );
    return ii( ( aa.F * k + bb.F )%P, aa.S + bb.S );
}

int main(){
	
	int n, m, a, b;
	char op;
	while( scanf("%lld%lld%d%d", &B, &P, &n, &m ) != EOF ){
		if( !P ) break;
		
		build( 1, 0, n-1 );		
		
		while( m-- ){
			scanf(" %c%d%d", &op, &a, &b );
			if( op == 'E' ) update( 1, 0, n-1, a-1, b );
			else printf("%lld\n", query( 1, 0, n-1, a-1, b-1 ).F );
		}
		printf("-\n");
	}
	
}

