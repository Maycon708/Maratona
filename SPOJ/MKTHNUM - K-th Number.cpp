#include<bits/stdc++.h>

#define all(s) ( s.begin(), s.end() ) 
#define pb push_back

using namespace std;

#define N 100010

vector<int> tree[4*N], v;
int a[N];

void build( int no, int i, int j ){
	if( i == j ){
		tree[no].pb( a[i] );
		return;
	}
	int L = no << 1, R = L+1, mid = (i+j) >> 1;
	build( L, i, mid );
	build( R, mid+1, j );
	
	merge( tree[L].begin(), tree[L].end(), tree[R].begin(), tree[R].end(), back_inserter(tree[no]) );	
}


int query( int no, int i, int j, int a, int b, int v ){
	
	if( i > b || j < a ) return 0;
	if( i >= a && j <= b ){
		int p = upper_bound( tree[no].begin(), tree[no].end(), v ) - tree[no].begin();
		return p;
	}
	
	int L = no << 1, R = L+1, mid = (i+j) >> 1;
	int aa = query( L, i, mid, a, b, v );
	int bb = query( R, mid+1, j, a, b, v );
	return aa + bb;
}

int main(){
	int n, k, x, y, q;
	while( scanf("%d%d", &n, &q ) != EOF ){
		for( int i = 0; i < n; i++ ){
			scanf("%d", &a[i] );
			v.pb( a[i] );
		}
		sort( v.begin(), v.end() );
		for( int i = 0; i < n; i++ ){
			a[i] = lower_bound( v.begin(), v.end(), a[i] ) - v.begin() + 1;
		}
		build( 1, 0, n-1 );
		while( q-- ){
			scanf("%d%d%d", &x, &y, &k );
			x--, y--;
			int i = 1, j = n, ans;
			while( i <= j ){
				int mid = ( i+j )/2;
				int aux = query( 1, 0, n-1, x, y, mid );
				if( aux >= k ){
					ans = mid;
					j = mid-1;
				}
				else i = mid+1;
			}
			printf("%d\n", v[ans-1] );
		}
	}
}
