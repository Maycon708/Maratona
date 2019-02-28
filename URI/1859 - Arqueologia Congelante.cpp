#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define NN 60
#define MAXW 1

int g[NN][NN], v[NN], w[NN], na[NN], n;
bool a[NN];

int stoer_wagner(){
	for( int i = 0; i < n; i++ ) v[i] = i;
	int best = ( 1 << 20 );
	while( n > 1 ){
		a[v[0]] = true;
		for( int i = 1; i < n; i++ ){
			a[v[i]] = false;
			na[i - 1] = i;
			w[i] = g[v[0]][v[i]];
		}
		int prev = v[0];
		for( int i = 1; i < n; i++ ){
			int zj = -1;
			for( int j = 1; j < n; j++ )
				if( !a[v[j]] && ( zj < 0 || w[j] > w[zj] ) )
					zj = j;
			a[v[zj]] = true;
			if( i == n - 1 ){
				best = min(best,w[zj]);
				for( int j = 0; j < n; j++ )
					g[v[j]][prev] = g[prev][v[j]] += g[v[zj]][v[j]];
				v[zj] = v[--n];
				break;
			}
			prev = v[zj];

			for( int j = 1; j < n; j++ ) if( !a[v[j]] ) w[j] += g[v[zj]][v[j]];
		}
	}
	return best;
}

// MAX_N esta com um zero a menos por motivos de teste :D
  
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

int tam[60];

inline int f( int x ){
	rep( i, 0, n ){
		if( x < tam[i] ) return i;
	}
}

int main(){

	int kk;
	 
	while( scanf("%d%d", &n, &kk ) != EOF ){
		memset( g, 0, sizeof g );		
		int mn; 
		string s;
		T.clear();
		
		char k = '0';
		
		rep( i, 0, n ){
			cin >> s;
			mn = s.size();
			s += s;
			T += s;
			T += ( k++ );
			tam[i] = T.size();
			if( k == 'G' || k == 'C' || k == 'T' || k == 'A' ) k++;
		}
		T += '$';
		N = T.size();
		
		constructSA();
		computeLCP();
		
		mn *= kk;
		mn = ( mn/100 ) + ( mn%100 != 0 );
		
		set<int> st;
		set<int> :: iterator it, it2;
		rep( i, 1, N ){
			if( LCP[i] >= mn ) st.insert( f( SA[i] ) ), st.insert( f( SA[i-1]));
			else{
				for( it = st.begin(); it != st.end(); it++ ){
					for( it2 = it; it2 != st.end(); it2++ ){
						if( it == it2 ) continue;
						int a = *it, b = *it2;
						g[a][b] = g[b][a] = 1;
					}
				}
				st.clear();
			}
		}
		for( it = st.begin(); it != st.end(); it++ ){
			for( it2 = it; it2 != st.end(); it2++ ){
				if( it == it2 ) continue;
				int a = *it, b = *it2;
				g[a][b] = g[b][a] = 1;
			}
		}
		st.clear();
		printf("%d\n", stoer_wagner() );
	}
	
}
