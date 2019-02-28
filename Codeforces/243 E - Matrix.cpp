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

const int N = 2112;

namespace PQ{
	const int MAXN = N;
	const int P = -1, Q = -2, White = 0, Gray = 1, Black = 2;
	
	struct node{
		int v;
		node *son,*bro;
		int c;
		node(){}
		node(int v,node *son,node *bro,int c):
			v(v),son(son),bro(bro),c(c){}
	};
	node pool[MAXN*4];int poolN;
	node *unused;
	void clear(){
		poolN=0;unused=0;
	}
	node *NEW(){
		if(unused){
			node *p=unused;
			unused=unused->bro;
			return p;
		}else
			return pool+(poolN++);
	}
	void DELETE(node *p){
		p->bro=unused;
		unused=p;
	}
	node *newSubtree(node *p,int pv){
		return p->bro ? new(NEW())node(pv,p,0,0) : p;
	}
	
	node **tail(node *p){			// p != NULL
		node **lst=0;
		for(;p;p=p->bro)lst=&p->bro;
		return lst;
	}
	void cat(node *p,node *q){*tail(p)=q;}
	
	node *reverseBro(node *p){
		node *prev=0,*succ;
		for(node *i=p;i;i=succ){
			succ=i->bro;
			i->bro=prev;
			prev=i;
		}
		return prev;
	}
	void reverse(node *p){p->son=reverseBro(p->son);}
	
	bool checkRight(node *p){
		int st=0;
		int cnt[3]={0,0,0};
		for(node *s=p->son;s;s=s->bro){
			int c=s->c;
			if(c<st)return 0;
			++cnt[c];
			st=c;
		}
		return cnt[Gray]<=1;
	}
	void alignRight(node *p){
		if(p->v==P){
			node *h=0;
			node **slst=&p->son;
			node **hlst=&h;
			// join the gray node to h, the others to s, attention "*slast=NULL"
			for(node *s=p->son;s;s=s->bro){
				if(s->c==Gray)
					*hlst=s,hlst=&s->bro;
				else
					*slst=s,slst=&s->bro;
			}
			*slst=0;
			
			slst=&p->son;
			for(node *s=p->son;s;s=s->bro){
				if(s->c==Black)
					*hlst=s,hlst=&s->bro;
				else
					*slst=s,slst=&s->bro;
			}
			// join the black node after h, the others to s
			*slst=h;
			// join the h after s
			*hlst=0;
		}else{
			if(!checkRight(p))reverse(p);
		}
	}
	node *splitWhite(node *p){			// p != NULL
		for(node *s=p->son,**prev=&p->son;s;prev=&s->bro,s=s->bro)
			if(s->c!=White){*prev=0;return s;}
		return 0;
	}
	int cntNGray(node *p){
		int cnt=0;
		for(;p&&p->c==Gray;p=p->bro)++cnt;
		return cnt;
	}
	struct PQTree{
		int n;
		node *rt;
		void init(int n){
			this->n=n;
			rt=new(NEW())node(P,0,0,0);
			node **lst=&rt->son;
			for(int v=0;v<n;++v){
				*lst=new(NEW())node(v,0,0,0);
				lst=&(*lst)->bro;
			}
		}
		void permutationDfs( node *p, int *&out ){
			for(node *s = p->son; s; s = s->bro ){
				if( s->v >= 0 ) *out++ = s->v;
				else permutationDfs(s,out);
			}
		}
		void permutation(int *out){permutationDfs(rt,out);}
		
