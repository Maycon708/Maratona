#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugP(a) cout << "F" << " = " << a.first << " --- " << "S" << " = " << a.second << "\n";
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int MAXV = 1111;
vector <int> adj[MAXV];
int cor[MAXV];

int readInt () {
    bool minus = false;
    int result = 0; char ch;
 
    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

bool ehbipartido(){
    queue < int > q;
    q.push(1);
    cor[1] = 0;
    bool bipartido = true;
    while( !q.empty() && bipartido ){
        int u = q.front();
        q.pop();
        int tam = adj[u].size();
        rep( i, 0, tam ){
            int v = adj[u][i];
            if( cor[v] == -1 ){
                cor[v] = 1 - cor[u];
                q.push(v);
            }
            else if( cor[v] == cor[u] )
                return false;
        }
    }
    return true;        
}
 
int main(){
	
	int n, aux;
	
	while( scanf("%d", &n) != EOF ){
		
		rep( i, 0, n ){
            adj[i].clear();
            cor[i] = -1;
        }
		rep( i, 0, n ){
			rep( j, 0, n ){
				aux = readInt();
				if( !aux ){
					adj[i].pb(j);
				}
			}
		}
		if( ehbipartido() ) printf("Bazinga!\n");
        else printf("Fail!\n");
	}	
	
	return 0;
}

