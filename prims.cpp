#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5;
#define ll long long
#define PII pair<ll, int>

priority_queue<PII, vector<PII>, greater<PII>> PQ;
vector<bool> visited(mxn, false);
vector<PII> adj[mxn];
PII p;


ll prims(int s) {
	PQ.push({0, s});
	ll min_cost = 0, x, y;
	while (!PQ.empty()) {
		p = PQ.top();
		PQ.pop();
		x = p.second;
		if (!visited[x]) {
			min_cost += p.first;
			visited[x] = true;
			for (int i=0; i<adj[x].size(); i++) {
				y = adj[x][i].second;
				if (!visited[y]) {
					PQ.push(adj[x][i]);
				}
			}
		}
	}
	
	return min_cost;
}

int main() {
	ll n, e, node1, node2, cost, start_node;
	cin >> n >> e;
	for (int i=0; i<e; i++) {
		cin >> node1 >> node2 >> cost;
		adj[node1].push_back({cost, node2});
		adj[node2].push_back({cost, node1});
	}
	
	start_node = node1;
	cout << "Min cost for min spanning tree : " << prims(start_node) << "\n";
}