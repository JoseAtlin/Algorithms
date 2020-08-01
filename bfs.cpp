#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5;

vector<int> adj[mxn];
vector<bool> visited;
vector<int> level(mxn);
set<int> st;

void bfs(int s) {
	queue<int> que;
	que.push(s);
	level[s] = 0;
	visited[s] = true;
	while (!que.empty()) {
		int p = que.front();
		que.pop();
		for (int i=0; i<adj[p].size(); i++) {
			if (!visited[adj[p][i]]) {
				level[adj[p][i]] = level[p] + 1;
				visited[adj[p][i]] = true;
				que.push(adj[p][i]);
			}
		}
	}
}

int main() {
	int n,e,start_node,node1,node2;
	cin >> n >> e >> start_node;
	for (int i=0; i<e; i++) {
		cin >> node1 >> node2;
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
		st.insert(node1);
		st.insert(node2);
	}
	
	visited.assign(n, false);
	bfs(start_node);
	cout << "node" << "\t" << "level" << "\n";
	for (auto i : st)
		cout << i  << "\t"<< level[i] << "\n";
}
