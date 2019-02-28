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

inline int C ( char c ){
	if( c >= '0' && c <= '9') return c - '0';
	return c -'A' + 10;
}

int main(){
	char aux[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string s1, s2, resp;
	while( 1 ){
		resp = "";
		cin >> s1 >> s2;
		if( s1 == "0" && s2 == "0" ) break;
		reverse( all( s1 ) );
		reverse( all( s2 ) );
		int carry = 0;
		rep( i, 0, min( s1.size(), s2.size() ) ){
			int u = C( s1[i] );
			int v = C( s2[i] );
			int w = u + v + carry;
//			debug( w )
			resp += aux[ w%36 ];
			carry = w/36;
		}
		if( s1.size() < s2.size() ){
			rep( i, s1.size(), s2.size() ){
				int v = C( s2[i] );
				int w = v + carry;
				resp += aux[ w%36 ];
				carry = w/36;
			}
		}
		else{
			rep( i, s2.size(), s1.size() ){
				int v = C( s1[i] );
				int w = v + carry;
				resp += aux[ w%36 ];
				carry = w/36;
			}
		}
		if( carry ) resp += aux[ carry ];
		reverse( all( resp ) );
		cout << resp << endl;	
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


