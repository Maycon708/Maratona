#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

inline int cmp( double x, double y = 0, double tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

int main(){
	int w1, w2, r, t = 0;
	double m, sum = 0;
	while( scanf("%d%d%d", &w1, &w2, &r ) != EOF ){
		if( !w1 && !w2 && !r ) break;
		m =  w1 * ( 1 + r/30.0 );
		m += w2 * ( 1 + r/30.0 );	
		sum += m;
		m /= 2;
		if( cmp( m, 13 ) == -1 ) printf("Nao vai da nao\n");
		else if( cmp( m, 14 ) == -1 ) printf("E 13\n");
		else if( cmp( m, 40 ) == -1 ) printf("Bora, hora do show! BIIR!\n");
		else if( cmp( m, 60 ) !=  1 ) printf("Ta saindo da jaula o monstro!\n");
		else printf("AQUI E BODYBUILDER!!\n");
		t += 2;
	}
	if( sum/t > 40 ) 
		printf("\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n");
}
