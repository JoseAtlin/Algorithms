#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5;

vector<int> adj[mxn];
vector<bool> visited(mxn, false);
set<int> st;

void dfs(int s) {
	visited[s] = true;
	for (int i=0; i<adj[s].size(); i++) {
		if (!visited[adj[s][i]])
			dfs(adj[s][i]);
	}
}

int main() {
	int n,e,node1,node2;
	cin >> n >> e;
	for (int i=0; i<e; i++) {
		cin >> node1 >> node2;
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
		st.insert(node1);
		st.insert(node2);
	}

	int components = 0;
	for (auto i : st) {
		if (!visited[i]) {
			dfs(i);
			components += 1;
		}
	}

	cout << "No. of components : " << components << "\n";
}
