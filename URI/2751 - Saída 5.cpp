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
	
	int a = 15, b = a/2;
	float c, d;
	c = 15.456;
	d = c/7;
	
	printf("Valores de b:\n");
	printf("-------------\n");
	printf("1) b = %d\n", b );
	printf("2) b = %20d\n", b );
	printf("3) b = %020d\n", b );
	printf("4) b = %-20d\n", b );
	printf("5) b = %d\%\n", b );
	printf("\n");
	printf("Valores de d:\n");
	printf("-------------\n");
	printf("1) d = %.6f\n", d );
	printf("2) d = %d\n", (int)d );
	printf("3) d = %.1f\n", d );
	printf("4) d = %.2f\n", d );
	printf("5) d = %.3f\n", d );
	printf("6) d = %20.3f\n", d );
	printf("7) d = %020.3f\n", d );
	printf("8) d = %-020.3f\n", d );
	printf("9) d = %.2f\%\n", d );
	
	
}
