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
	ll a, b, c, d, e, f;
	while( cin >> a >> b >> c >> d >> e >> f ){
		ll pc = a * 6000 + b * 2000 + c;
		ll pf = d * 6000 + e * 2000 + f;
		if( pc > pf ) printf("C\n");
		else if( pc == pf ) printf("=\n");
		else printf("F\n");
	}
}

