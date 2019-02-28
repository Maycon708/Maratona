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

int C( char c ){
	char aux[] = { "57630499617851881234762239" };
	c = toupper(c);
	if( c >= 'A' && c <= 'Z' ) return aux[c - 'A'] - '0';
	return -1;
}

int S( char c ){
	if( c >= '0' && c <= '9' ) return c - '0';
	return -1;
}

const int cc = 10;
const int MAX = 1000000;

int cnt;
int sig[MAX][cc];
vector<int> term[MAX];
int T[MAX];
int v[MAX];

void add( string s, int id ){
	int x = 0;
	rep( i, 0, s.size() ){		
		int c = C( s[i] );
		if( c == -1) continue;
		if( !sig[x][c] ){
			term[cnt].clear();
			sig[x][c] = cnt++;
		}
		x = sig[x][c];
	}
	term[x].pb(id);
}

string s[75001], ss;
int tam;
vector<string> resp;

void busca( int ini, vector<int> ans, bool can ){
	int x = 0;
	if( ini == tam ){
		string kk;
		rep( i, 0, ans.size() ){
			kk += " ";
			kk += s[ans[i]].c_str();
		}
		resp.pb(kk);
		return;
	}	
	if( ss[ini] < '0' || ss[ini] > '9' ){
		busca( ini+1, ans, can );
		return;
	}

	bool k = 1;
	if( can ){
		rep( i, 0, 10 )
			if( sig[x][i] ) k = 0;
		if( k ){
			ans.pb( ss[ini] - '0' );
			busca( ini+1, ans, 0 );
			ans.pop_back();
			return;
		} 		
	}
	rep( i, ini, tam ){
		int u = S( ss[i] );
		if( u == -1 ) continue;
		if( !sig[x][u] ) break;
		x = sig[x][u];
		if( !term[x].empty() ){
			rep( j, 0, term[x].size() ){
				ans.pb( term[x][j] );
				busca( i+1, ans, 1 );
				ans.pop_back();
				can = 0;
			}
		}
	}
	if( can ){
		ans.pb( ss[ini] - '0' );
		busca( ini+1, ans, 0 );
		ans.pop_back();
	} 
}

int main(){
	int n, test = 1;
	rep( i, 0, 10 ) s[i] += char('0'+i);
//	freopen( "lisp.in", "r", stdin );
	while( scanf("%d", &n ) != EOF && n ){
		if( test != 1 ) printf("\n");
		memset( sig, 0, sizeof sig );
		cnt = 1;
		rep( i, 10, n+10 ){
			cin >> s[i];
			add(s[i], i);	
		}
		printf("Instancia %d\n", test++ );
		scanf("%d", &n );
		rep( i, 0, n ){
			cin >> ss;
			tam = ss.size();
			vector<int> aux;
			busca(0, aux, 1 );
			sort( all(resp) );
			rep( i, 0, resp.size() ){
				printf("%s:%s\n", ss.c_str(), resp[i].c_str() );		
			}
			resp.clear();
		}
	}
}

