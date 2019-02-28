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

int main(){
	char s[60], m[60][60];
	int t = readInt();
	while( t-- ){
		int l = readInt();
		int c = readInt();
		rep( i, 0, l ){
			scanf("%s", m[i] );
		}
		int p = readInt();
		while( p-- ){
			scanf("%s", s );
			int k = 0, tam = strlen(s);
			int cont = 0;
			rep( i, 0, l ){
				rep( j, 0, c ){
					if( m[i][j] == s[0] ){
						k = 0;
						int I = i;
						while( m[I][j] == s[k] && k < tam && I < l ){
							I++; k++;
						}
						if( k == tam ){
							cont++;
//								debug2( I, j )
						}
						if( tam == 1 ) continue;
						k = 0;
						int J = j;
						while( m[i][J] == s[k] && k < tam && J < c ){
							J++; k++;
						}
						if( k == tam ) cont++;
					}
				}
			}
			printf("%d\n", cont );
		}
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

