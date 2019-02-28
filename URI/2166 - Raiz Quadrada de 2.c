#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	int s[600], n, i, resp;
	while( scanf("%d", &n ) != EOF ){
		double aux = 0;
		for( i = 0; i < n; i++ ) aux += 2, aux = 1/aux; 
		printf("%.10f\n", 1 + aux );
	}
}
