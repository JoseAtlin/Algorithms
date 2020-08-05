#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5;
vector<int> adj[MXN], ans;
vector<bool> visited;
set<int> st;


void dfs(int s) {
	visited[s] = true;
	for (int i=0; i<adj[s].size(); i++) {
		if (!visited[adj[s][i]])
			dfs(adj[s][i]);
	}
	ans.push_back(s);
}

void topological_sort() {
	visited.assign(MXN, false);
	ans.clear();
	for (auto i : st) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	
	reverse(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
}

int main() {
	int n, e, node1, node2;
	cin >> n >> e;
	for (int i=0; i<e; i++) {
		cin >> node1 >> node2;
		adj[node1].push_back(node2);
		st.insert(node1);
		st.insert(node2);
	}
	
	visited.assign(MXN, false);
	cout << "Topological Sorted Order : ";
	topological_sort();
}