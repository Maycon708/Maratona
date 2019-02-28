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
	
		int x1[2], y1[2], x2[2], y2[2];
	
		while( scanf("%d%d%d%d", &x1[0], &y1[0], &x2[0], &y2[0] ) != EOF ){
			scanf("%d%d%d%d", &x1[1], &y1[1], &x2[1], &y2[1] );
			int id = ( x1[0] > x1[1] );
			if( x2[id] > x1[!id] ){
				if( y1[id] > y2[!id] || y2[id] < y1[!id] ) puts("inexistente");
				else if( y1[id] == y2[!id] || y2[id] == y1[!id] ) puts("linha");
				else{
					int area = ( min( x2[id], x2[!id] ) - max( x1[id], x1[!id] ) );
					if( y1[id] < y2[!id] ) area *= ( y2[!id] - max( y1[id], y1[!id]) );
					else area *= ( y2[id] - max( y1[id], y1[!id] ) );
					if( area > 10 ) puts("grande");
					else puts("adequada");
				}
		
			}
			else if( x2[id] == x1[!id] ){
				if( y1[id] > y2[!id] || y2[id] < y1[!id] ) puts("inexistente");
				else 	if( y1[id] == y2[!id] || y2[id] == y1[!id] ) puts("ponto");
				else puts("linha");
			}		
			else puts("inexistente");
		}

	}
