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
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();
//
//int tree[1000100];
//
//void build( int node, int i, int j, int cnt ){
//	int l = node << 1, r = l ^ 1;
//	int mid = ( i + j )/2;
//	if( i == j ){
////		debug( cnt )
//		tree[node] = 0;
//		return;
//	}
//	build( l, i, mid, cnt+1 );
//	build( r, mid+1, j, cnt+1 );
//	tree[node] = 0;
//}
//
//int query( int node, int i, int j, int a, int b ){
//	int l = node << 1, r = l ^ 1;
//	int mid = ( i + j ) >> 1;
//	if( j < a || i > b ) return 0;
//	if( i >= a && j <= b ) return tree[node];
//	int q1 = query( l, i, mid, a, b );
//	int q2 = query( r, mid+1, j, a, b );
//	tree[node] = max( q1, q2 );
//}
//
//void update( int node, int i, int j, int a, int b, int v ){
////	debug( node )
////	debug2( i, j )
//	int l = node << 1, r = l ^ 1;
////	debug2( l, r )
//	int mid = ( i + j ) >> 1;
//	if( j < a || i > b ) return;
//	if( i == j ){
//		tree[node] = max( tree[node], v );
//		return;
//	}
//	update( l, i, mid, a, b, v );
//	update( r, mid+1, j, a, b, v );
//	tree[node] = max( tree[l], tree[r] );
//}

struct E{
	int ini, h, fim;
};

inline bool cmp( E a, E b ){
	return a.h > b.h;
}

int main(){
	int m = 131071;
	vector < E > v;
	int resp[101010], l[101010];
	E e;
	v.clear();
	rep( i, 0, 101010 ) resp[i] = l[i] = 0;
	while( scanf("%d%d%d", &e.ini, &e.h, &e.fim ) != EOF ){
		v.pb( e );
	}
	sort( all(v), cmp );
	
	rep( i, 0, v.size() ){
		int x = v[i].ini, y = v[i].fim, z = v[i].h;
		rep( j, x, y ){
			if( resp[j] ) j = l[j]-1; 
			else{
				resp[j] = z;
				l[j] = y;
			}
		} 
	}
	bool aux = 0;
	rep( i, 1, 100001 ){
		if( resp[i] != resp[i-1] ){
			if( aux ) printf(" ");
			aux = 1;
			printf("%d %d", i, resp[ i ] );
		}
	}
	printf("\n");
}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

