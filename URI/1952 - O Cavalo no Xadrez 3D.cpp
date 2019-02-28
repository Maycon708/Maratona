#include <bits/stdc++.h>
    
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debug3(x,y,z) cout << #x << " = " << x << " --- " << #y << " " << y << " --- " << #z << " " << z << "\n";
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
    
using namespace std;
    
typedef long long ll;
typedef pair < int, int >  ii;

struct ponto {
    int x, y, z, c;
};

int dx[] = { 0,  0,  0,  0, 0,  0,  0,  0, 2,  2, 2,  2, -2, -2, -2, -2, 1,  1, 1,  1, -1, -1,-1, -1};
int dy[] = { 1,  1, -1, -1, 2,  2, -2, -2, 0,  0, 1, -1,  0,  0,  1, -1, 0,  0, 2, -2,  0,  0, 2, -2};
int dz[] = { 2, -2,  2, -2, 1, -1,  1, -1, 1, -1, 0,  0,  1, -1,  0,  0, 2, -2, 0,  0,  2, -2, 0,  0};
int n, m, l;
bool vis[210][210][210];

bool dentro ( ponto aux ){
    return aux.x > 0 && aux.x<=n && aux.y > 0 && aux.y <= m && aux.z > 0 && aux.z <= l;
}

int bfs(ponto ini, ponto fim){

    queue < ponto > q;

    q.push( ini );
    
    while(!q.empty()){
    
        ponto aux1 = q.front();
        q.pop();
        int x = aux1.x;
        int y = aux1.y;
        int z = aux1.z;
        int c = aux1.c;
        
       // debug3(x, y, z)
        if(vis[x][y][z]) continue;
        vis[x][y][z] = true;
        
        if( x == fim.x && y == fim.y && z == fim.z ) return c;
        
        rep(i, 0, 24){
            ponto aux;        
            aux.x = x + dx[i];
            aux.y = y + dy[i];
            aux.z = z + dz[i];
            aux.c = c + 1;
            if( dentro(aux) ) q.push(aux);        
        }
    }
}

int main(){
    
    int x1, x2, y1, y2, z1, z2;
    
    cin >> n >> m >> l;
    
    cin >> x1 >> y1 >> z1;
    
    cin >> x2 >> y2 >> z2;
    
    ponto ini, fim;
    
    ini.x = x1, ini.y = y1, ini.z = z1, ini.c = 0;        
    fim.x = x2, fim.y = y2, fim.z = z2, fim.c = 0;        
        
    cout << bfs(ini, fim) << endl;
}
