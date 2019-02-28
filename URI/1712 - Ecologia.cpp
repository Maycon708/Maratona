#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

#define MAXN 55

ii coord[MAXN], path[MAXN];
int used[MAXN][MAXN];
int mat[MAXN][MAXN], maxsum, N, M, nused;
int dx[] = { 1, 0, -1, 0 };

//0->unused , 1->t o be used , 2->used
void dfs ( int sum, int h, int n) {
	used[coord[n].first][coord[n].second] = 2;
	path[h] = coord[n];
	if(h == M){
		maxsum = max(maxsum , sum ) ;
		used[coord[n].first][coord[n].second] = 1;
		return ;
	}
	int nadded = 0;
	ii next;
	for(int i=0; i<4; i++){
		next = ii( coord[n].F+dx[i], coord[n].S+dx[i^1] );
		if(!used[next.first][next.second]){
			used[next.first][next.second] = 1;
			coord[nused] = next;
			nadded++; nused++;
		}
	}
	for(int i=n+1, nextsum; i<nused; i++){
		nextsum = mat[coord[i].first][coord[i].second];
		dfs( sum + nextsum , h+1, i );
	}
	while ( nadded-->0){
		nused--;
		next = coord[nused];
		used[next.first][next.second] = 0;
	}
	used[coord[n].first][coord[n].second] = 1;
}

int main(){
	while( scanf("%d%d", &N, &M ) != EOF ){
		rep( i, 1, N+1 ){
			used[0][i] = used[i][0] = used[N+1][i] = used[i][N+1] = 1;
			rep( j, 1, N+1 ){
				scanf("%d", &mat[i][j] );
				used[i][j] = 0;
			}
		}
		rep( i, 1, N+1 ){
			rep( j, 1, N+1){
				nused = 1;
				coord[0] = ii( i, j );
				dfs(mat[i][j], 1, 0);
			}
		}
		printf("%d\n", maxsum );
	}
}
