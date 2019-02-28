#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

map < ii, int > mp;
map <int, int> mp1;

int main(){
	
	int n, m, a,b, aux;
	
	while(scanf("%d%d", &n, &m) != EOF){
		
		for(int i=1; i<=n; i++){
			scanf("%d", &aux);
			mp1[aux]++;
			mp[ii(aux, mp1[aux])] = i;	
		}
		
		while(m--){
			scanf("%d%d", &a, &b);
			printf("%d\n", mp[ii(b,a)]);
		}
		
		mp.clear();
		mp1.clear();
	}
	
}

