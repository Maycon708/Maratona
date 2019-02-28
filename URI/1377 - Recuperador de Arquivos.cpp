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

ll readInt();
#define MAX 100010
  
// SUFFIX ARRAY O(N log N)
  
#define MAX_N 100010 // second approach: O(n log n)
char T[MAX_N]; // the input string, up to 100K characters
ll n; // the length of input string
int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int c[MAX_N]; // for counting/radix sort
int Phi[MAX_N], PLCP[MAX_N], LCP[MAX_N];
  
void countingSort(int k) { // O(n)
    int i, sum, maxi = max((ll)300, n); // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c); // clear frequency table
    for (i = 0; i < n; i++) // count the frequency of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t; 
    }
    for (i = 0; i < n; i++) // shuffle the suffix array if necessary
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++) // update the suffix array SA
        SA[i] = tempSA[i];
}
  
void constructSA() { // this version can go up to 100000 characters
  
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i]; // initial rankings
    for (i = 0; i < n; i++) SA[i] = i; // initial SA: {0, 1, 2, ..., n-1}
      
    for (k = 1; k < n; k <<= 1) { // repeat sorting process log n times
        countingSort(k); // actually radix sort: sort based on the second item
        countingSort(0); // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++) // compare adjacent suffixes
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
            // ^ if same pair => same rank r; otherwise, increase r
        for (i = 0; i < n; i++) // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break; // nice optimization trick
    } 
}
  
// Permuted Longest-Common-Prefix (PLCP) O(N)
void computeLCP() {
      
    int i, L;
    Phi[SA[0]] = -1; // default value
    for (i = 1; i < n; i++) // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1]; // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) { // compute Permuted LCP in O(n)
        if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
        while (T[i + L] == T[Phi[i] + L]) L++; // L increased max n times
        PLCP[i] = L;
        L = max(L-1, 0); // L decreased max n times
    }
    for (i = 0; i < n; i++){ // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]]; // put the permuted LCP to the correct position
    }
}

void constructH( vector<int>& v ){
	rep( i, 1, n ){
		v.pb( LCP[i] );
		int x = SA[i];
		v.pb( n - x - 1 ); 
	}
}

int main(){
//	freopen("file.in", "r", stdin );
	while( 42 ){
		scanf("%s", T );
		if( T[0] == '*' ) break;
		n = strlen(T);
		T[n++] = '$';
		T[n] = '\0';
		constructSA();
		computeLCP();
		vector<int> H;
		constructH( H );
		int cnt = 0;
		stack<ii> s;
		rep( i, 0, H.size() ){
			int id = i;  
			while( !s.empty() && H[i] < s.top().F ){
				ii a = s.top(); s.pop();
				id = a.S;
				if( i - a.S >= 2 ){
					cnt += a.F;
					if( s.size() ) cnt -= max( H[i], s.top().F );
					else cnt -= H[i];
				}              
			}                  
			if( !H[i] || ( s.size() && s.top().F == H[i] ) ) continue;
			s.push( ii( H[i], id ) );
		}                      
		while( !s.empty() ){   
			ii a = s.top(); s.pop();
			if( H.size() - a.S >= 2 ){
				cnt += a.F;
				if( s.size() ) cnt -= s.top().F;
			}
		}
		printf("%d\n", cnt );
	}
}


