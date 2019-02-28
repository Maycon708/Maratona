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

queue < int > q[10];

inline bool C(){
	rep( i, 2, 10 ){
		if( q[i].size() ) return 0;
	}
	return 1;
}

int main(){
	char aux[] = {"0123456789"};
	char s[1000];
	while( 1 ){
		string S = "";
		int n = readInt();
		if( n == -1 ) break;
		rep( i, 2, n+1 ){
			scanf("%s", s );
			int tam = strlen( s );
			rep( j, 0, tam ){
				q[i].push( s[j] - '0' );
			}
		}
		int i = 2;
		while( 1 ){
			if( i == 10 ) i = 2;
			if( C() ) break;
			if( q[i].empty() ){
				i++; continue;
			}
			int u = q[i].front();
			if( u == 1 ){
				q[i].pop();
				S += aux[i];
				continue;
			}
			if( q[u].front() == i ){
				q[i].pop(); q[u].pop();
			}
			else i++;
		}
		cout << S << endl;
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

