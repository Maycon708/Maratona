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

double pd[10][2], p;
int n;
string s1, resp;

double solve( int pos, int prefix ){
	if( pos == n ) return !prefix; // se o numero for igual retorna 0, pois procura-se a prob de ser diferente
	if( pd[pos][prefix] > -1 ) return pd[pos][prefix];
	double ans = 0;
	if( prefix ){
		int ck = ( s1[pos] == resp[pos] ); // prefixo permanece 1 se for diferente e mudar ou se for igual e mudar
		ans += ( solve( pos+1, ck ) * (1.0-p) ); // prob de não mudar
		ans += ( solve( pos+1, !ck ) * p ); // prob de mudar
	}
	else{
		ans += ( solve( pos+1, 0 ) );//* (1.0-p) ); // prob de não mudar
//		ans += ( solve( pos+1, 0 ) * p ); // prob de mudar
	}
	return pd[pos][prefix] = ans;
}

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

int main(){
	char S1[20], S2[20]; 
	int t = readInt(), m;
	while( t-- ){
		n = readInt();
		scanf("%d%lf", &m, &p );
		scanf("%s", S1 );
		scanf("%s", S2 );
		cin >> resp;
		double ans = 1;
		rep( k, 0, 2 ){
			s1 = "";
			rep( i, 0, n ) pd[i][0] = pd[i][1] = -10;
			rep( i, 0, m ){
				if( k )s1 += S1[i];
				else s1 += S2[i];
			}
			rep( i, m, n ){
				if( k ) s1 += S2[i];
				else s1 += S1[i];
			}
			ans *= solve( 0, 1 );
		}
		printf("%.7f\n", 1 - ans );
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


