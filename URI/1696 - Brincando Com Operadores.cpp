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

typedef pair <int, int> ii;
typedef long long int ll;

int tree[4*MAXV], aux[4*MAXV];
int v[MAXV], N;

void build( int no, int i, int j ){

	if( i > j ) return;
	
	int left = no << 1, right = left^1;
    int mid = (i+j)/2;
	
    if( i == j ){
        tree[no] = v[i];
        aux[no] = 1;
        return;
    }

    build( left, i, mid );
    build( right, mid+1, j );
	
	aux[no]  = !aux[left];
    if( aux[no] ) tree[no] = tree[left] - tree[right];
    else tree[no] = tree[left] + tree[right];
}

void update( int no, int i, int j, int a, int V ){
	
	int left = no << 1, right = left^1;
    int mid = (i+j)/2;
	
	if( i > a || j < a  ) return;
    if( i == j ){
        tree[no] = V;
        return;
    }

    update( left, i, mid, a, V );
    update( right, mid+1, j, a, V );

	if( aux[no] ) tree[no] = tree[left] - tree[right];
    else tree[no] = tree[left] + tree[right];
}

int main(){
	
	int n, a, b, t, q, turn = 0;
	
	scanf("%d", &t );
	while( t-- ){
		
		scanf("%d%d", &n, &q );
		rep( i, 1, n+1 ) scanf("%d", &v[i] );
		int aux = 1;
		while( aux < n ) aux *= 2;
		rep( i, n+1, aux+1 ) v[i] = 0;
		n = aux;
		build( 1, 1, n );
		
		printf("%d ", tree[1] );
		if( ( tree[1] & 1 ) ^ turn ) puts("Rusa");
		else puts("Sanches");
		
		rep( i, 0, q ){
			scanf("%d%d", &a, &b );
			update( 1, 1, n, a, b );
		
			printf("%d ", tree[1] );
			if( ( tree[1] & 1 ) ^ turn ) puts("Rusa");
			else puts("Sanches");
		}
		turn ^= 1;
	}
}

