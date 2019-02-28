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

int l, c, dx[] = {1, -1, 0, 0 }, resp, xxx, yyy, dy[] = {0, 0, 1, -1}, vis2[1025][1025];
bool vis[1025][1025];
char m[1025][1025];

bool dentro(int i, int j){
	return (i>=0 && i<l && j>=0 && j<c);
}

vector <ii> v;

void bfs(int a, int b){
		
	queue < pair < ii, int > > q;
	
	q.push(mp(ii(a,b), 0));
	
	while(!q.empty()){
		
		int i = q.front().F.F;
		int j = q.front().F.S;
		int c = q.front().S; 
		q.pop();
		
		vis[i][j] = true;
		
		if(c>resp){
			v.clear();
			v.pb(ii(i,j));
			resp = c;
		}
		if(c==resp){
			v.pb(ii(i,j));
		}
		
		rep(kk, 0, 4){
			int xx = i+dx[kk], yy = j+dy[kk];
			if( dentro(xx, yy) && m[xx][yy] != '#' && !vis[xx][yy]) q.push(mp(ii(xx,yy), c+1));
		}
	}
	return; 
}
void bfs2(int a, int b, int k){
		
	queue < pair < ii, int > > q;
	
	q.push(mp(ii(a,b), 0));
	
	while(!q.empty()){
		
		int i = q.front().F.F;
		int j = q.front().F.S;
		int c = q.front().S; 
		q.pop();
		
		vis2[i][j] = k;
		
		resp = max(resp, c);
		
		rep(kk, 0, 4){
			int xx = i+dx[kk], yy = j+dy[kk];
			if( dentro(xx, yy) && m[xx][yy] != '#' && vis2[xx][yy]!= k) q.push(mp(ii(xx,yy), c+1));
		}
	}
	return; 
}

int main(){
//	freopen("code.in", "r", stdin);
// 	freopen("out_maycon.txt", "w", stdout);

	int cont = 0;
	
	while(scanf("%d%d", &l, &c) && l+c){
		
		memset(vis, false, sizeof(vis));
		memset(vis2, -1, sizeof(vis2));
		
		resp = 0;
		
		rep(i,0,l)
			scanf(" %s", m[i]);
				
				
		rep(i,0,l)
			rep(j,0,c)
				if(m[i][j] != '#' && !vis[i][j]){
					bfs(i,j);
				}
		
		int k = 1;		
				
		rep(i,0,v.size())
			bfs2(v[i].F,v[i].S, k++);
		
		printf("%d\n", resp);
	}
	return 0;
}
