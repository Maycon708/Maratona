#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

char s[1000100];
int P[1000100], t;

void kmp(){
	P[0] = -1;
	rep( i, 1, t ){
		P[i] = P[i-1];
		while( P[i] >= 0 && s[P[i]+1] != s[i] ) P[i] = P[P[i]];
		if( s[P[i]+1] == s[i] ) P[i]++;
	}
}

int main(){
	scanf("%s", s );
	t = strlen(s);
	kmp();
	if( P[t-1] == -1 ){
		puts("Just a legend");
		return 0;
	}
	rep( i, 0, t-1 ){
		if( P[i] == P[t-1] ){
			rep( j, 0, P[i]+1 ) printf("%c", s[j] );
			printf("\n");
			return 0;
		}
	}
	
	if( P[P[t-1] ] == -1 ) puts("Just a legend");
	else{
		rep( i, 0, P[P[t-1]]+1 ) printf("%c", s[i] );
		printf("\n");
	}
}
