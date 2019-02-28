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
	char s[1010];
	while( scanf("%s", s ) != EOF ){
		int t = strlen(s);
		vector<int> cnt( 26, 0 );
		rep( i, 0, t ){
			cnt[ s[i] - 'a' ]++;
		}
		int k = 0;
		rep( i, 0, 26 ) k += ( cnt[i]&1 );
		printf("%s\n", (!k || k&1)? "First" : "Second" );
	}
}
