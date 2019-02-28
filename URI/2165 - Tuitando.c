#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	char s[600];
	while( gets( s ) ){
		int t = strlen( s );
		if( t > 140 ) printf("MUTE\n");
		else printf("TWEET\n");
	}
}
