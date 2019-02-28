#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

const int N = 500001;

OST bit[N];

void insert(int x, int y){
	for(int i = x; i < N; i += i & -i)
		bit[i].insert(mp(y, x));
}

void remove(int x, int y){
	for(int i = x; i < N; i += i & -i)
		bit[i].erase(mp(y, x));
}

int query(int x, int y){
	int ans = 0;
	for(int i = x; i > 0; i -= i & -i)
		ans += bit[i].order_of_key(mp(y+1, 0));
	return ans;
}

int main(){
	
	int t, n, xx[N], yy[N], d;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &d );
		rep( i, 0, n ){
			scanf("%d%d", &xx[i], &yy[i] );
			int x = xx[i] + yy[i];
			int y = xx[i] - yy[i];
			insert( x, y );
		}
		rep( i, 0, n ){
			int x = xx[i] + yy[i];
			int y = xx[i] - yy[i];
			printf("%d ", query( x+d, y+d ) - query( x+d, y-d-1 ) - query( x-d-1, y+d )  + query( x-d-1, y-d-1 ) - 1 );
		}
		printf("\n");
		
	}

}
