#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

int pd[301][301][301], n;

int solve( int p, int r, int g, int b ){
	if( p == n ) return r*4+g*2+b;
	int &ans = pd[r][b][g];
	if( !ans ){
		if( r ){
			if( g ) ans |= solve( p+1, r-1, g-1, b+1 );
			if( b ) ans |= solve( p+1, r-1, g+1, b-1 );
		}
		if( b && g ) ans |= solve( p+1, r+1, g-1, b-1 );
		if( r > 1 ) ans |= solve( p+1, r-1, g, b );
		if( g > 1 ) ans |= solve( p+1, r, g-1, b );
		if( b > 1 ) ans |= solve( p+1, r, g, b-1 );
	}
	return ans;
}

int main(){
	string s;
	scanf("%d", &n );
	cin >> s;
	int r = 0, b = 0, g = 0;
	for( auto x : s ) 
		r += x == 'R',
		b += x == 'B',
		g += x == 'G';
	
	r = solve( 1, r, g, b );
	if( r&1 ) printf("B");
	if( r&2 ) printf("G");
	if( r&4 ) printf("R");
}
