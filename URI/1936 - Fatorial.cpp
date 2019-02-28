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

int main(){
//	freopen("code.in", "r", stdin);
// 	freopen("out_maycon.txt", "w", stdout);

	int fat[10], n;
	fat[0] = 1;
	
	rep(i,1,10) fat[i] = fat[i-1] * i;
	
	while(scanf("%d", &n) != EOF){
		
		int k = 9, cont = 0;
		
		while(n){
			cont += n/fat[k];
			n%= fat[k];
			k--;
		}
		
		printf("%d\n", cont);
	}
	
	return 0;
}


