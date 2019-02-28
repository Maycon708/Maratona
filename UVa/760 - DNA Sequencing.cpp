#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define MAX_N 1000100
string T; 
ll N; 
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N]; 
int c[MAX_N]; 
int Phi[MAX_N], PLCP[MAX_N], LCP[MAX_N];
  
void countingSort( int k ){ 
    int i, sum, maxi = max((ll)300, N); 
    memset(c, 0, sizeof c); 
    for( i = 0; i < N; i++ ) 
        c[i + k < N ? RA[i + k] : 0]++;
    for( i = sum = 0; i < maxi; i++ ){
        int t = c[i]; 
		c[i] = sum; sum += t; 
    }
    for( i = 0; i < N; i++ ) 
        tempSA[c[SA[i]+k < N ? RA[SA[i]+k] : 0]++] = SA[i];
    for( i = 0; i < N; i++ ) 
        SA[i] = tempSA[i];
}
  
void constructSA() { 
  
    int i, k, r;
    for (i = 0; i < N; i++) RA[i] = T[i]; 
    for (i = 0; i < N; i++) SA[i] = i; 
      
    for (k = 1; k < N; k <<= 1) { 
        countingSort(k); 
        countingSort(0); 
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < N; i++) 
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < N; i++) 
            RA[i] = tempRA[i];
        if (RA[SA[N-1]] == N-1) break;
    } 
}
  
void computeLCP() {
      
    int i, L;
    Phi[SA[0]] = -1;
    for( i = 1; i < N; i++ )
        Phi[SA[i]] = SA[i-1]; 
    for( i = L = 0; i < N; i++ ){ 
        if( Phi[i] == -1 ){ PLCP[i] = 0; continue; }
        while( T[i + L] == T[Phi[i] + L] ) L++; 
        PLCP[i] = L;
        L = max(L-1, 0); 
    }
    for( i = 0; i < N; i++ ){ 
        LCP[i] = PLCP[SA[i]];
    }
}

int main(){
	string a, b, c;
	bool aux = 0;
	while( getline( cin, a ) ){
		getline( cin, b );
		getline( cin, c );
		
		if( aux ) printf("\n");
		aux = 1;

		T = a + "$" + b + "#";
		N = T.size();
		
		constructSA();
		computeLCP();
		
		int ans = 0;
		
		vector<ii> v;
		
		rep( i, 1, T.size() ){
			if( ( SA[i] < a.size()+1 ) ^ ( SA[i-1] < a.size()+1 ) ){
				if( LCP[i] > ans ){
					ans = LCP[i];
					v.clear();
					v.pb( ii( SA[i], LCP[i] ));
				}
				else if( LCP[i] == ans ) v.pb( ii( SA[i], LCP[i] ));
			} 
	
		}
		
		set<string> st;
		set<string> :: iterator it;
		
		rep( i, 0, v.size() ){
			string aux;
			rep( j, v[i].F, v[i].F + v[i].S ) aux.pb( T[j] );
			if( aux.size() ) st.insert(aux);
		}
		
		if( st.empty() ) puts("No common sequence.");
		for( it = st.begin(); it != st.end(); it++ ){
			printf("%s\n", (*it).c_str() );
		}
	}
}
