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

int p[2], a[2], b[2];

bool check(){
	rep( i, 0, 2 )	rep( j, 0, 2 )	rep( k, 0, 2 )
		if( a[i] + b[j] <= p[k] && a[!i] <= p[!k] && b[!j] <= p[!k] )
			return 1;
	return 0;
}

int main(){
	while( cin >> p[0] >> p[1] ){
		cin >> a[0] >> a[1];
		cin >> b[0] >> b[1];
		if( check() ) printf("S\n");
		else printf("N\n");
	}
}

