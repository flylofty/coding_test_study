#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<char>> v;
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int Max = 0;

void input() {

	cin >> N >> M;
	v.assign(N, vector<char>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
		}
	}
}

void bfs(int a, int b) {

	queue<pair<pair<int, int>, int>> q;
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	q.push( { {a, b}, 0 } );
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (Max < time)
			Max = time;

		for (int i = 0; i < 4; ++i) {
			int n_x = x + dir[i][0];
			int n_y = y + dir[i][1];

			if (!(n_x >= 0 && n_x < N && n_y >= 0 && n_y < M))
				continue;

			if (v[n_x][n_y] == 'W' || visit[n_x][n_y])
				continue;

			q.push({ {n_x, n_y}, time + 1 });
			visit[n_x][n_y] = true;
		}
	}
}

void findAnswer() {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}
	cout << Max << "\n";
}

int main() {

	input();

	findAnswer();

	return 0;
}