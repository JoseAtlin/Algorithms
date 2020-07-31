#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e3;

vector<bool> visited;
vector<int> adj[mxn], adj_rev[mxn];
stack<int> order;

void dfs1 (int s) {
	visited[s] = true;
	for (int i=0; i<adj[s].size(); i++)
		if (!visited[adj[s][i]])
			dfs1(adj[s][i]);
	order.push(s);
}

void dfs2 (int s) {
	visited[s] = true;
	cout << s << " ";
	for (int i=0; i<adj_rev[s].size(); i++) {
		if (!visited[adj_rev[s][i]])
			dfs2(adj_rev[s][i]);
	}
}

int main () {
	int n, e, node1, node2;
	cin >> n >> e;
	for (int i=0; i<e; i++) {
		cin >> node1 >> node2;
		adj[node1].push_back(node2);
		adj_rev[node2].push_back(node1);
	}
	
	visited.assign(n, false);
	for (int i=0; i<n; i++) {
		if (!visited[i])
			dfs1(i);
	}

	visited.assign(n, false);
	int count = 0;
	while (!order.empty()) {
		int s = order.top();
		order.pop();
		if (!visited[s]) {
			dfs2(s);
			cout << "\n";
			count += 1;
		}
	}
	cout << "No. of Strongly Connected Components : " << count << "\n";
}