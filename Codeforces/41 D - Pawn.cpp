#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

char mat[200][200];
int pd[200][200][15], K, n, m, memo[200][200][15];

int solve( int x, int y, int k ){
	if( x == n ) return k ? (-(1<<30)) : 0;
	int &ans = pd[x][y][k];
	if( ans == -1 ){
		int aux = ( k + mat[x][y]-'0' )%K, a = (-(1<<30)), b = (-(1<<30));
		if( y+1 <  m ) a = solve( x+1, y+1, aux ) + mat[x][y]-'0';
		if( y-1 >= 0 ) b = solve( x+1, y-1, aux ) + mat[x][y]-'0';
		if( a > b ) memo[x][y][k] = 1;
		ans = max( a, b );
	}
	return ans;
}

void reconstruct( int x, int y, int k ){
	if( x == n-1 ){
		printf("\n");
		return;
	}	
	int aux = ( k + mat[x][y]-'0' )%K;
	if( memo[x][y][k] ){
		printf("R");
		reconstruct(x+1, y+1, aux);
	}
	else{
		printf("L");
		reconstruct(x+1,y-1, aux);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &K ); K++;
	for( int i = n-1; i >= 0; i-- ) scanf("%s", mat[i] );
	memset( pd, -1, sizeof pd );
	int best = -1, id;
	rep( i, 0, m ){
		int tmp = solve(0, i, 0);
		if( tmp > best ){
			best = tmp, id = i;
		}
	} 
	printf("%d\n", max( -1, best ) );
	if( best > -1 ) printf("%d\n", id+1 ), reconstruct( 0, id, 0 );
}

