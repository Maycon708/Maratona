#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

map < string, int > mp;
ll readInt();

void init(){
	mp[  "HANDGUN"  ] = 20;
	mp[   "RED9"    ] = 35;
	mp[ "BLACKTAIL" ] = 35;
	mp[  "MATILDA"  ] = 20;
	mp[ "HANDCANNON"] = 600;
	mp[ "HANDCANON" ] = 600;
	mp[  "STRIKER"  ] = 120;
	mp[    "TMP"    ] = 12;
	mp[   "RIFLE"   ] = 120;
	mp[  "GANADOS"  ] = 500;
	mp[  "COBRAS"   ] = 400;
	mp[  "ZEALOT"   ] = 750;
	mp[ "COLMILLOS" ] = 600;
	mp[ "GARRADOR"  ] = 1250;
	mp[ "LASPLAGAS" ] = 1000;
	mp[ "GATLINGMAN"] = 1500;
	mp["REGENERATOR"] = 2500;
	mp[ "ELGIGANTE" ] = 5000;
	mp["DR.SALVADOR"] = 3500;
}

int pd[10][10010], v[10];
int p[10], n;

int solve( int pos, int cap ){
	if( pos == n || !cap ) return 0;
	if( pd[pos][cap] > -1 ) return pd[pos][cap];
	int ans = solve( pos+1, cap );
	if( cap >= p[pos] ) ans = max( ans, solve( pos+1, cap - p[pos] ) + v[pos] );
	return pd[pos][cap] = ans; 
}

int main(){
	init();
	int q, m, cap;
	char s[20];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			scanf(" %s", s );
			q = readInt();
			v[i] = mp[s] * q; p[i] = q;
		}
		m = readInt();
		int a = 0;
		rep( i, 0, m ){
			scanf(" %s", s );
			q = readInt();
			a += mp[s] * q;
		}
		cap = readInt();
		rep( i, 0, n )
			rep( j, 0, cap+1 ) 
				pd[i][j] = -1;
		
		int b = solve( 0, cap );
		if( b >= a ) puts("Missao completada com sucesso\n");
		else puts("You Are Dead\n");
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


