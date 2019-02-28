#include <bits/stdc++.h>
  
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
  
using namespace std;
  
typedef long long ll;
typedef pair < int, int >  ii;
 
bool term[1001000]; // terminal
int S[1001000][30]; // TRIE
int T[100100]; // arestas de volta
int pd[55][100100];
int t;
int L;
 
int topo;
 
void add ( string s ){
    int x = 0;
    rep(i, 0, s.size()){
        int k = s[i] - 'a';
        if(!S[x][k]){
            S[x][k] = topo++;
        }
        x = S[x][k];
    }
    term[x] = 1;
}

int percorre( string s ){
	int x = 0;
	int cont = 0;
    rep(i, 0, s.size()){
        
        int k = s[i] - 'a';
        int aux = 0;
        
        rep(j, 0, 26)
        	if( ( j != k && S[x][j] ) || ( !x ) ) aux = 1;
        
        if( term[x] ) aux = 1;
        
        x = S[x][k];
        cont += aux;
    }
    return cont;
}

string s[100100];

int main(){

	int n;

	while( scanf("%d", &n) != EOF ){
		
		topo = 1;
		memset( S, 0, sizeof S );
		memset( term, false, sizeof term );
		
		rep(i, 0, n){
			cin >> s[i];
			add( s[i] ); 		
		}
		double ans = 0;
		rep(i, 0, n){
			ans += percorre( s[i] );
		}		
		printf("%.2lf\n", ans/n);
	}
}
