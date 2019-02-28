#include <stdio.h>

#define rep(i, a, b) for (i = a; i < b; i++)

int main(){

	int t = 1, n, cont, a, b, i;
	while( 42 ){
		scanf("%d", &n );
		if( !n ) break;
		printf("Teste %d\n", t++ );
		cont = 0;
		rep( i, 0, n ){
			scanf("%d%d", &a, &b );
			cont += ( a - b );
			printf("%d\n", cont );
		}
		printf("\n");
	}
}

