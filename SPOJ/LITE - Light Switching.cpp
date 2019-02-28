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

int tree[4*MAXV];
bool lazy[4*MAXV];
int v[MAXV], N;

void propagate( int no, int i, int j ){
	
	int left = no << 1, right = left^1;
    int mid = (i+j)/2;
	
	tree[no] = ( j - i + 1 ) - tree[no];
	lazy[no] = 0;
	
	if( i != j ) lazy[left] ^= 1, lazy[right] ^= 1;
}

void update( int no, int i, int j, int a, int b ){
	
	if( lazy[no] ) propagate( no, i, j );
	
	int left = no << 1, right = left^1;
    int mid = (i+j)/2;
	
	if( j < a || i > b ) return;
	
	if( i >= a && j <= b ){
		propagate( no, i, j );
        return;
    }

    update( left, i, mid, a, b );
    update( right, mid+1, j, a, b );

    tree[no] = tree[left] + tree[right];
}


int query( int no, int i, int j, int a, int b ){
	
	if( lazy[no] ) propagate( no, i, j );
	
	if( j < a || i > b ) return 0;
	if( i >= a && j <= b ) return tree[no];

	int left = no << 1, right = left^1;
	int mid = (i+j)/2;

    if( i == j ){
        return tree[no];
    }

    int A = query( left, i, mid, a, b );
    int B = query( right, mid+1, j, a , b );
	return A+B;
}

int main(){
	int n, m, op, a, b;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, 4*n ){
			tree[i] = lazy[i] = 0;
		}
		
		while( m-- ){
			scanf("%d%d%d", &op, &a, &b );
			a--, b--;
			if( op ){
				printf("%d\n",  query( 1, 0, n-1, a, b ) );
			}
			else update( 1, 0, n-1, a, b );
		}
	}
}

