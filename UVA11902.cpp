#include<iostream>
using namespace std;

int graph[101][101], n;

void dfs(int u, int * visited) {
	visited[u] = 1;
	for(int v=0; v<n; v++) {
		if(graph[u][v] && !visited[v]) dfs(v, visited);
	}
}
void dfs_without(int u, int * visited, int _deletedNode) {
	if(u == _deletedNode) return;
	visited[u] = 1;
	for(int v=0; v<n; v++) {
		if(graph[u][v] && !visited[v]) dfs_without(v, visited, _deletedNode);
	}
}
int main() {
	int Test;
	cin >> Test;
	int t = 0;
	while(t++ < Test) {
		cin >> n;
		for(int i = 0; i<n; i++) 
			for(int j = 0; j<n; j++)
				cin >> graph[i][j];
		
		int canVisit[101] = {0};
		dfs(0, canVisit);
		cout << "Case " << t <<":" <<endl;
		for(int i=0; i<n; i++) {
			
			cout <<'+';
			for(int i=0; i< n*2 - 1; i++) cout << '-';
			cout <<'+'<<endl;
			
			int visit[101] = {0};
			dfs_without(0, visit, i);
			for(int j=0; j<n; j++) {
				cout << '|';
				if(canVisit[j] && !visit[j]) cout << 'Y'; else cout << 'N';
			}
			cout << '|' <<endl;
		}
		cout <<'+';
		for(int i=0; i< n*2 - 1; i++) cout << '-';
		cout <<'+'<<endl;
	}
	return 0;
}
