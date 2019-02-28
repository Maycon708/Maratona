#include <stdio.h>

#define rep(i, a, b) for ( i = a; i < b; i++)

struct{
	int F, S;
} v[1100];

int max( int a, int b ){
	if( a > b ) return a;
	return b;
}

int main(){

	int n, t = 1, i, x, y;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		int aux = 0;
		rep( i, 0, n ){
			scanf("%d%d", &x, &y );
			aux = max( aux, y );
			v[i].F = x;
			v[i].S = y;
		}
		printf("Turma %d\n", t++ );
		rep( i, 0, n ){
			if( v[i].S == aux ){
				printf("%d ", v[i].F );
			}
		}
		printf("\n\n");
	}
	
}

