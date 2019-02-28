#include<iostream>
#include<stack>

using namespace std;

int main(){
	
	stack<int> s;
	
	int n, aux;
	
	while(cin>>n && n){
		aux=1;
		while(aux!=0){
			bool aux2=true;
			cin>>aux;
			int m=aux;
			for(int i=1; i<m; i++) s.push(i);
			if(aux!=0){
				for(int i=1;i<n;i++){
					cin>>aux;
					if(aux>m){
						for(int i=m+1; i<aux;i++) s.push(i);
						m=aux;
					}
					else{
						if(s.top()!=aux){
							aux2=false;
						}
						else s.pop();
					}	
				}
				if(aux2)cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
			else cout<<endl;
		}
		while(s.size()!=0)s.pop();
	}
	
	return 0;
}
