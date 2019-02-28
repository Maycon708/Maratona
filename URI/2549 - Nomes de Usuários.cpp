#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;


int main(){

	int n, y;
	char s[111], ans[111];
	
	while( scanf("%d%d", &n, &y ) != EOF ){
		getchar();
		map<string, int> mp;
		int cnt = 0;
		while( n-- ){
			gets(s);
			stringstream ss;
			ss << s;
			int i = 0;
			while( ss >> s ){
				ans[i++] = s[0];
			}
			ans[i] = '\0';
			if( mp.count(ans) ) cnt++;
			mp[ans] = 1;
		}
		printf("%d\n", cnt );
	
	}
	
}
