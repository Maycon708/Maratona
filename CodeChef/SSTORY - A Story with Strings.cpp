#include <bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define debug(a) cout << #a << " = " << a << endl;
#define F first
#define S second
#define INF 0x3f3f3f3f
typedef long long int ll;
typedef pair<int, int> ii;
 
const int MAX = 500050;
int gap, tam, sa[MAX], pos[MAX], lcp[MAX], tmp[MAX]; 
 
bool sufixCmp(int i, int j){
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
	i+=gap, j+=gap;
	return (i<tam && j<tam) ? pos[i]<pos[j] : i>j;
}
void buildSA(char s[]){
	tam=strlen(s);
	for(int i=0; i<tam; i++) 
		sa[i]=i, pos[i]=s[i], tmp[i]=0;
		
	for(gap=1;;gap*=2){
		sort(sa, sa+tam, sufixCmp);
		tmp[0]=0;
		for(int i=0; i<tam-1; i++)
			tmp[i+1] = tmp[i] + sufixCmp(sa[i], sa[i+1]);
		for(int i=0; i<tam; i++)
			pos[sa[i]]=tmp[i];
		if(tmp[tam-1] == tam-1) break;
	}
}
ll buildLCP(char s[]){
	ll sum=0;
	for(int i=0, k=0; i<tam; i++){
		if(pos[i]==tam-1) continue;
		for(int j=sa[pos[i]+1]; s[i+k]==s[j+k];) k++;
		lcp[pos[i]+1] = k;
		sum+=k;
		if(k>0) k--;
	}
	return sum;
}
void PrintAll(char s[]){
	printf("SA\ttam\tLCP\tSuffix\n");
	rep(i, 0, tam)
		printf("%2d\t%2d\t%2d\t%s\n", sa[i], tam-sa[i], lcp[i], s + sa[i]);
}
ll num_subs(ll m){
	return (ll)tam*(tam+1)/2 - m;
}
ll num_subsrn(){
	ll ret=0;
	rep(i, 1, tam)
		if(lcp[i]>lcp[i-1])
			ret+=lcp[i]-lcp[i-1];
	return ret;
}
void printans(char s[], int n){
	int maior=0, id=-1;
	rep(i, 0, tam)
		if(lcp[i]>n	 && lcp[i]>maior)
			maior=lcp[i], id=i;
	if(id==-1) printf("*");
	else
		rep(i, sa[id], sa[id]+maior)
			printf("%c", s[i]);
	printf("\n");
}

char s[MAX];
int main(){
	
	while(scanf("%s", s) != EOF ){
		int T = strlen(s);
		s[T] = '$';
		scanf("%s", s+T+1 );
		
		if(s[0]=='*') break;
		buildSA(s);
		ll m=buildLCP(s);
		
		int ans = 0, id = tam, lid = tam;
		for( int i = 1; i < tam; i++ ){
			if( sa[i] < T && sa[i-1] > T ||  sa[i] > T && sa[i-1] < T ) ans = max( ans, lcp[i] );
		}
		
		for( int i = 1; i < tam; i++ ){
			if( lcp[i] >= ans ){
				if( sa[i] < T && sa[i-1] > T ||  sa[i] > T && sa[i-1] < T ){
					id = min( id, max( sa[i], sa[i-1] ));
					while( i < tam && lcp[i+1] >= ans ){
						i++;
						if( sa[i] > m ) id = min( id, sa[i] );
					}
					id = min( id, lid );
				}
				else if( sa[i] > T ){
					lid = min( sa[i], sa[i-1] );
				}
			}
			else{
				lid = tam;
			}
		}
		
		if( ans ){
			rep( i,  id, id+ans  ){
				printf("%c", s[i]);
			}
			printf("\n");
		}
		printf("%d\n", ans );
		
		//PrintAll(s); //printa sa, lcp, suffixs
		//printf("%lld\n", num_subs(m)); //numero de substrings nao repetidas
		//printf("%lld\n", num_subsrn()); //numero de substrings que se repete 
		//printans(s, 2); //maior substring de tamanho maior ou igual a n que se repete
		break;
	}
}

