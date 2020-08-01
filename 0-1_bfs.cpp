#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5;

vector<pair<int,int>> adj[mxn];
vector<int> length(mxn, 999999);

void bfs(int s) {
	deque<int> que;
	que.push_back(s);
	length[s] = 0;
	while (!que.empty()) {
		int p = que.front();
		que.pop_front();
		for (int i=0;i<adj[p].size();i++) {
			if (length[adj[p][i].first] > length[p] + adj[p][i].second) {
				length[adj[p][i].first] = length[p] + adj[p][i].second;
				if (adj[p][i].second == 0) {
					que.push_front(adj[p][i].first);
				}
				else {
					que.push_back(adj[p][i].first);
				}
			} 
		}
	}
}

int main() {
	int n,e,start_node,end_node,weight,node1,node2;
	cin >> n >> e >> start_node >> end_node;
	for (int i=0;i<e;i++) {
		cin >> node1 >> node2 >> weight;
		adj[node1].push_back(make_pair(node2, weight));
		adj[node2].push_back(make_pair(node1, weight));
	}
	
	bfs(start_node);
	cout << "min_dist(" << start_node << "," << end_node << ")" << " = " <<  length[end_node] << "\n";
}
