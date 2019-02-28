#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	char mat[1001][10];
	while( scanf("%d", &n ) != EOF ){
		int ok = 0;
		for( int i = 0; i < n; i++ ){
			scanf("%s", mat[i] );
			if( ( mat[i][0] == 'O' && mat[i][1] == 'O'  && !ok) ) mat[i][0] = '+', mat[i][1] = '+', ok = 1;
			if( (mat[i][3] == 'O' && mat[i][4] == 'O'  && !ok ) ) mat[i][3] = '+', mat[i][4] = '+', ok = 1;
		}
		if( !ok ) printf("NO\n");
		else{
			printf("YES\n");
			for( int i = 0; i < n; i++ ){
				printf("%s\n", mat[i] );
			}
		}
	}
}
