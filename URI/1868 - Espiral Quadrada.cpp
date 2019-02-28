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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

bool fora(int x, int y, int n){
	return (x<0 || x>=n || y<0 || y>=n);
}

int main(){
	
	int n;
	bool vis[50][50], up, down, left, right;
	char m[50][50];
	
	while(scanf("%d", &n) && n){
		
		up = down = right = false;
		left = true;
		
		rep(i, 0, n){
			rep(j, 0, n){
				m[i][j] = 'O';
				vis[i][j] = false;
			}
			m[i][n] = '\0';
		}
			
		
		int x = n/2, y = n/2;
			
		while(1){
			
			if(fora(x, y, n)) break;
			
			m[x][y] = 'X';
			vis[x][y] = true;
			
			rep(i, 0, n)
				printf("%s\n", m[i]);
			
			printf("@\n");
			
			m[x][y] = 'O';
				
			if(left){
				if(!vis[x][y+1]){
					y = y+1;
					left = false;
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
					right = true;
				}
				else{
					y = y+1; 
				}
			}
			else if(right){
				if(!vis[x][y-1]){
					y = y-1;
					right = false;
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
					left = true;
				}
				else{
					y = y-1; 
				}
			}
			
		}
		
	}

	return 0;
}

