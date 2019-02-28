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
	int t, bonus, a1, d1, l1, a2, d2, l2;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &bonus );
		bonus <<= 1;
		scanf("%d%d%d", &a1, &d1, &l1 );
		scanf("%d%d%d", &a2, &d2, &l2 );
		int v1 = ( ( a1 + d1 ) ) + bonus * !( l1&1 );
		int v2 = ( ( a2 + d2 ) ) + bonus * !( l2&1 );
		if( v1 > v2 ) puts("Dabriel");
		else if( v2 > v1 ) puts("Guarte");
		else puts("Empate");
	}
}

