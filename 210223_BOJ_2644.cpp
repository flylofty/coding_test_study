#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, a, b, m;
vector<int> v[101];
vector<bool> visit(101, false);

int main() {

	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		v[x].push_back(y); 
		v[y].push_back(x);
	}

	//bfs
	queue<pair<int, int>> q;
	q.push({ a, 0 });
	visit[a] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int r = q.front().second;
		q.pop();

		if (x == b) {
			cout << r << "\n";
			return 0;
		}

		for (int i = 0; i < v[x].size(); ++i) {

			int y = v[x][i];

			if (!visit[y]) {
				q.push({ y, r + 1 });
				visit[y] = true;
			}
		}
	}

	cout << "-1\n";
	return 0;
}