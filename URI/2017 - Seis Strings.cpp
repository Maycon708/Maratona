#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 100005
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
#define LSOne(S) (S & (-S))
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

char s1[100010], s[10][100010];

int main(){
	ii cont[10];
	while( scanf("%s", s1 ) != EOF ){
		int n = readInt();
		rep( i, 0, 5 ){
			cont[i] = ii( 0, i );
			scanf("%s", s[i] );
		}
		int tam = strlen( s1 );		
		rep( i, 0, tam ){
			rep( j, 0, 5) cont[j].F += ( s1[i] != s[j][i] );
		}
		sort( cont, cont+5 );
//		rep( i, 0, 5 ) debug2( cont[i].F, cont[i].S )
		if( cont[0].F > n )
			printf("-1\n");
		else 
			printf("%d\n%d\n", cont[0].S+1, cont[0].F);
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

