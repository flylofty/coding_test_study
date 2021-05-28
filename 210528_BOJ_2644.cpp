#include <iostream>
#include <vector>

using namespace std;

int n, from, to, m;
vector<int> E[101];
bool check[101];

void DFS(int node, int cnt) {

	if (node == to) {
		cout << cnt;
		exit(0);
	}

	for (int i = 0; i < E[node].size(); ++i) {

		int idx = E[node][i];

		if (!check[idx]) {
			check[idx] = true;
			DFS(E[node][i], cnt + 1);
			check[idx] = false;
		}
	}
}

int main() {

	cin >> n;

	cin >> from >> to;

	cin >> m;

	for (int i = 0; i < m; ++i) {
		
		int x, y; 
		
		cin >> x >> y;
		
		E[x].push_back(y);
		E[y].push_back(x);
	}

	DFS(from, 0);

	cout << -1;
	return 0;
}