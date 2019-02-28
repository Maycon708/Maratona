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

bool lex, sint;

int P( char c, char t){
	int pc,pt;
	if( c == '^' ) pc = 7;
	else if( c == '*' || c == '/' ) pc = 5;
	else if( c == '+' || c == '-') pc = 4;
	else if( c == '<' || c == '>' || c == '=' || c == '#' ) pc = 3;
	else if( c == '.' ) pc = 2;
	else if( c == '|' ) pc = 1;
	else if( c == '(') pc = 7;
	else lex = 0;
	if( t == '^' ) pt = 6;
	else if( t == '*' || t == '/' ) pt = 5;
	else if( t == '+' || t == '-' ) pt = 4;
	else if( t == '(') pt = 0;
	else if( t == '<' || t == '>' || t == '=' || t == '#' ) pt = 3;
	else if( t == '.' ) pt = 2;
	else if( t == '|' ) pt = 1;
	else lex = 0;
	return (pc > pt);
}

inline bool S( char s ){
	return !( s >= 'a' && s <= 'z') && !( s >= 'A' && s <= 'Z') && !( s <= '9' && s >= '0') && s != ')' && s != '(';
}

int main(){
    int n;
    char c, s[1111];
    while( scanf("%s", s ) != EOF ){
    	string resp; lex = 1, sint = 1; 
        
	    stack < char > p;
        int tam = strlen( s );
        
        int cnt = 0;
		rep( i, 0, tam ){
			if( s[i] == '(' ) cnt++;
			if( s[i] == ')' ){
				if( cnt ) cnt--;
				else sint = 0;
			}
			if( i && S( s[i] ) && S( s[i-1] ) ) sint = 0;
		}
		if( cnt ) sint = 0;
			
        rep( i, 0, tam+1 ){
            if( ( s[i] >='A' && s[i] <= 'Z' ) || ( s[i] >= 'a' && s[i] <= 'z' ) || ( s[i] >= '0' && s[i] <= '9' ) )	resp += s[i];
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
			        		if( c != '(' ) resp += c;
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
				    				resp += c;
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
    		if( c != '(' ) resp+= c;
        }
        if( !lex ) printf("Lexical Error!\n");
        else if( !sint || resp.size()%2 == 0 ) printf("Syntax Error!\n");
        else printf("%s\n", resp.c_str() );
    }
}
