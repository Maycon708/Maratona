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

bool bissexto( int ano ){
	return ( ano%4 == 0 && ano%100 != 0 ) || ( ano%400 == 0 );
}

int main(){
	int mes_n[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int mes_b[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int n, d[10010], m[10010], y[10010], v[10010];
	
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		rep( i, 0, n ){
			scanf("%d%d%d%d", &d[i], &m[i], &y[i], &v[i] );
		}
		int cnt = 0, resp = 0;
		rep( i, 0, n-1 ){
			int dd = d[i], mm = m[i], yy = y[i];
			if( bissexto(yy) ){
				dd++;
				if( dd > mes_b[mm] ) dd -= mes_b[mm], mm++;
				if( mm > 12 ) mm = 1, yy++;
			}
			else{
				dd++;
				if( dd > mes_n[mm] ) dd -= mes_n[mm], mm++;
				if( mm > 12 ) mm = 1, yy++;
			}
			if( d[i+1] == dd && m[i+1] == mm && y[i+1] == yy ){
				cnt++; resp += ( v[i+1] - v[i] ); 
			}
		}
		printf("%d %d\n", cnt, resp );
	}
		
}

