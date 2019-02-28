/**************************************************************************************

	Palindrome tree. Useful structure to deal with palindromes in strings. O(N)

	This code counts number of palindrome substrings of the string.
	Based on problem 1750 from informatics.mccme.ru:
	http://informatics.mccme.ru/moodle/mod/statements/view.php?chapterid=1750

**************************************************************************************/

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

const int MAXN = 50011;

struct node {
	int next[36];
	int len;
	int sufflink;
	int num;
	int mask;
	void clear(){
		rep( i, 0, 36 ) next[i] = 0;
		len = sufflink = num = mask = 0;
	}
};

int len;
char s[MAXN];
node tree[MAXN*10]; 
int num; 			// node 1 - root with len -1, node 2 - root with len 0
int suff; 			// max suffix palindrome
long long ans;

inline int C( char a ){
	if( a >= 'A' && a <= 'Z') return a - 'A' + 26;
	return a - 'a';
}

bool addLetter( int pos, int id ){
	int cur = suff, curlen = 0;
	int let = C( s[pos] );

	while( true ){
		curlen = tree[cur].len;
		if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])    	
			break;	
		cur = tree[cur].sufflink;
	}		
	if( tree[cur].next[let] ){	
		suff = tree[cur].next[let];
		tree[suff].mask |= ( 1 << id );
		return false;
	}

	num++;
	suff = num;
	tree[num].mask = ( 1 << id );
	tree[num].len = tree[cur].len + 2;
	tree[cur].next[let] = num;

	if( tree[num].len == 1 ){
		tree[num].sufflink = 2;
		tree[num].num = 1;
		return true;
	}

	while( true ){
		cur = tree[cur].sufflink;
		curlen = tree[cur].len;
		if( pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos] ){
			tree[num].sufflink = tree[cur].next[let];
			break;
		}    	
	}           

	tree[num].num = 1 + tree[tree[num].sufflink].num;

	return true;
}

void initTree(){
	num = 2; suff = 2;
	tree[1].len = -1; tree[1].sufflink = 1;
	tree[2].len = 0; tree[2].sufflink = 1;
}

int main() {
	
	int n;
	while( scanf("%d", &n ) != EOF ){
		initTree();
		int aux = ( 1 << n ) -1;
		char k = 'A';
		rep( i, 0, n ){
			scanf("%s", s );
			int t = strlen(s);
			s[t++] = k++;
			s[t] = '\0';
			rep( j, 0, t ){
				addLetter( j, i ); 
			}
		}
		int ans = 0;
		rep( i, 0, num+1 ){
			if( tree[i].mask == aux )
				ans = max( ans, tree[i].len );
			tree[i].clear();
		}
		printf("%d\n", ans );
	}
	return 0;
}   
