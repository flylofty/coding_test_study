#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> v[1001];

void bfs(int a, int b) {

	vector<bool> visit(N + 1, false);

	queue<pair<int, int>> q;
	q.push({a, 0});
	visit[a] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop();

		if (x == b) {
			cout << d << "\n";
			return;
		}

		for (int i = 0; i < v[x].size(); ++i) {
			if (!visit[v[x][i].first]) {
				q.push({ v[x][i].first, d + v[x][i].second });
				visit[v[x][i].first] = true;
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N - 1; ++i) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	while (M--) {
		int a, b; cin >> a >> b;
		bfs(a, b);
	}

	return 0;
}