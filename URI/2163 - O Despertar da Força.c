#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int mat[1001][1001];

int main(){
	int n, a, i, j, m, resp, b;
	while( scanf("%d%d", &n, &m ) != EOF ){
		a = b = 0;
		for( i = 0; i < n; i++ ){
			for( j = 0; j < m; j++ ){
				scanf("%d", &mat[i][j] );
			}
		}
		for( i = 1; i < n-1; i++ ){
			for( j = 1; j < m-1; j++ ){
				if( mat[i][j] == 42 )
					if( mat[i-1][j-1] == 7 && mat[i-1][j] == 7 && mat[i-1][j+1] == 7 && mat[i][j-1] == 7 && 
						mat[i][j+1] == 7 && mat[i+1][j-1] == 7 && mat[i+1][j] == 7 && mat[i+1][j+1] == 7 ) a = i+1, b = j+1;
			}
		}
		printf("%d %d\n", a, b );
	}
}
