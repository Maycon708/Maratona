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

bool C( int a ){
	rep( i, 2, a ) if( a%i == 0 ) return 0;
	return 1;
}

bool CC( int a, int b ){
	rep( i, a+1, b )
		if( C(i) ) return 0;
	return 1;
}

int main(){
	int a, b;
	while( scanf("%d%d", &a, &b ) != EOF ){
		if( !C(b) || !CC( a, b ) ) puts("NO");
		else puts("YES");
	}
}

