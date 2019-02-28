#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)

using namespace std;

int main(){
	char a[10100], b[10100];
	while( scanf("%s%s", a, b ) != EOF ){
		int t1 = strlen(a), t2 = strlen(b), ans = 0;
		rep( i, 0, t1-t2+1 ){
			bool check = 1;
			rep( j, 0, t2 ){
				if( a[i+j] == b[j] ) check = 0;
			}
			ans += check;
		}
		printf("%d\n", ans );
	}
}
