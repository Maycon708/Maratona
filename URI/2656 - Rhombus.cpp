#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
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
	
	int q, op, xx, yy, d;
	scanf("%d", &q );
	while( q-- ){
		scanf("%d%d%d", &op, &xx, &yy );
		int x = xx + yy;
		int y = xx - yy;
		if( op == 1 ) insert( x, y );
		else if( op == 2 ) remove( x, y );
		else{
			scanf("%d", &d );
			printf("%d\n", query( x+d, y+d ) - query( x+d, y-d-1 ) - query( x-d-1, y+d )  + query( x-d-1, y-d-1 ) );
		}
	}

}
