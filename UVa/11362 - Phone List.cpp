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

int sig[100010][10], cnt;
int term[100010];

bool add( string s ){
	int x = 0;
	rep( i, 0, s.size() ){
		int c = s[i] - '0';
		if( !sig[x][c] ){
			term[cnt] = 0;
			sig[x][c] = cnt++;
		}
		x = sig[x][c];
		if( term[x] ) return 0;
	}
	rep( i, 0, 10 ) if( sig[x][i] ) return 0;
	term[x] = 1;
	return 1;
}

int main(){
	int t, n;
	char s[10000];
	scanf("%d", &t );
	while( t-- ){
		memset( sig, 0, sizeof sig );
		cnt = 1;
		scanf("%d", &n );
		bool ans = 1;
		rep( i, 0, n ){
			scanf("%s", s );
			ans &= add(s);
		}
		if( ans ) puts("YES");
		else puts("NO");
	}
}

