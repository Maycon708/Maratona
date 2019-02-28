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
int v[MAXV], N;

void build( int no, int i, int j ){

	if( i > j ) return;
	
	int left = no << 1, right = left^1;
    int mid = (i+j)/2;
	
    if( i == j ){
        tree[no] = v[i];
        return;
    }

    build( left, i, mid );
    build( right, mid+1, j );

    tree[no] = tree[left] + tree[right];
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

    tree[no] = tree[left] + tree[right];
}

int query( int no, int i, int j, int a, int b ){
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
	int n, a, b, t = 1;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		rep( i, 1, n+1 ) scanf("%d", &v[i] );
		build( 1, 1, n );
		string s;
		if( t != 1 ) printf("\n");
		printf("Case %d:\n", t++ );
		while( cin >> s ){
			if( s == "END" ) break;
			if( s == "M" ){
				scanf("%d%d", &a, &b );
				printf("%d\n", query( 1, 1, n, a, b ));
			}
			else{
				scanf("%d%d", &a, &b );
				update( 1, 1, n, a, b );
			}
		}
	}
}

