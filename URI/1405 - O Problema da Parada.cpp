#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

struct comando{
	string com, a, b;
};

int check, vis[1111];
int nxt[111], N, memo[1111];
comando instrucoes[111];

int C( string a ){
	if(a[0] == 'R') return a[1] -'0';
	stringstream ss;
	int aux;
	ss << a;
	ss >> aux;
	return -1-aux;
}

int solve( int n ){
	if( vis[n] == -1 ){
		check = 1;
		return -1;
	}
	else if( vis[n] == 1 ) return memo[n];
	int x, y;
	vis[n] = -1;
	vector<int> reg (10, 0);
	reg[0] = n;
	
	for( int i = 0; !check && i < N; i++ ){
		comando at = instrucoes[i];
		if( at.com == "MOV" ){
			x = C(at.a);
			y = C(at.b);
			if( y < 0 ) reg[x] = -1-y;
			else reg[x] = reg[y];
		}
		else if( at.com == "ADD" ){
			x = C(at.a);
			y = C(at.b);
			if( y < 0 ) reg[x] += -1-y;
			else reg[x] += reg[y];
		}
		else if( at.com == "SUB" ){
			x = C(at.a);
			y = C(at.b);
			if( y < 0 ) reg[x] -= -1-y;
			else reg[x] -= reg[y];
		}
		else if( at.com == "MUL" ){
			x = C(at.a);
			y = C(at.b);
			if( y < 0 ) reg[x] *= -1-y;
			else reg[x] *= reg[y];
		}
		else if( at.com == "DIV" ){
			x = C(at.a);
			y = C(at.b);
			if( y < 0 ) y = -1-y;
			else y = reg[y];
			if( y ) reg[x] /= y;
			else reg[x] = 0;
		}
		else if( at.com == "MOD" ){
			x = C(at.a);
			y = C(at.b);
			if( y < 0 ) reg[x] %= -1-y;
			else reg[x] %= reg[y];
		}
		else if( at.com == "IFEQ" ){			
			x = C(at.a);
			y = C(at.b);
			if( x < 0 ) x = -1-x;
			else x = reg[x];
			if( y < 0 ) y = -1-y;
			else y = reg[y];
			if( x != y ) i = nxt[i];
		}
		else if( at.com == "IFNEQ" ){			
			x = C(at.a);
			y = C(at.b);
			if( x < 0 ) x = -1-x;
			else x = reg[x];
			if( y < 0 ) y = -1-y;
			else y = reg[y];
			if( x == y ) i = nxt[i];
		}
		else if( at.com == "IFG" ){			
			x = C(at.a);
			y = C(at.b);
			if( x < 0 ) x = -1-x;
			else x = reg[x];
			if( y < 0 ) y = -1-y;
			else y = reg[y];
			if( x <= y ) i = nxt[i];
		}
		else if( at.com == "IFL" ){			
			x = C(at.a);
			y = C(at.b);
			if( x < 0 ) x = -1-x;
			else x = reg[x];
			if( y < 0 ) y = -1-y;
			else y = reg[y];
			if( x >= y ) i = nxt[i];
		}
		else if( at.com == "IFGE" ){			
			x = C(at.a);
			y = C(at.b);
			if( x < 0 ) x = -1-x;
			else x = reg[x];
			if( y < 0 ) y = -1-y;
			else y = reg[y];
			if( x < y ) i = nxt[i];
		}
		else if( at.com == "IFLE" ){			
			x = C(at.a);
			y = C(at.b);
			if( x < 0 ) x = -1-x;
			else x = reg[x];
			if( y < 0 ) y = -1-y;
			else y = reg[y];
			if( x > y ) i = nxt[i];
		}
		else if( at.com == "CALL" ){			
			x = C(at.a);
			if( x < 0 ) x = -1-x;
			else x = reg[x];
			reg[9] = solve(x);
		}
		else if( at.com == "RET" ){
			x = C(at.a);
			if( x < 0 ) x = -1-x;
			else x = reg[x];
			vis[n] = 1;
			return memo[n] = x;
		}
		rep( i, 0, 10 ) reg[i] = ( (reg[i]%1000) + 1000 )%1000;
	}
}

void Debug( comando a, int id ){
	cout << id << " " << a.com << " - " << a.a << " ___  " << a.b << endl;
}

int main(){
	
	int tmp;
	char op1[10], op2[10];
	while( scanf("%d%d", &N, &tmp ) != EOF && N  ){
		rep( i, 0, 1000 ) vis[i] = 0;
		rep( i, 0, N ){
			cin >> instrucoes[i].com;
			if( instrucoes[i].com != "ENDIF"){
				if ((instrucoes[i].com != "CALL") && (instrucoes[i].com != "RET")){
					scanf("%[^,],%s", op1, op2);
					stringstream ss;
					ss << op1;
					ss >> instrucoes[i].a;
					ss.clear();
					ss << op2;
					ss >> instrucoes[i].b;
				}
				else{
					stringstream ss;
					scanf("%s", op1);
					ss << op1;
					ss >> instrucoes[i].a;
				}
			}
		}
		stack<int> s;
		for( int i = N-1; i >= 0; i-- ){
			if( instrucoes[i].com == "ENDIF" ) s.push(i);
			else if( instrucoes[i].com[0] == 'I' ) nxt[i] = s.top(), s.pop();
		}
		check = 0;
		int ans = solve(tmp);
		if( check ) puts("*");
		else printf("%d\n", ans );
	}
}

