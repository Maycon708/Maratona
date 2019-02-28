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

ll n, v[100], pd[100][2][2];
string s1;

ll solve( int pos, int prefix, int num ){
	if( pos == s1.size() ) return 1;
	if( pd[pos][prefix][num] != -1 ) return pd[pos][prefix][num];
	ll ans = 0;
	if( prefix ){
		int u = s1[pos] - '0';
		rep( i, 0, u ){
			if( num || i )
				if( v[i] ) ans += solve( pos+1, 0, 1 );
		}
		if( v[u] ) ans += solve( pos+1, 1, 1 );
	}
	else{
		rep( i, 0, n ){
			if( num || i )
				if( v[i] ) ans += solve( pos+1, 0, 1 );
		}
	}
	if( !num ) ans += solve( pos+1, 0, 0 );
	return pd[pos][prefix][num] = ans;
}

string convert( ll d ){
	string s = "";
	char aux[] = {"0123456789"};
	while( d ){
		int u = d%n;
		s += aux[u];
		d /= n;	
	}
	reverse( all( s ) );
	return s;
}

int main(){
	char s[100];
	while( 1 ){
		ll d = readInt();
		ll h = readInt();
		n = readInt();
		scanf("%s", s );
		if( d == -1 ) break;
		rep( i, 0, n ) v[i] = ( s[i] == 'S' );
		s1 = convert( d-1 );
		string s2 = convert( h );
		memset( pd, -1, sizeof pd );
		ll ans = solve( 0, 1, 0 );
		memset( pd, -1, sizeof pd );
		s1 = s2;
		ll ans2 = solve( 0, 1, 0 );
		printf("%lld\n", ans2 - ans );
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


