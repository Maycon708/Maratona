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

using namespace std;

typedef long long ll;
typedef pair < int, string >  ii;

int main(){
	
	deque <ii> d;
	int n, number;
	char nome[50];
	
	while(scanf("%d", &n), n){
		
		rep(i,0,n){
			scanf(" %s %d", nome, &number);
			d.push_back(ii(number, nome));
		}
		
		int u = d.front().F;
		if(u&1)d.push_back(d.front());
		if(u&1)d.pop_front();
		
		while(d.size() != 1){
			
			if(u&1){
				rep(i,0,u-1){
					d.push_back(d.front());
					d.pop_front();
				}
				u = d.front().F;
//				cout << d.front().S << endl;
				d.pop_front();
			}
			else{
				rep(i,0,u-1){
					d.push_front(d.back());
					d.pop_back();
				}
				u = d.back().F;
//				cout << d.back().S << endl;
				d.pop_back();
			}
		}
		
		
		
		cout << "Vencedor(a): " << d.front().S << endl;
		d.pop_front();
		
	}

	return 0;
}

