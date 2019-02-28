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

char s[1000100];

inline int C( char c ){
	return int(c);
}

int main(){

	int m, cont[360], cnt;
	while( scanf("%d", &m ) != EOF ){
		if( !m ) break;
		rep( i, 0, 360 ) cont[i] = 0;
		cnt = 0;
		gets(s);
		gets(s);
		int tam = strlen(s);
		int i = 0, j = 0, ans = 0;
		while( i < tam ){
			int u = C( s[i] );
			if( !cont[u] ) cnt++;
			cont[u]++;
			while( cnt > m ){
				int v = C( s[j] );
				cont[v]--;
				if( !cont[v] ) cnt--;
				j++;
			}
			ans = max( ans, i-j+1 );
			i++;
		}
		printf("%d\n", ans );
	}
}
