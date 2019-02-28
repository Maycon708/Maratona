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

int C( string s ){
	if( s[0] == 'T' ) return 9;
	if( s[0] == 'J' ) return 10;
	if( s[0] == 'Q' ) return 11;
	if( s[0] == 'K' ) return 12;
	return s[0] - '1';
}

int B( string s ){
	if( s[1] == 'H') return 0;
	if( s[1] == 'C') return 1;
	if( s[1] == 'D') return 2;
	if( s[1] == 'S') return 3;
}

int cmp( string a, string b ){
	if( a[1] != b[1] ){
		return B(a) > B(b);
	}
	return C(a) > C(b);
}

int main(){
	char c[] = {"123456789TJQK"};
	string s1, s2, s3, s4;
	int n = readInt();
	while( n-- ){
		cin >> s1 >> s2 >> s3 >> s4;
		if( cmp( s2, s3 ) && cmp( s3, s4) ){
			int k = ( C( s1 ) + 6 )%13;
			cout << c[k] << s1[1] << endl;
		}
		if( cmp( s2, s4 ) && cmp( s4, s3) ){
			int k = ( C( s1 ) + 5 )%13;
			cout << c[k] << s1[1] << endl;
		}
		if( cmp( s3, s2 ) && cmp( s2, s4) ){
			int k = ( C( s1 ) + 4 )%13;
			cout << c[k] << s1[1] << endl;
		}
		if( cmp( s4, s2 ) && cmp( s2, s3) ){
			int k = ( C( s1 ) + 3 )%13;
			cout << c[k] << s1[1] << endl;
		}
		if( cmp( s3, s4 ) && cmp( s4, s2) ){
			int k = ( C( s1 ) + 2 )%13;
			cout << c[k] << s1[1] << endl;
		}
		if( cmp( s4, s3 ) && cmp( s3, s2) ){
			int k = ( C( s1 ) + 1 )%13;
			cout << c[k] << s1[1] << endl;
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

