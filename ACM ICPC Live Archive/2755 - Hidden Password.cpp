#include <bits/stdc++.h>
      
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 2110
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

#define MAX 1000010

string T;
ll n;
int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int c[MAX];
int Phi[MAX], PLCP[MAX], LCP[MAX];
int v[MAX], owner[MAX];
  
void countingSort(int k) {
    int i, sum, maxi = max((ll)300, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t; 
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}
  
void constructSA() {
  
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
      
    for (k = 1; k < n; k <<= 1) { 
        countingSort(k);
        countingSort(0); 
        tempRA[SA[0]] = r = 0; 
        for (i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++) 
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break; 
    } 
}
  
void computeLCP() {
      
    int i, L;
    Phi[SA[0]] = -1; 
    for (i = 1; i < n; i++) 
        Phi[SA[i]] = SA[i-1]; 
    for (i = L = 0; i < n; i++) {
        if (Phi[i] == -1) { PLCP[i] = 0; continue; } 
        while (T[i + L] == T[Phi[i] + L]) L++; 
        PLCP[i] = L;
        L = max(L-1, 0); 
    }
    for (i = 0; i < n; i++){ 
        LCP[i] = PLCP[SA[i]]; 
    }
}
int main(){
	
	string A, B;
	int m, u;
	cin >> m;
	while( m-- ){
		cin >> u >> T;
		T += T;
		T += '{';
		n = T.size();
		
		constructSA(); 
		computeLCP();
		
		int resp;
		rep( i, 0, n ){
			if( SA[i] < u ){
				resp = SA[i];
				break;
			}
		}
		printf("%d\n", resp );
	}
}
