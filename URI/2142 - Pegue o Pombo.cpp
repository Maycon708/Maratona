#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%3d ", x[i][j]); printf("\n");}}
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

bool fora(int x, int y, int n){
	return (x<0 || x>=n || y<0 || y>=n);
}

bool vis[1050][1050], up, down, l, r;
int m[1050][1050], t;

int main(){
	
	int n, mm;
	
	while(scanf("%d%d", &n, &mm ) != EOF ){
		if( 3*mm > n ){
			printf("Raios! Raios Duplos! Raios Triplos!\n");
			continue;
		}
		int aux = log10(n) + 1;
		n = sqrt(n);
		int t = 1, x, y;
		up = down = l = 0; r = 0;
		if( n & 1 ) r = 1, x = n/2, y = n/2;
		else l = 1, x = n/2, y = (n-1)/2;
		
		rep( i, 0, n )
			rep( j, 0, n )
				vis[i][j] = 0;
			
		while(1){
			
			if(fora(x, y, n)) break;
			
			m[x][y] = t++;
			vis[x][y] = true;
			
			if(l){
				if(!vis[x][y+1]){
					y = y+1;
					l = false;
					up = true;
				}
				else{
					x = x+1; 
				}
			}
			else if(up){
				if(!vis[x-1][y]){
					x = x-1;
					up = false;
					r = true;
				}
				else{
					y = y+1; 
				}
			}
			else if(r){
				if(!vis[x][y-1]){
					y = y-1;
					r = false;
					down = true;
				}
				else{
					x = x-1; 
				}
			}
			else if(down){
				if(!vis[x+1][y]){
					x = x+1;
					down = false;
					l = true;
				}
				else{
					y = y-1; 
				}
			}
		}
		rep( i, 0, n ){ 
			rep( j, 0, n ){
				if( m[i][j] == 2 * mm ) printf("%*c", aux, '*' );
				else if( m[i][j] == 3 * mm ) printf("%*c", aux, '!' ); 
				else printf("%*d", aux, m[i][j]);
				if( i != n-1 || j != n-1 ) printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}

