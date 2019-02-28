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
	char s1[100], s2[100];
	int t = readInt();
	while( t-- ){
		scanf("%s", s1 );
		scanf("%s", s2 );
		if( !strcmp( s1, "pedra" )){
			if( !strcmp( s2, "pedra" )){
				printf("Sem ganhador\n");
			}
			else if( !strcmp( s2, "papel" )){
				printf("Jogador 1 venceu\n");
			}
			else if( !strcmp( s2, "ataque" )){
				printf("Jogador 2 venceu\n");
			}
		}
		else if( !strcmp( s1, "papel" )){
			if( !strcmp( s2, "pedra" )){
				printf("Jogador 2 venceu\n");
			}
			else if( !strcmp( s2, "papel" )){
				printf("Ambos venceram\n");
			}
			else if( !strcmp( s2, "ataque" )){
				printf("Jogador 2 venceu\n");
			}
		}
		else if( !strcmp( s1, "ataque" )){
			if( !strcmp( s2, "pedra" )){
				printf("Jogador 1 venceu\n");
			}
			else if( !strcmp( s2, "papel" )){
				printf("Jogador 1 venceu\n");
			}
			else if( !strcmp( s2, "ataque" )){
				printf("Aniquilacao mutua\n" );
			}
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

