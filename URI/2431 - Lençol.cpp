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
	int a, b, c, d, x, y;
	while( scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &x, &y ) != EOF ){
		if( a > b ) swap( a, b );
		if( c > d ) swap( c, d );
		if( x > y ) swap( x, y );
		int sum = 0;
		if( a >= x ) sum += b;
		else if( b >= x ) sum += a;
		if( c >= x ) sum += d;
		else if( d >= x ) sum += c;
		if( sum >= y ) printf("S\n");
		else printf("N\n");
	}
}

