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
	int a, mat[10][10];
	int dx[] = { 1, -1, 0, 0, 0 };
	int dy[] = { 0, 0, 1, -1, 0 };
	while(42){
		rep( i, 0, 10 ) rep( j, 0, 10 ) mat[i][j] = 1;
		rep( i, 1, 4 ){
			rep( j, 1, 4 ){
				scanf("%d", &a );
				for( int k = 0; k < 5 && (a&1); k++ )
					mat[i+dx[k]][j+dy[k]] ^= 1;
			}
		}
		rep( i, 1, 4 ){
			rep( j, 1, 4 )
				printf("%d", mat[i][j] );
			printf("\n");
		}
		break;
	}
}

