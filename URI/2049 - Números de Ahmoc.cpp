#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

const int MAX = 300100, cc = 10;

int term[MAX], sig[MAX][cc], T[MAX], cnt;

void add( string s ){
	int tam = s.size(), x = 0;
	rep( i, 0, tam ){
		int c = s[i] - '0';
		if( !sig[x][c] ){
			term[cnt] = 0;
			sig[x][c] = cnt++;
		}
		x = sig[x][c];
	}
	term[x] = 1;
}

void aho(){
	queue < int > q;
	rep( i, 0, cc ){
		int x = sig[0][i];
		if( !x ) continue;
		T[x] = 0;
		q.push( x );
	}
	while( !q.empty() ){
		int u = q.front(); q.pop();
		rep( i, 0, cc ){
			int x = sig[u][i];
			if( !x ) continue;
			int v = T[u];
			while( v && !sig[v][i] ) v = T[v];
			int y = sig[v][i];
			q.push( x ); T[x] = y; term[x] |= term[y]; 
		}
	}
}

inline bool busca( string s ){
	s += s;
	int tam = s.size();
	int x = 0;
	rep( i, 0, tam ){
		int c = s[i] - '0';
		while( x && !sig[x][c] ) x = T[x];
		x = sig[x][c];
		if( term[x] ) return 1;
	}
	return 0;
}

int main(){
	string pattern, text;
	int T = 1;
	while( 1 ){
		cin >> pattern;
		if( pattern == "0" ) break;
		if( T != 1 ) printf("\n");
		memset( sig, 0, sizeof sig );
		cnt = 1;
		cin >> text;
		add( pattern );
		aho();
		printf("Instancia %d\n", T++ );
		if( busca( text ) ) printf("verdadeira\n");
		else printf("falsa\n");
	}

}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

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

