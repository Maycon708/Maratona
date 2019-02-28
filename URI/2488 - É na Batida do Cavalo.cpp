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

#define N 10010

double dist[N], tree[N<<2];

void build( int no, int i, int j ){
	if( i > j ) return;
	if( i == j ){
		tree[no] = dist[i];
		return;
	}
	int mid = ( i + j ) >> 1;
	int l = no << 1;
	int r = l ^ 1;
	build( l, i, mid );
	build( r, mid+1, j );
	tree[no] = max( tree[l], tree[r] );
}

double query( int no, int i, int j, int a, int b ){
	if( i > b || j < a ) return 0;
	if( i >= a && j <= b ) return tree[no];
	int mid = ( i + j ) >> 1;
	int l = no << 1;
	int r = l ^ 1;
	double aa = query( l, i, mid, a, b );
	double bb = query( r, mid+1, j, a, b );
	return max( aa, bb );
}

int main(){
	
	int n, k, x, y, xx, yy;
	while( scanf("%d%d", &n, &k ) != EOF ){
		map<ii,int>mp;
		rep( i, 0, n ){
			scanf("%d%d", &x, &y );
			mp[ii(x,y)] = i;
			if(i)dist[i] = hypot( x - xx, y - yy );
			xx = x, yy = y;
		}
		build( 1, 0, n );
		while( k-- ){
			scanf("%d%d%d%d", &x, &y, &xx, &yy );
			int a = mp[ii(x,y)];
			int b = mp[ii(xx,yy)];
			if( a > b ) swap( a, b );
			printf("%.2f\n", query( 1, 0, n, a+1, b ) );
		}
	} 
}

