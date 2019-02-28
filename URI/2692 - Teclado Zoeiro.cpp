#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = a; i < b; i++ )

using namespace std;

int main(){
	
	int n, m;
	while( scanf("%d%d", &n, &m ) != EOF ){
		map<char, char> mp;
		char a, b, s[100000];
		rep( i, 0, n ){
			scanf(" %c %c", &a, &b );
			mp[a] = b;
			mp[b] = a;
		}
		gets(s);
		rep( i, 0, m){
			gets(s);
			int t = strlen(s);
			rep( i, 0, t ){
				if( mp.count(s[i])) printf("%c", mp[s[i]]);
				else printf("%c", s[i]);
			}
		printf("\n");
		}
	}
	
	return 0;
}