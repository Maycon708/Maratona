#include <stdio.h>

int min( int a, int b ){
	if( a < b ) return a;
	return b;
}

int max( int a, int b ){
	if( a > b ) return a;
	return b;
}

int main(){
	int n, i, v[50005], r[50005], l[50005], ans;
	while( scanf("%d", &n ) != EOF ){
		ans = 0;
		for( i = 0; i < n; i++ ){
			scanf("%d", &v[i] );
			if( i == 0 ) l[i] = 1;
			else l[i] = min( l[i-1]+1, v[i] );
		}
		for( i = n-1; i >= 0; i-- ){
			if( i == n-1 ) r[i] = 1;
			else r[i] = min( r[i+1]+1, v[i] );
			ans = max( ans, min( r[i], l[i] ));
		}
		printf("%d\n", ans );
	}
}

