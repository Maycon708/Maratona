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
	
	int p, g1, g2, ans;
	char nome[1000], t1[1000], t2[1000];
	string s;
	map < string, int > mp;
	map < string, int > :: iterator it;
	
	while( 1 ){
		int n = readInt();
		if( !n ) break;
		mp.clear();
		rep( i, 0, n ){
			scanf("%s %d", nome, &p );
			mp[nome] = p;
		}
		rep( i, 0, n/2 ){
			
			scanf("%s %d - %d %s", t1, &g1, &g2, t2 );
			mp[t1] += ( g1 * 3 ), mp[t2] += ( g2 * 3 );
			
			if( g1 == g2 ) mp[t1]++, mp[t2]++;
			else if( g1 > g2 ) mp[t1] += 5;
			else mp[t2] += 5;
		}
		ans = 0;
		for( it = mp.begin(); it != mp.end(); it++ ){
			if( ans < it -> S ){
				ans = it -> S;
				s = it -> F;
			}
		}
		if( s == "Sport" ) printf("O Sport foi o campeao com %d pontos :D\n", ans );
		else cout << "O Sport nao foi o campeao. O time campeao foi o " << s << " com "<< ans << " pontos :(\n";
		printf("\n");
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


