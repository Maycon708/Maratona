#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int n, t, v[3000000];
	
	scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		for(int i=0;i<t;i++){
			scanf("%d", &v[i]);	
		}
		sort(v,v+t);
		for(int i=0;i<t;i++){
			if(i!=0) printf(" ");
			printf("%d", v[i]);
		}
		printf("\n");
	}
	return 0;
}
