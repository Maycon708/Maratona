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

int v[] = { 0, 1, 2, 3, 4 };
int mat[6][6];
	
int C(){
	int ans = 0;
	rep( i, 0, 4 )
		for( int j = i ; j < 4; j += 2 )
			ans += ( mat[v[j]][v[j+1]] + mat[v[j+1]][v[j]] );
	return ans;
}

int main(){
	rep( i, 0, 5 ){
		rep( j, 0, 5 ){
			scanf("%d", &mat[i][j] );
		}
	}
	int ans = 0;
	do{
		ans = max( ans, C() );
	}while( next_permutation(v, v+5 ) );
	printf("%d\n", ans );
}

