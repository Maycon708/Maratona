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

	int n, t = 1;
	ii v[1100];
	while( cin >> n ){
		if( !n ) break;
		int aux = 0;
		rep( i, 0, n ){
			int x, y;
			cin >> x >> y;
			aux = max( aux, y );
			v[i] = ii( x, y );			
		}
		printf("Turma %d\n", t++ );
		bool a = 0;
		rep( i, 0, n ){
			if( v[i].S == aux ){
				if( a ) printf(" ");
				a = 1;
				printf("%d", v[i].F );
			}
		}
		printf("\n\n");
	}
	
}

