#include<bits/stdc++.h>

#define rep(i,a,b) for( int i = a; i < b; i++ )

using namespace std;

int main(){
	
	int n, k, ans[111][111];
	char mat[111][111];
	
	while( cin >> n >> k ){
		rep( i, 0, n ) scanf("%s", mat[i] );
		
		rep( i, 0, n ) rep( j, 0, n ) ans[i][j] = 0;
		
		rep( i, 0, n ){
			rep( j, 0, n ){
				int cnt = 0;
				rep( ii, 0, k ){
					if( i + ii >= n ) break;
					if( mat[i+ii][j] == '#') break;
					cnt++; 
				}
				if( cnt == k ){
					rep( ii, 0, k ) ans[i+ii][j]++;
				}
				cnt = 0;
				rep( jj, 0, k ){
					if( j + jj >= n ) break;
					if( mat[i][j+jj] == '#') break;
					cnt++; 
				}
				if( cnt == k ){
					rep( jj, 0, k ) ans[i][j+jj]++;
				}
			}
		}
		
		int anss  = 0;
		int x = 0, y = 0;
		
		rep( i, 0, n ){
			rep( j, 0, n ){
				if( ans[i][j] > anss ){
					x = i, y = j;
					anss = ans[i][j];
				}
			}
		}
		
		printf("%d %d\n", x+1, y+1 );
		
		
	}
	
	
}