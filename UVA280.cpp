#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef vector<int> vi;

int main() {
	while(true) { // lap qua so do thi
		int n;
		cin >> n;
		if(n==0) break;
		vector<vi> v;
		v.assign(n+1, vi());
		
		while(true) {
			int i;
			cin >> i;
			if(i==0) break;
			while(true) {
				int j = 0;
				cin >> j;
				if(j==0) break;
				v[i].push_back(j);
			}
		}
		
		int numQuery;
		cin >> numQuery;
		for(int i=0; i<numQuery; i++) {
			int query;
			cin >>query;
			
			// bfs
			int visited[101] = {0};
			int numVisited = 0;
			queue<int> q;
			for(int j = 0; j < v[query].size(); j++) {
				q.push(v[query][j]);
			}
			
			while(!q.empty()) {
				int parent = q.front(); q.pop();
				if(!visited[parent]) numVisited++;
				visited[parent] = 1;
				
				
				for(int j = 0; j < v[parent].size(); j++) {
					if(!visited[v[parent][j]]) q.push(v[parent][j]);
				}
			}
			//cout <<"----------" << endl;
			cout << n - numVisited;
			for(int j=1; j<=n; j++) if(!visited[j]) cout << ' ' << j;
			cout << endl;
			//cout <<"----------end"<<endl;
		}
		
	}
	
	
	return 0;
}
