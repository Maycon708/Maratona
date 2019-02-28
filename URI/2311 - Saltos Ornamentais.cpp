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
	int n;
	char s[1000];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			double m, sum = 0, mn = 1 << 30, mx = 0, a;
			scanf("%s", s );
			scanf("%lf", &m );
			rep( i, 0, 7 ){
				scanf("%lf", &a );
				sum += a;
				mn = min( mn, a );
				mx = max( mx, a );
			}
			sum -= ( mn + mx );
			printf("%s %.2f\n", s, sum * m );
		}
	}
}

