#include<stdio.h>
#include<math.h>

int main(){
	int a, b, c, d, i, t, n, ans;
	while( scanf("%d%d%d%d", &a, &b, &c, &d ) != EOF ){
		t = sqrt(c); ans = 1e9+7;
		for( i = 1; i <= t; i++ ){
			if( c%i == 0 ){
				if( i%a == 0 && i%b != 0 && d%i != 0 && ans > i ) ans = i; 
				n = c/i;
				if( n%a == 0 && n%b != 0 && d%n != 0 && ans > n ) ans = n;
			}
		}
		printf("%d\n", ( ans == 1e9+7 )? -1 : ans );
	}
}
