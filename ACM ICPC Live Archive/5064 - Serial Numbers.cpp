#include<bits/stdc++.h>

#define rep( i, a, b ) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << "\n";
#define debug2(a, b) cout << #a << " = " << a << " ---- " << #b << " = " << b <<  "\n";
#define F first
#define S second
#define pb push_back
#define mk make_pair
#define INF 0x3f3f3f3f

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

const int cc = 10;		
const int MAX = 110; 						

int cnt;												
int sig[MAX][cc]; 									
bool term[MAX]; 									
int T[MAX]; 									

inline int C( char c ){
	return c - '0'; 									
}

void add( string s ){
	int x = 0; 											
	rep( i, 0, s.size() ){		
		int c = C( s[i] );								
		if( !sig[x][c] ){ 								
			term[cnt] = 0; 								
			sig[x][c] = cnt++; 							
		}
		x = sig[x][c]; 									
	}
	term[x] = 1; 										
}

void aho(){
	queue < int > q;
	rep( i, 0, cc ){									
		int x = sig[0][i];				
		if( !x ) continue;								
		q.push( x ); 									
		T[x] = 0;										
	}
	while( !q.empty() ){
		int u = q.front();							
		q.pop();
		rep( i, 0, cc ){								
			int x = sig[u][i]; 							
			if( !x ) continue;							
			int v = T[u];							
			while( v && !sig[v][i] ) v = T[v];			
			v = sig[v][i];								
			T[x] = v;								
			term[x] |= term[v];							
			q.push( x );								
		}
	}
}

ll pd[110][33][2][2];
string s;

ll solve( int x, int pos, int pre, int z ){
	if( pos == s.size() ) return 1;
	if( pd[x][pos][pre][z] != -1 ) return pd[x][pos][pre][z];
	ll ans = 0;
	if( pre ){
		int u = C( s[pos] );
		rep( i, 0, u ){	
			int v = x;
			while( v && !sig[v][i] ) v = T[v];
			v = sig[v][i];
			if( !term[v] || !(z || i != 0) ) 
				ans += solve( v, pos+1, 0, z || i != 0 );
		}
		int v = x;
		while( v && !sig[v][u] ) v = T[v];
		v = sig[v][u];
		
		if( !term[v] ) ans += solve( v, pos+1, 1, 1 );
		
	}
	else{
		rep( i, 0, 10 ){	
			int v = x * z;
			while( v && !sig[v][i] ) v = T[v];
			v = sig[v][i];
			if( !term[v] || !(z || i != 0)) 
				ans += solve( v, pos+1, 0, z || i != 0 );
		}
	}
	return pd[x][pos][pre][z] = ans;
}

string SS ( ll a ){
	string ss = "", aux = "0123456789";
	while( a ){
		ss += aux[a%10];
		a /= 10;
	}
	reverse( ss.begin(), ss.end() );
	return ss;
}

ll bb( ll u ){
	ll ini = 1, fim = ( ll(1) << 32 );
	ll mid;
	while( ini < fim ){
		mid = ( ini + fim ) >> 1;
		s = SS( mid );
		
		rep( i, 0, cnt )
			rep( j, 0, s.size() )
				pd[i][j][0][0] = pd[i][j][0][1] = pd[i][j][1][0] = pd[i][j][1][1] = -1;
			
		ll aux = solve( 0, 0, 1, 0 ) -1; 
		if( aux >= u ) fim = mid;
		else ini = mid+1;
	}
	return ini;
}

inline bool cmp1( ii a, ii b ){
	return a.F < b.F;
}

inline bool cmp2( ii a, ii b ){
	return a.S < b.S;
}

int main(){

	ll t, n;
	scanf("%lld", &t );
	while( t-- ){
		cnt = 1;
		memset( sig, 0, sizeof sig );
		scanf("%lld", &n );
		while( n-- ){
			string aux;
			cin >> aux;
			add( aux );	
		}
		aho();
		ii v[110];
		scanf("%lld", &n );
		rep( i, 0, n ){
			v[i].S = i;
			scanf("%lld", &v[i].F );
		}
		sort( v, v+n, cmp1 );
		rep( i, 0, n ){
			v[i].F = bb( v[i].F );
		}
		sort( v, v+n, cmp2 );
		rep( i, 0, n ){
			if( i ) printf(" ");
			printf("%lld", v[i].F );
		}
		printf("\n");
	}	

}
