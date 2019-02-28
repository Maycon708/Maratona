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

typedef pair<int,int> ii;

#define gc getchar_unlocked

void scan( int &x ){
    register int c = gc(), aux = 0;
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() ) if( c == '-' ) aux = 1;
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
    if( aux ) x *= -1;
}

// 2D point object
struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}	
	void read(){
		scanf("%lf%lf", &x, &y );
	}
};

// the "hyperplane split", use comparators for all dimensions
bool cmpx(const point& a, const point& b) {return a.x < b.x;}
bool cmpy(const point& a, const point& b) {return a.y < b.y;}

struct kdtree {
	point *tree;
	int n;
	// constructor
	kdtree(point p[], int n): tree(new point[n]), n(n) {
		copy(p, p + n, tree);
		build(0, n, false);
	}
	// destructor
	~kdtree() {delete[] tree;}
	// k-nearest neighbor query, O(k log(k) log(n)) on average
	double query(double x, double y, int k = 1) {
		perform_query(x, y, k, 0, n, false); // recurse
		double ans = 0;
		//vector<point> points;
		while (!pq.empty()) { // collect points
		//	points.push_back(*pq.top().S);
			ans += sqrt(pq.top().F);
			pq.pop();
		}
		//reverse(points.begin(), points.end());
		return ans;
	}
private:
	// build is O(n log n) using divide and conquer
	void build(int L, int R, bool dvx) {
		if (L >= R) return;
		int M = (L + R) / 2;
		// get median in O(n), split x-coordinate if dvx is true
		nth_element(tree+L, tree+M, tree+R, dvx?cmpx:cmpy);
		build(L, M, !dvx); build(M+1, R, !dvx);
	}

	// priority queue for KNN, keep the K nearest
	priority_queue<pair<double, point*> > pq;
	void perform_query(double x, double y, int k, int L, int R, bool dvx) {
		if (L >= R) return;
		int M = (L + R) / 2;
		double dx = x - tree[M].x;
		double dy = y - tree[M].y;
		double delta = dvx ? dx : dy;
		double dist = dx * dx + dy * dy;
		// if point is nearer to the kth farthest, put point in queue
		if (pq.size() < k || dist < pq.top().first) {
			pq.push(make_pair(dist, &tree[M]));
			if (pq.size() > k) pq.pop(); // keep k elements only
		}
		int nearL = L, nearR = M, farL = M + 1, farR = R;
		if (delta > 0) { // right is nearer
			swap(nearL, farL);
			swap(nearR, farR);
		}
                // query the nearer child
		perform_query(x, y, k, nearL, nearR, !dvx);

		if (pq.size() < k || delta * delta < pq.top().first)
                        // query the farther child if there might be candidates
			perform_query(x, y, k, farL, farR, !dvx);
	}
};

int main(){
	int n, c, k, d, x, y;
	while( scanf("%d%d%d%d", &n, &c, &k, &d ) != EOF ){
		point v[n];
		map<ii, bool> MP;
		rep( i, 0, n ){
			scan(x), scan(y);
			v[i] = point(x, y);
			MP[ii(x,y)] = 1;
		}
		kdtree K = kdtree( v, n );
		int cnt = 0;
		rep( i, 0, c ){
			scanf("%d%d", &x, &y );
			if( MP[ii(x,y)] ) continue;
			double aux = K.query( x, y, k );
			if( aux > d ) cnt++;
		}
		printf("%d\n", cnt );
	}
}

