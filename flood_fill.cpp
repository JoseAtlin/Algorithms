#include <bits/stdc++.h>
using namespace std;

bool visited[100][100] = {false};
int n, m, dest_x, dest_y, src_x, src_y;
vector<vector<char>> mat(100, vector<char>(100));


bool dfs(int x, int y) {
	if (x == src_x && y == src_y) return true;
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	if (visited[x][y]) return false;
	if (mat[x][y] == 'X') return false;
	visited[x][y] = true;
	if (dfs(x+1, y)) return true;
	if (dfs(x, y+1)) return true;
	if (dfs(x-1, y)) return true;
	if (dfs(x, y-1)) return true;
	return false;
}

int main() {
	cin >> n >> m;
	// input a matrix as S - source, D -destination, X - cannot use, O - can use
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'S') {
				src_x = i;
				src_y = j;
			}
			if (mat[i][j] == 'D') {
				dest_x = i;
				dest_y = j;
			}
		}
	}
	if (dfs(src_x, src_y)) cout << "Possible\n";
	else cout << "Not Possible\n";
}
