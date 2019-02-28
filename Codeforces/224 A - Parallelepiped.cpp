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
	int a, b, c;
	while( scanf("%d%d%d", &a, &b, &c ) != EOF ){
		int ans = 0;
		rep( i, 1, a+1 ){
			if( a%i ) continue;
			int aa = a/i;
			if( b%i == 0 && c%aa == 0 && b/i == c/aa ) ans = i + aa + b/i;
			if( b%aa == 0 && c%i == 0 && c/i == b/aa ) ans = i + aa + c/i;
			if( ans ) break;
		}
		printf("%d\n", ans << 2 );
	}
}
