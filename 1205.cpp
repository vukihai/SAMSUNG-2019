#include<iostream>
#include<queue>

using namespace std;

struct Node{
	int id;
	double pri;
	Node(int _id, double _pri) {
		id = _id;
		pri = _pri;
	}
};
struct cmpNode {
	bool operator()(Node a, Node b) {
		return a.pri < b.pri;
	}	
};
int main() {
	int n, r;
	while(cin >>n >> r && n && r) {
		priority_queue<Node, vector<Node>, cmpNode> listNode;
		int parent[1002], c[1002], exist[1002], time[1002], cost[1002];
		for(int i=1; i<=n; i++) {
			cin >> c[i];
			cost[i] = c[i];
			time[i] = 1;
			exist[i] = 1;
			listNode.push(Node(i, (double)c[i]));
		}
		for(int i=1; i<n; i++) {
			int p, c;
			cin >> p >> c;
			parent[c] = p;
		}
		
		while(!listNode.empty()) {
			Node j = listNode.top(); listNode.pop();
			if(j.id == r) continue;
			if(!exist[j.id]) continue;
			
			// join j vs parent j
			for(int k = 1; k<=n; k++) if(parent[k] == j.id) {
				parent[k] = parent[j.id];
			}
			
			cost[parent[j.id]] += cost[j.id] + time[parent[j.id]] * c[j.id];
			time[parent[j.id]] += time[j.id];
			c[parent[j.id]] += c[j.id];
			
			listNode.push(Node(parent[j.id],((double)c[parent[j.id]]/time[parent[j.id]])));
			exist[j.id] = 0;
			
		}
		
		cout <<cost[r] <<endl;
	}
	
	return 0;
}
