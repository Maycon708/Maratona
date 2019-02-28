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

bool valido ( int i ){
	
	stringstream ss;
	string s;
	
	bool v[10];
	memset(v, false, sizeof(v));
	
	ss << i;
	ss >> s;
	
	int t = s.size();
	
	rep(i,0,t){
		int u = s[i] -'0';
 		if(v[u]) return false;
 		v[u] = true;
	}
	return true;
}

int main(){
//	freopen("code.in", "r", stdin);
// 	freopen("out_maycon.txt", "w", stdout);
	
	int dd[5500], a, b;
	
	dd[0] = 1;
	
	rep(i, 1, 5010){
		if(valido(i)) dd[i] = dd[i-1] + 1;
		else dd[i] = dd[i-1];
	}
	
	while(scanf("%d%d", &a, &b) != EOF){
		
		printf("%d\n", dd[b]-dd[a-1]);
		
	}
	
	return 0;
}


