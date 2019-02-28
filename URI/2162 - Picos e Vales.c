#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	int n, a, i, j, aux, m, resp, b, v[111];
	while( scanf("%d", &n ) != EOF ){
		for( i = 0; i < n; i++ ){
			scanf("%d", &v[i] );
		}
		resp = 1;
		if( v[1] > v[0] ) aux = 1;
		else aux = 0;
		for( i = 1; i < n; i++ ){
			if( aux && v[i] <= v[i-1] ) resp = 0;
			if( !aux && v[i] >= v[i-1] ) resp = 0;
			aux ^= 1;
		}
		printf("%d\n", resp );
	}
}
