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

int x, y, v[20], t = 1;

bool check( int p, int x ){
	rep( i, 1, p ){
		if( v[i] == x || abs(x-v[i]) == p-i ) return 0;
	}
	return 1;
}

void back( int p ){
	if( p == 9 ){
		printf("%2d      ", t++ );
		rep( i, 1, 9 ) printf("%d%s", v[i], i == 8 ? "\n" : " " );
		return;
	}
	rep( i, 1, 9 ){
		if( p == x && i != y ) continue;
		if( check(p, i) ){
			v[p] = i;
			back( p+1 );
		}
	}	
}

int main(){
	int test, aux = 0;
	scanf("%d", &test );
	while( scanf("%d%d", &y, &x ) != EOF ){
		t = 1;
		if( aux ) printf("\n");
		else aux = 1;
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		back(1);
	}
}	
