#include <bits/stdc++.h>
     
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 110015
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
     
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
     
using namespace std;
     
typedef pair <int, int> ii;
typedef long long int ll;

int P( char c, char t){
  int pc,pt;
  if( c == '^' ) pc = 4;
  else if( c == '*' || c == '/' ) pc = 2;
  else if(c == '+' || c == '-') pc = 1;
  else if(c == '(') pc = 4;
  if(t == '^') pt = 3;
  else if(t == '*' || t == '/') pt = 2;
  else if(t == '+' || t == '-') pt = 1;
  else if(t == '(') pt = 0;
 
  return (pc > pt);
}

int cnt, R[1000], L[1000], t;
char tree[1000];

void build( int no, char *s ){
	if( t < 0 ) return;
	tree[no] = s[t];
	if( isalnum(s[t]) ) return;
	R[no] = cnt++;
	t--;
	build( R[no], s );
	L[no] = cnt++;
	t--;
	build( L[no], s );
}

string nivel[1000];
int nmx;

void bfs(){
	queue<ii> q;
	q.push( ii(0, 0) );
	while( !q.empty() ){
		int u = q.front().F;
		int d = q.front().S;
		q.pop();
		nivel[d].pb(tree[u]);
		nmx = max( nmx, d+1 );
		if( L[u] != -1 ) q.push( ii( L[u], d+1 ) );
		if( R[u] != -1 ) q.push( ii( R[u], d+1 ) );
	}
}

int main(){
    char c, s[1111];
    int space = 0;
    while( gets(s) ){
    	if( space ) printf("\n");
    	else space = 1;
    	nmx = 0;
    	rep( i, 0, 1000 ) nivel[i].clear(), R[i] = L[i] = -1;
    	cnt = 1;
    	stack <char> p;
    	char infixa[1000];
    	t = 0;
        int tam = strlen( s );
        rep( i, 0, tam+1 ){
        	if( s[i] == ' ' ) continue;
            if( ( s[i] >='A' && s[i] <= 'Z' ) || ( s[i] >= 'a' && s[i] <= 'z' ) || ( s[i] >= '0' && s[i] <= '9' ) )	infixa[t++] = s[i];
            else{
            	if( s[i] == '(' ){
            		p.push( s[i] );
            	}
            	else{
		        	if( s[i] == ')' || s[i] == '\0' ){
		        		do{
		        			if( p.empty() ) break;
		        			c = p.top();
		        			p.pop();
			        		if( c != '(' ) infixa[t++] = c;
			        	}while( c != '(' );	
		        	}
		        	else{
		        		if( p.empty() ){
		        			p.push( s[i] );
		        		}
		        		else{
				    		while( 1 ){
				    			if( p.empty() ){
				    				p.push( s[i] );	
				    				break;
				    			}
				    			c = p.top();
				    			p.pop();
				    			if( P( s[i], c ) ){
				    				p.push( c );
				    				p.push( s[i] );
				    				break;
				    			}
				    			else{
				    				infixa[t++] = c;
				    			}
				    		}
		        		}
		        	}
		        }
            }
        }
        while( !p.empty() ){
        	c = p.top();
			p.pop();
    		if( c != '(' ) infixa[t++] = c;
        }
        infixa[t] = '\0';
        t--;
        build( 0, infixa );
        bfs();
        rep( i, 0, nmx ){
        	printf("Nivel %d: %s\n", i, nivel[i].c_str() );
		}
		
    }
}
