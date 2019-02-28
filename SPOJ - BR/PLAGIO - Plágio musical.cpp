#include <bits/stdc++.h>
     
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1002100
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
     
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
     
using namespace std;
     
typedef pair <int, int> ii;
typedef long long int ll;

int P[1010101];

inline int C( char s ){
	if( s == 'A' ) return 0;
	if( s == 'B' ) return 2;
	if( s == 'C' ) return 3;
	if( s == 'D' ) return 5;
	if( s == 'E' ) return 7;
	if( s == 'F' ) return 8;
	if( s == 'G' ) return 10;
	if( s == '#' ) return 1;
	if( s == 'b' ) return -1;
}

int pattern[100010], text[200010], n, m;

void pre_process( ){
	P[0] = 0;
	int j = 0;
	rep( i, 1, m ){
		while( j > 0 && pattern[j] != pattern[i] ) j = P[j-1];
		if( pattern[j] == pattern[i] ) j++;
		P[i] = j;
	}
}

inline bool KMP ( ){
	bool aux = true;
	int j = 0;
	rep( i, 0, 2*n ){
		while( j > 0 && pattern[j] != text[i] ) j = P[j-1];
		if( pattern[j] == text[i] ){
			j++;
			if( j == m ){
				aux = false;
				j = P[j-1];
			}
		}
	}
	return !aux;
}

int main(){
	int v[100100], u[100100];
	char s[10];
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		rep( i, 0, n ){
			scanf("%s", s );
			v[i] = 0;
			int tam = strlen( s );
			rep( j, 0, tam ){
				v[i] += C(s[j]);
			}
		}
		rep( i, 0, n ){
			int w = i-1;
			if( w < 0 ) w += n;
			text[i] = ( v[i] - v[w] + 12 ) % 12;
			text[i+n] = text[i]; 
		}
		rep( i, 0, m ){
			scanf("%s", s );
			u[i] = 0;
			int tam = strlen( s );
			rep( j, 0, tam ){
				u[i] += C(s[j]);
				
			}
		}
		rep( i, 1, m ){
			int w = i-1;
			pattern[i-1] = ( u[i] - u[w] + 12 ) % 12;
		}
		m--;
		pre_process();
		if( m > n ) printf("N\n");
		else if( KMP() ) printf("S\n");
		else printf("N\n");
	}
}
