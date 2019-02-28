#include<bits/stdc++.h>

using namespace std;

int main(){
	int t, r, g, b, test = 1;
	string s;
	scanf("%d", &t );
	while( t-- ){
		cin >> s;
		scanf("%d%d%d", &r, &g, &b );
		printf("Caso #%d: ", test++ );
		if( s == "eye" ) printf("%d\n", ( r * 30 + g * 59 + b * 11 )/100 );
		else if( s == "mean" ) printf("%d\n", (r+g+b)/3 );
		else if( s == "max" ) printf("%d\n", max( r, max( g, b ) ) );
		else printf("%d\n", min( r, min( g, b )));	
	}
}