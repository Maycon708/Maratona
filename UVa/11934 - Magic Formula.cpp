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
	ll a, b, c, d, n;
	while( scanf("%lld%lld%lld%lld%lld", &a,&b, &c, &d, &n ) != EOF ){
		if( !a && !b && !c && !d && !n ) break;
		int cnt = 0;
		rep( i, 0, n+1 ){
			ll aux = a * i * i + b * i + c;
			if( aux%d == 0 ) cnt++;
		}
		printf("%d\n", cnt );
	}
}

