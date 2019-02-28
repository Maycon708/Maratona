#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)

using namespace std;

int main(){
	int n, m, a, t;
	while( scanf("%d%d", &n, &m ) != EOF ){
		t = 0;	
		rep( i, 0, n ) 
			rep( j, 0, m )
				scanf("%d", &a ),
				t += a;
		printf("%d saca(s) e %d litro(s)\n", t/60, t%60 );
	}
}
