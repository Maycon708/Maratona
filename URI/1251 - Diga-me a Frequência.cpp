#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

vector<pair<int,int> > v;

bool comp(ii a, ii b){
	if(a.first!=b.first) return a.first<b.first;
	else return a.second>b.second;
}

int main(){
	
	char c[2000];
	bool aux2=false;
	
	while(gets(c)){
		if(aux2)cout<<endl;
		sort(c, c+strlen(c));
		
		char aux=c[0];
		int cont=0;
		for(int i=0; i<strlen(c); i++){
			if(aux!=c[i]){
				v.push_back(make_pair(cont, aux-0));
				aux=c[i];
				cont=0;
			}
			cont++;
		}
		v.push_back(make_pair(cont, aux-0));
		
		sort(v.begin(), v.end(), comp);
		
		for(int i=0; i<v.size(); i++) cout<<v[i].second<<" "<<v[i].first<<endl;
		v.clear();
		aux2=true;
	}
	
	return 0;
}
