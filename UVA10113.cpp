#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<pipii> vpipii;

map<string, int> proToInt;
int proNum = 0;
vector<vpipii> graph;

int gdc(int a, int b) {
	if(a== b) return a;
	if(a< b) return gdc(a, b-a);
	return gdc(a-b, b);
}
int main() {
	graph.assign(61, vpipii());
	
	char cmd;
	while(cin >> cmd && cmd != '.') {
		if(cmd == '!') {
			// info
			string pro1, pro2;
			int num, denum;
			cin >> num >> pro1 >> pro2 >> denum >> pro2;
			if(proToInt.find(pro1) == proToInt.end()) {
				proToInt[pro1] = proNum;
				proNum++;
			}
			if(proToInt.find(pro2) == proToInt.end()) {
				proToInt[pro2] = proNum;
				proNum++;
			}
			int p1 = proToInt[pro1];
			int p2 = proToInt[pro2];
			graph[p1].push_back(make_pair(p2, make_pair(num, denum)));
			graph[p2].push_back(make_pair(p1, make_pair(denum, num)));
		} else {
			// query
			string pro1, pro2;
			cin >> pro1 >> pro2 >> pro2;
			int p1 = proToInt[pro1];
			int p2 = proToInt[pro2];
			
			//bfs
			int visited[61] = {0};
			bool found = false;
			queue<pipii> q;
			q.push(make_pair(p1, make_pair(1, 1)));
			while(!q.empty()) {
				pipii parent = q.front(); q.pop(); visited[parent.first] = 1;
				if(parent.first == p2) {
					int ucln = gdc(parent.second.first, parent.second.second);
					cout << parent.second.second/ucln <<" " << pro1 <<" = " << parent.second.first/ucln << " " << pro2 << endl;
					found = true;
					break;
				}
				for(int i=0; i< graph[parent.first].size(); i++) {
					pipii child = graph[parent.first][i];
					if(! visited[child.first]) {
						q.push(make_pair(child.first, make_pair(parent.second.first * child.second.second, parent.second.second * child.second.first)));
					}
				}
				
			}
			if(!found) cout << "? " << pro1 << " = ? " << pro2 <<endl;
		}
	}
	
	return 0;
}
