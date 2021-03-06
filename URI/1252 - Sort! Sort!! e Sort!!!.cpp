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

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

int n, mod, v[11234];

bool cmp(int a, int b){
	
	if(a%mod<b%mod)return true;
	if(a%mod>b%mod)return false;
	if(a&1 && !(b&1)) return true;
	if(!(a&1) && b&1) return false;
	if(a&1 && a>b) return true;
	if(a&1 && a<b) return false;
	if(a<b) return true;
	return false;
	
}

int main(){
//	freopen("code.in", "r", stdin);
// 	freopen("out_maycon.txt", "w", stdout);

	while(scanf("%d%d", &n, &mod) && n+mod){
		
		rep(i,0,n) scanf("%d", &v[i]);
		
		sort(v, v+n, cmp);
		
		printf("%d %d\n", n, mod);
		rep(i,0,n) printf("%d\n", v[i]);
		
	}
	
	printf("0 0\n");
	
	return 0;
}


