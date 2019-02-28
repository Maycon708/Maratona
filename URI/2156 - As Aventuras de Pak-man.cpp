#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int l, c, n;
char mat[110][110], s[11000];

inline bool dentro( int x, int y ){
	return x >= 0 && x < l && y >= 0 && y < c && mat[x][y] != '#';
}

int main(){
	
	int x, y;
	while( scanf("%d%d%d", &l, &c, &n ) != EOF ){
		if( !l && !c && !n ) break;
		getchar();
		rep( i, 0, l ){
			rep( j, 0, c ){
				mat[i][j] = getchar();
				if( mat[i][j] == '<' ) x = i, y = j;
			}
			getchar();
		}
		gets(s);
		
		int k = 2, cnt = 0;
		int tam = strlen(s);
		int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
		
		rep( i, 0, tam ){
			if( s[i] == 'D' || s[i] == 'd' ) k = 0;
			if( s[i] == 'U' || s[i] == 'u' ) k = 1;
			if( s[i] == 'R' || s[i] == 'r' ) k = 2;
			if( s[i] == 'L' || s[i] == 'l' ) k = 3;
			if( s[i] == 'W' || s[i] == 'w' ){
				int xx = x + dx[k], yy = y + dy[k];
				if( dentro( xx, yy ) ){
					x = xx, y = yy;
					if( mat[x][y] == '*' ) cnt++, mat[x][y] = ' ';
				}
			}
		}
		printf("%d\n", cnt );
	}
}
