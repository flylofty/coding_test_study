#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int v[101][101]{ 0 };

int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		string a; cin >> a;
		for (int j = 1; j <= M; ++j) {
			v[i][j] = a[j - 1] - '0';
		}
	}

	int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

	queue<pair<int, pair<int, int>>> q;
	q.push({ 1, {1, 1} });
	v[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cnt = q.front().first;
		q.pop();

		if (x == N && y == M) {
			cout << cnt << "\n";
			return 0;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (!(nx >= 0 && nx <= N && ny >= 0 && ny <= M))
				continue;

			if (v[nx][ny] == 0)
				continue;

			q.push({ cnt + 1, {nx, ny} });
			v[nx][ny] = 0;
		}
	}

	return 0;
}