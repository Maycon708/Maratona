#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) 																									cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM(x,l,c) 																									{ rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	int n, mat[55][55], c[55], l[55];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) c[i] = l[i] = 0;
		rep( i, 0, n ){
			rep( j, 0, n ){
				scanf("%d", &mat[i][j] );
				l[i] += mat[i][j];
				c[j] += mat[i][j]; 
			}
		}
		int aux;
		rep( i, 0, 2 )
			rep( j, i+1, n ){ 
				if( l[j] == l[i] ){
					aux = l[i];
					break;
				}
			}	
		int x, y;
		rep( i, 0, n ){
			if( c[i] != aux ) y = i;
			if( l[i] != aux ) x = i;
		}
		printf("%d %d\n", mat[x][y] + ( aux - c[y] ), mat[x][y] );
	}
}

