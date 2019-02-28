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
	char aux[] = {"0123456789"}; 
	vector < string > v;
	v.pb("3");
	v.pb("13");
	v.pb("1113");
	rep( i, 3, 40 ){
		string s = v[i-1];
		char S[123456];
		int k = 0;
		int a = s[0] - '0';
		int cnt = 1;
		rep( j, 1, s.size() ){
			if( s[j] - '0' == a ) cnt++;
			else{
				S[k++] = aux[cnt];
				S[k++] = aux[a];
				a = s[j] - '0';
				cnt = 1;
			}
		}
		S[k++] = aux[cnt];
		S[k++] = aux[a];
		S[k] = '\0';
		v.pb( S );
	}
	int n;
	while( scanf("%d", &n ) != EOF ){
		cout << v[n-1] << endl;
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

