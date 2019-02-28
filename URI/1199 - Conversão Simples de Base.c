#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
	char s[20], ch;
	long long int n, k;
	while( 1 ){
		ch = getchar(); k = 0;
		while( ch != '\n' ){
			s[k++] = ch;
			ch = getchar();
		}
		s[k] = '\0';
		
		if( s[0] == '-' ) break;
		if( s[0] == '0' ){
			n = strtol( s, NULL, 16 );
			printf("%lld\n", n );
		}
		else{
			n = atol( s );
			printf("0x%llX\n", n );
		}
	}
}
