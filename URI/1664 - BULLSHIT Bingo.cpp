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

int mdc( int a, int b ){
	if( !a ) return b;
	return mdc( b%a, a );
}

char c[1000100];
int main(){
	int num = 0, den = 0;
	map < string, int > mp;
	mp.clear();
		
	while( gets( c ) ){
//		if( strcmp(c, "*") == 0 ) break;
		int tam = strlen( c );
		string s = "";
		bool aux = 0;
		rep( i, 0, tam ){
			c[i] = toupper( c[i] );
			if( c[i] >= 'A' && c[i] <= 'Z' ){
				s += c[i];
				aux = 1;
			}
			else{
				if( !aux ){
					s = "";
					continue;
				}
				aux = 0;
				if( s == "BULLSHIT" ){
					den++;
					num += mp.size();
					mp.clear();
				}
				else{
					mp[s] = 1;
				}
				s = "";
			}
		}
		
		if( s == "BULLSHIT" ){
			den++;
			num += mp.size();
			mp.clear();
		}
		else if( s != "" ) mp[s] = 1;
	}
//	debug2( num, den )
	int MDC = mdc( num, den );
	printf("%d / %d\n", num/MDC, den/MDC );
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

