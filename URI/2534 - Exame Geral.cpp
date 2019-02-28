#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back

int main(){

	int a, b, v[111], n, q;
	
	while( scanf("%d%d", &n, &q ) != EOF ){
		rep( i, 0, n ) scanf("%d", &v[i] );
		sort( v, v+n );
		reverse( v, v+n );
		while( q-- ){
			scanf("%d", &a );
			printf("%d\n", v[a-1] );
		}
	}
	
}
