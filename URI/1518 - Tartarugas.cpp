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

int order[] = { 0, 1, 2 }, tx[5], ty[5];
char op[5];

int cost( int &x, int &y, int xx, int yy ){
	int dy = abs( y - yy );
	y = yy;
	int t = ( dy+1 )/2;
	xx += t;
	if( xx == x ) return t;
	if( dy&1 ) x += ( x > xx )? -1 : 1;
	int dx = abs( xx - x );
	if( xx > x ) xx += dx, x = xx, t += dx;
	else xx += (dx+2)/3, x = xx, t += (dx+2)/3;
	return t; 
}

int solve( int x, int y ){
	int t = 0;
	rep( i, 0, 3 ){
		int id = order[i];
		int xx = tx[id], yy = ty[id];
		if( op[id] == 'D' ) t += cost( x, y, xx+t, yy );
		else t += cost( y, x, yy+t, xx );
	}
	return t;
}

int main(){
	int x, y;
	while( scanf("%d%d", &x, &y ) != EOF && x+y ){
		int ans = INF;
		rep( i, 0, 3 ) scanf("%d %d %c", &tx[i], &ty[i], &op[i] );
		do{
			ans = min( ans, solve( x, y ) ); 
		}while( next_permutation( order, order+3 ) );
		printf("%d\n", ans );
	}
}

