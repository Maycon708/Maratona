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

int read(){
	int h, m;
	if( scanf("%d:%d", &h, &m ) != EOF ){
		return h*60 + m;
	} 
	return -1;
}

int main(){
	int a = read(), b, c, d;
	while( a != -1 ){
		b = read(), c = read(), d = read();
		int aa = b - a, bb = d - c;
		c =  -INF, d = INF;
		rep( i, 0, 2 ){
			rep( j, 0, 2 ){
				a = aa, b = bb;
				if( i ) a += ( 24 * 60 );
				if( j ) b += ( 24 * 60 );
				int dur = ( a + b ) >> 1;
				int fuso = ( a - dur )/60;
				if( fuso > 12 && fuso < 24 ) fuso -= 24;
				if( fuso <= -12 && fuso > -24 ) fuso -= -24;
				if( dur <= 0 || dur >= 12 * 60 || fuso <= -12 || fuso > 12  ) continue;
				if( d > dur || ( d == dur && c < fuso ) ) d = dur, c = fuso; 
			}
		}
		printf("%d %d\n", d, c );
		a = read();
	}
}

