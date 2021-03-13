#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
int arr[51][51];
bool visit[51][51];
queue<pair<int, int>> q;
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push({x, y});
	visit[x][y] = true;

	vector<pair<int, int>> g;
	g.push_back({x, y});


	int sum = arr[x][y];
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int n_x = x + dir[i][0];
			int n_y = y + dir[i][1];

			if (!(n_x >= 0 && n_x < N && n_y >= 0 && n_y < N))
				continue;

			int d = abs(arr[x][y] - arr[n_x][n_y]);
			if (L > d || d > R || visit[n_x][n_y])
				continue;

			g.push_back({ n_x, n_y });
			visit[n_x][n_y] = true;
			q.push({ n_x, n_y });
			sum += arr[n_x][n_y];
		}
	}

	if (g.size() <= 1)
		return 0;

	for (int i = 0; i < g.size(); ++i)
		arr[g[i].first][g[i].second] = sum / g.size();

	return 1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	int t = 0;
	while (t < 2000) {

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				visit[i][j] = false;
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!visit[i][j])
					cnt += bfs(i, j);
			}
		}

		if (cnt == 0)
			break;

		t++;
	}

	cout << t << "\n";

	return 0;
}