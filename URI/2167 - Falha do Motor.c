#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	int s[600], n, i, resp;
	while( scanf("%d", &n ) != EOF ){
		for( i = 0; i < n; i++ ) scanf("%d", &s[i] );
		resp = 0;
		for( i = 1; i < n; i++ )
			if( s[i] < s[i-1] ){
				resp = i+1;
				break;
			}
		printf("%d\n", resp );
	}
}
