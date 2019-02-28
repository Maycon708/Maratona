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
	while( scanf("%d", &n ) != EOF ){
		char s[10000];
		int a, b, c, d, e, f;
		double r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0;
		rep( i, 0, n ){
			scanf("%s", s );
			scanf("%d%d%d", &a, &b, &c );
			scanf("%d%d%d", &d, &e, &f );
			r1 += a, r2 += b, r3 += c;
			r4 += d, r5 += e, r6 += f;
		}
		double s1 = 0, s2 = 0, s3 = 0;
		if( r1 ) s1 = r4/r1;
		if( r2 ) s2 = r5/r2;
		if( r3 ) s3 = r6/r3;
		printf("Pontos de Saque: %.2lf %%.\n", s1 * 100 );
		printf("Pontos de Bloqueio: %.2lf %%.\n", s2 * 100 );
		printf("Pontos de Ataque: %.2lf %%.\n", s3*100 );
	}
}

