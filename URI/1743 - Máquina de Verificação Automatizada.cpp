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
	int a = 0, b = 0, bit;
	rep( i, 0, 5 ){
		scanf("%d", &bit );
		a *= 2;
		a += bit;
	}
	rep( i, 0, 5 ){
		scanf("%d", &bit );
		b *= 2;
		b += bit;
	}
	if( ( a^b ) == 31 ) puts("Y");
	else puts("N");
}