		char* insertS;
		void insertPreDfs(node *p){
			if(p->v>=0)p->c=(insertS[p->v]=='1' ? Black : White);
			else{
				int s0=0,s1=1;
				for(node *s=p->son;s;s=s->bro){
					insertPreDfs(s);
					s0|=s->c!=White;
					s1&=s->c==Black;
				}
				p->c=(s0 ? (s1 ? Black : Gray) : White);
			}
		}
		bool insertDfs(node *p){
			if(p->v>=0||p->c==White||p->c==Black)return 1;
			if(p->v==P){
				alignRight(p);
				node *h=splitWhite(p);
				// h -> the gray and black nodes, p -> the white nodes
				if(!p->son){ // have not white nodes
					p->son=h;
					int nGray=cntNGray(h); // the number of gray nodes
					if(nGray==0)return 1;  // all black nodes
					else if(nGray==1){
						p->v=Q;
						node *np=h;
						node *nq=newSubtree(h->bro,P); // a new P node contain all black nodes
						nq->c=Black;
//************  if P only have 1 gray node ... it seems to be RE ?!
//				But it acutally never happens
						p->son=np,np->bro=nq,nq->bro=0;
					}else if(nGray==2){
						p->v=Q;
						node *npl=h,*npr=h->bro;
						if(h->bro->bro){
							node *nq=newSubtree(h->bro->bro,P);
							nq->c=Black;
							p->son=npl,npl->bro=nq,nq->bro=npr,npr->bro=0;
						}else{
							p->son=npl,npl->bro=npr,npr->bro=0;
						}
					}
				}else{
					node *np=newSubtree(h,P);
					np->c=Gray;
//					PQ::print(h,0);
					np->bro=p->son;p->son=np;
					return insertDfs(np);
				}
			}
			node *fs=0,*ls=0;
			// fs -> the first gray/black node, ls -> the last gray/black node
			for(node *s=p->son;s;s=s->bro)
				if(s->c!=White){
					if(!fs)fs=s;
					ls=s;
				}
			if(fs==ls){ // Only sole Gray/Black sons
				return insertDfs(fs);
			}
			for(node *s=fs->bro;s!=ls;s=s->bro)
				if(s->c!=Black)
					return 0;
			
			for( int ti=0; ti<2; ++ti ){ 
				if(ti==1){ reverse(p); swap(fs,ls); }
				while(fs->c!=Black){
					alignRight(fs);
					if(!checkRight(fs))
						return 0;
					node *h=splitWhite(fs);
					if(fs->v==P){
						int nGray=cntNGray(h);
						if(nGray==0){
							h=newSubtree(h,P);
							h->c=Black;
						}
						else{
							if(h->bro){
								h->bro=newSubtree(h->bro,P);
								h->bro->c=Black;
							}
						}
					}
					else{
						if(fs->son){
							node *nfs = fs->son;
							while(nfs->bro) nfs = nfs->bro;
							nfs->bro = fs->bro;
							fs->bro = fs->son, fs->son = 0;
							fs=nfs;
						}
					}
					cat(h,fs->bro);
					fs->bro = h;
					fs = fs->bro;
				}
				if(ti==1){reverse(p);swap(fs,ls);}
			}
			for(node *s=p->son,**prev=&p->son;s;s=*prev){
				if(s->v<0){
					if(!s->son){
						*prev=s->bro;
						DELETE(s);
					}
					else if(!s->son->bro){ 
						*prev=s->son,s->son->bro=s->bro;
						DELETE(s);
					}else
						prev=&s->bro;
				}else
					prev=&s->bro;
			}
			return 1;
		}
		bool insert(char *str){
			insertS = str;
			insertPreDfs(rt);
			bool ok = insertDfs(rt);
			return ok;
		}
	};
}

char s[N][N];
PQ::PQTree sv;
int res[N];

int main(){
	int n, m, k, aux, u, x;
	while( scanf("%d", &n ) != EOF ){
		PQ::clear();
		sv.init(n);
		aux = 0;
		rep( i, 0, n ){
			scanf("%s", s[i] );
			if( aux ) continue;
			if( !sv.insert(s[i]) ) aux = 1;
		}
		if( aux ){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		sv.permutation(res);
		rep( i, 0, n ){
			rep( j, 0, n )
				printf("%c", s[i][res[j]] );
			printf("\n");
		}
		printf("\n");
	}
}
