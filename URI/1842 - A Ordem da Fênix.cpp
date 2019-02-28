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

const int MAX = 105023;

char T[MAX];
int n;
int RA[MAX], tempRA[MAX]; 				// rank array and temporary rank array
int SA[MAX], tempSA[MAX];				// suffix array and temporary suffix array
int c[MAX]; 							// for counting/radix sort
int Phi[MAX], PLCP[MAX], LCP[MAX];

void countingSort( int k ){ 			// O(n)
	int i, sum, maxi = max(300, n); 	// up to 255 ASCII chars or length of n
	memset(c, 0, sizeof c); 			// clear frequency table
	for (i = 0; i < n; i++) 			// count the frequency of each integer rank
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t; 
	}
	for (i = 0; i < n; i++) 			// shuffle the suffix array if necessary
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for (i = 0; i < n; i++) 			// update the suffix array SA
		SA[i] = tempSA[i];
}

void constructSA() { 						// this version can go up to 100000 characters

	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i]; 	// initial rankings
	for (i = 0; i < n; i++) SA[i] = i; 		// initial SA: {0, 1, 2, ..., n-1}
	
	for (k = 1; k < n; k <<= 1) { 			// repeat sorting process log n times
		countingSort(k); 					// actually radix sort: sort based on the second item
		countingSort(0); 					// then (stable) sort based on the first item
		tempRA[SA[0]] = r = 0; 				// re-ranking; start from rank r = 0
		for (i = 1; i < n; i++){			// compare adjacent suffixes
			if( RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k] )
				tempRA[SA[i]] = r;   		// ^ if same pair => same rank r
			else tempRA[SA[i]] = ++r;		// otherwise, increase r
		}
		for (i = 0; i < n; i++) 			// update the rank array RA
			RA[i] = tempRA[i];
		if (RA[SA[n-1]] == n-1) break;		// nice optimization trick
	} 
}

void computeLCP() {
	
	int i, L;
	Phi[SA[0]] = -1; 							// default value
	for( i = 1; i < n; i++ ) 					// compute Phi in O(n)
		Phi[SA[i]] = SA[i-1]; 					// remember which suffix is behind this suffix
	for( i = L = 0; i < n; i++ ){ 				// compute Permuted LCP in O(n)
		if( Phi[i] == -1 ){ 					// special case
			PLCP[i] = 0; 
			continue; 
		} 
		while( T[i + L] == T[Phi[i] + L] ) L++;	// L increased max n times
		PLCP[i] = L;
		L = max( L-1, 0 );						// L decreased max n times
	}
	for( i = 0; i < n; i++ ){ 					// compute LCP in O(n)
		LCP[i] = PLCP[SA[i]]; 					// put the permuted LCP to the correct position
	}
}

int main(){

	while( cin >> T ){
		
		n = strlen( T );
		T[n++] = '$';
		T[n] = '\0';
		constructSA();
		computeLCP();

		int ans = 0;
		rep( i, 0, n )
			ans = max( ans, LCP[i] );
		
		if( ans < 3 ){
			printf("*\n");
			continue;
		}
		int pos;
		rep( i, 0, n ){
			if( LCP[i] == ans ) pos = i;
		}
		int u = SA[pos];
		rep( i, 0, ans ){
			printf("%c", T[u++] );
		}
		printf("\n");
	}

	return 0;
}

