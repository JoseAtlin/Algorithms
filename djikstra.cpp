#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5, INF = 1e9;
#define ll long long
#define PII pair<ll, int>

priority_queue<PII, vector<PII>, greater<PII>> PQ;
vector<PII> adj[MXN];
vector<int> dist(MXN, INF);
vector<bool> visited(MXN, false);
PII p;
set<int> st;


void djikstra(int s) {
	dist[s] = 0;
	PQ.push({0, s});
	int x, y, z;
	while (!PQ.empty()) {
		p = PQ.top();
		PQ.pop();
		x = p.second;
		if (!visited[x]) {
			visited[x] = true;
			for (int i=0; i<adj[x].size(); i++) {
				y = adj[x][i].second, z = adj[x][i].first;
				if (dist[y] > dist[x] + z) {
					dist[y] = dist[x] + z;
					PQ.push({dist[y], y});
				}
			}
		}
	}
}

int main() {
	int n, e, node1, node2, weight, start_node;
	cin >> n >> e >> start_node;
	for (int i=0; i<e; i++) {
		cin >> node1 >> node2 >> weight;
		adj[node1].push_back({weight, node2});
		st.insert(node1);
		st.insert(node2);
	}
	
	djikstra(start_node);
	for (auto a : st) {
		if (a != start_node) {
			cout << dist[a] << " ";
		}
	}
	cout << "\n";
}