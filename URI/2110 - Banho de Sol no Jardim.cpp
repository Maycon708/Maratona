#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
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

int main(){

	int n, l, d, v[110];
	while( scanf("%d%d%d", &n, &l, &d ) != EOF ){
		int pos;
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			if( !v[i] ) pos = i;
		}
		double a1 = 0, a2 = 0;
		rep( i, 0, n ){
			if( i < pos ){
				double aux = pos - i;
				aux = aux * ( l + d );
				a1 = max( a1, atan( v[i]/aux ) );
			}
			if( i > pos ){
				double aux = i - pos;
				aux = aux * ( l + d );
				a2 = max( a2, atan( v[i]/aux ) );
			}
		}
		double a =  pi - a2 - a1;
		double resp = ( 16 * 60 * a )/ ( pi );
		printf("%.2f\n", resp );
//		pi --- 16*60
//		a  --- resp
	}

}

