#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for( int i = (int) a; i < (int) b; ++i )

struct team{
	int p, nt, score, total, id ;
	team(){};
	team(int a, int b, int c){ p = a; nt = b; score = c; }
	void init( int i ){ p = nt = score = total = 0, id = i; }
	bool operator < (team a) const{
		if( p != a.p ) return p > a.p;
		if( total != a.total ) return total < a.total;
		if( score != a.score ) return score < a.score;
		return id < a.id;
	}
	bool operator == ( team a ) const{
		return a.id == id; 
	}
};


bool check( vector<team> &a, vector<team> &b ){
	rep( i, 1, a.size() ){
		if( a[i].total == a[i-1].total && b[i].total != b[i-1].total  ) return 0;
		if( b[i].total == b[i-1].total && a[i].total != a[i-1].total  ) return 0;
	}
	return a == b;
}

int main(){
	int t, p, a, b;
	char s[10], lixo;
	while( scanf("%d%d", &t, &p ) != EOF && t ){
		vector<team> v(t), w;
		rep( i, 0, t ){
			v[i].init(i);
			rep( j, 0, p ){
				scanf("%s", s );
				int t = strlen(s), aux = 1;
				rep( k, 0, t ) if(s[k] == '-') aux = 0;
				if( aux ){
					stringstream ss;
					ss << s;
					ss >> a >> lixo >> b;
					v[i].p++;
					v[i].nt += a-1;
					v[i].score += b;
					
				}
			}
		}
		rep( i, 0, t ) v[i].total = v[i].score + v[i].nt * 20;
		sort(v.begin(), v.end());
		w = v;
		int L, R = 3000;
		for( L = 1; L <= 20; ++L ){
			rep( i, 0, t ) v[i].total = v[i].score + v[i].nt * L;
			sort(v.begin(), v.end() );
			if( check(v, w) ) break;
		}
	   	bool aux = 0;
		for( ; R > L; R-- ){
			rep( i, 0, t ) v[i].total = v[i].score + v[i].nt * R;
			sort(v.begin(), v.end() );
			if( check(v, w) ) break;	
			aux = 1;
		}
		if( !aux ) printf("%d *\n", L );
		else printf("%d %d\n", L, R );
	}
	return 0;
}
