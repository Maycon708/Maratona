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

typedef pair <int, int> ii;
typedef long long int ll;

const int mod = 1000000007;

const int MAX_N = 210;

ll C[MAX_N][MAX_N];
 
void calc_pascal(){
    memset(C, 0, sizeof(C));
    for(int i = 0; i < MAX_N; i++){
        C[i][0] = C[i][i] = 1;   
        for(int j = 1; j < i; ++j){
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
		}
    }
}

ll pd[110][110], n, k;
 
ll solve(int tam, int g){
	
	if(tam <= 1) return (g<=k);
	
	if(pd[tam][g] != -1) return pd[tam][g];
	
	ll resp = 0;
	
	rep(i, 1, tam){
		
		ll aux = (C[tam-2][i-1] * solve(tam - i, g+1))%mod;
		aux = (aux * i) % mod;
		aux = (aux* solve(i, 1))%mod;
		resp += aux;
		resp %= mod;
		
	}
	
	return pd[tam][g] = resp;
	
}

int main(){
	
	calc_pascal();
	
	while(scanf("%lld%lld", &n, &k) != EOF){
		
		memset(pd, -1, sizeof(pd));
		
		printf("%lld\n", solve(n, 0));
		
	}

	return 0;
}


