#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	
	float a, b;
	double c, d;
	
	while( cin >> a >> b >> c >> d ){
		printf("A = %.6f, B = %.6f\nC = %.6f, D = %.6f\n", a, b, c, d );
		printf("A = %.1f, B = %.1f\nC = %.1f, D = %.1f\n", a, b, c, d );
		printf("A = %.2f, B = %.2f\nC = %.2f, D = %.2f\n", a, b, c, d );
		printf("A = %.3f, B = %.3f\nC = %.3f, D = %.3f\n", a, b, c, d );
		printf("A = %.3E, B = %.3E\nC = %.3E, D = %.3E\n", a, b, c, d );
		printf("A = %.0f, B = %.0f\nC = %.0f, D = %.0f\n", a, b, c, d );
	}
	
}
