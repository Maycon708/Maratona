#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

int main(){
	stack<int> s;
	queue<int> q;
	priority_queue<int> pq;
	int n, a, b, t1, t2, vs[1000];
	
	while(cin>>n){
		bool aux=true, aux1=true, aux2=true;
		int cont=0;
		while(n--){
			cin >> a >> b;
			if(a==1){
				if(aux)s.push(b);
				if(aux1)q.push(b);
				if(aux2)pq.push(b);
			}
			else{
				if(aux){
					if(!s.empty() && s.top()==b){
						s.pop();
					}
					else aux=false;
				}
				if(aux1){
					if(!q.empty() && q.front()==b){
						q.pop();
					}
					else{
						aux1=false;
					}
				}
				if(aux2){
					if(!pq.empty() && pq.top()==b){
						pq.pop();
					}
					else{
						aux2=false;
					}
				}
			}
		}
		if(!aux && !aux1 && !aux2)cout << "impossible" << endl;
		if(aux && aux1 || aux && aux2 || aux1 && aux2) cout << "not sure" << endl;
	    else {
	    	if(aux)cout << "stack" << endl;
	    	if(aux1)cout << "queue" << endl;
	    	if(aux2)cout << "priority queue" << endl;
		}
		while(!q.empty()) q.pop();
		while(!pq.empty()) pq.pop();
		while(!s.empty()) s.pop();
    }
	return 0;
}
