#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> II;

const int INF = 987654321;
const int WALL = 1;
int N, M, T;
int castle[101][101];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int Min = INF;
II graam{0, 0};
queue<pair<int, II>> q;
bool visit[101][101];

int bfs(int s_x, int s_y, int e_x, int e_y) {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			visit[i][j] = false;
		}
	}

	q.push({ 0, {s_x, s_y} });
	visit[s_x][s_y] = true;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int distance = q.front().first;
		q.pop();

		if (x == e_x && y == e_y) {
			return distance;
		}

		for (int i = 0; i < 4; ++i) {
			int n_x = x + dir[i][0];
			int n_y = y + dir[i][1];

			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M)
				continue;

			if (castle[n_x][n_y] == WALL || visit[n_x][n_y])
				continue;

			q.push({ distance + 1 , { n_x, n_y } });
			visit[n_x][n_y] = true;
		}
	}

	return INF;
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> castle[i][j];
			if (castle[i][j] == 2) {
				graam.first = i;
				graam.second = j;
			}
		}
	}

	int withOutGraam = bfs(0, 0, N - 1, M - 1);
	
	int withGraam = bfs(0, 0, graam.first, graam.second);

	if (withGraam != INF)
		withGraam = withGraam + (N - 1 - graam.first + M - 1 - graam.second);

	Min = min(withGraam, withOutGraam);

	if (Min > T)
		cout << "Fail\n";
	else
		cout << Min << "\n";

	return 0;
}