#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = a; i < b; i++ )

using namespace std;

int main(){
	
	int n, a, b;
	scanf("%d", &n );
	while( n-- ){
		scanf("%dx%d", &a, &b );
		if( a == b ){
			rep( i, 5, 11 ){
				printf("%d x %d = %d\n", a, i, a*i );
			}
		}
		else{
			rep( i, 5, 11 ){
				printf("%d x %d = %d && %d x %d = %d\n", a, i, a*i, b, i, b*i );
			}
		}
	}
	
	return 0;
}