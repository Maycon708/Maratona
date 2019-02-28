#include <stdio.h>

int aux[1000100];

int main(){
	int k = 2, i, n;
	aux[1] = 0;
	for( i = 2; i < 1000100; i++ ){
		aux[i] = aux[i-1]+1;
		if( aux[i] == k )  aux[i] = 0, k++;
	}
	while( 42 ){
		scanf("%d", &n );
		if( !n ) break;
		printf("%d %d\n", n - aux[n], aux[n] );
	}
    return 0;
}

