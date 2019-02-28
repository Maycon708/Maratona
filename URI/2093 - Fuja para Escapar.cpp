#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

int main(){

	char s[100100];
	while( scanf("%s", s ) != EOF ){
		int tam = strlen( s );
		int resp = 1;
		while( 1 ){		
			set < ll > st;
			rep( i, 0, tam - resp +1 ){
				ll aux = 0;
				rep( j, i, i + resp ){
					aux <<= 1;
					aux += ( s[j] - '0' );
				}
				st.insert( aux );
			}
			if( st.size() != ( 1 << resp ) ) break;
			resp++;
		}
		printf("%d\n", resp );
	}

	return 0;
}

