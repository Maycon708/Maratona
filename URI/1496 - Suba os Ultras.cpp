#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAX  110000
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int v[MAX], esq[MAX], dir[MAX];
int SEG[4*MAX];

void build_tree( int node, int i, int j ){                                       
    if( i == j ){                                   
        SEG[node] = v[i];  
        return;
    }

    int left = 2 * node;
    int right = 2 * node + 1; 

    build_tree( left, i, (i + j)/2 );  
    build_tree( right, 1 + (i + j)/2, j ); 

    SEG[node] = min( SEG[left], SEG[right] );
}

int query( int node, int i, int j, int a, int b ){
    if( i > b || j < a || i > j ) return INF;

    if( i >= a && j <= b ) return SEG[node];

    int left = 2 * node;
    int right = 2 * node + 1;

    int q1 = query(left, i, (i + j)/2, a, b);
    int q2 = query(right, (i + j)/2 + 1, j, a, b);

    return min( q1, q2 );
}


int main(){
	
	int N;
	while( scanf("%d", &N ) != EOF ){
		rep( i, 0, N ) scanf("%d", &v[i] );
		build_tree( 1, 0, N );
		esq[0] = -1;
		rep( i, 1, N ){
			esq[i] = i-1;
			while( esq[i] >= 0 && v[i] >= v[esq[i]] )
				esq[i] = esq[esq[i]];
		}  
		dir[N-1] = N;
		for( int i = N-2; i >= 0; i-- ){
			dir[i] = i+1;
			while( dir[i] < N && v[i] >= v[ dir[i] ] )
				dir[i] = dir[dir[i]];
		}
		bool aux = 0;
		rep( i, 0, N ){
			bool a = 0, b = 0;
			if( esq[i] == -1 ) a = 1;
			else{
				int k = query( 1, 0, N, esq[i], i );
				if( v[i] - k >= 150000 ) a = 1;
			}
			if( dir[i] == N ) b = 1;
			else{
				int k = query( 1, 0, N, i, dir[i] );
				if( v[i] - k >= 150000 ) b = 1;
			}
			if( a && b ){
				if( aux ) printf(" ");
				aux = 1;
				printf("%d", i+1 );		
			}		
		}
		printf("\n");
	}
}

