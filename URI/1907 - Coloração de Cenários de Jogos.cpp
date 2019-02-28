#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

int l, c, dx[] = {1, -1, 0, 0 }, dy[] = {0, 0, 1, -1};
char m[1025][1025];

bool dentro(int i, int j){
	return (i>=0 && i<l && j>=0 && j<c);
}

void dfs(int i, int j){
	
	m[i][j] = 'o';
	
	rep(k, 0, 4){
		int xx = i+dx[k], yy = j+dy[k];
		if( dentro(xx, yy) && m[xx][yy] != 'o') dfs(xx, yy);
	}
	return; 
}

int main(){
//	freopen("code.in", "r", stdin);
// 	freopen("out_maycon.txt", "w", stdout);

	int cont = 0;
	
	scanf("%d%d", &l, &c);
	
	rep(i,0,l)
		scanf(" %s", m[i]);
			
			
	rep(i,0,l)
		rep(j,0,c)
			if(m[i][j] != 'o'){
				cont++;
				dfs(i,j);
			}
	
	printf("%d\n", cont);

	return 0;
}


