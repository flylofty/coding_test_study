#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int deletePuyo;
const int Row = 12;
const int Col = 6;
char map[Row][Col];
bool visit[Row][Col];
queue<pair<int, int>> q;
vector<pair<int, int>> crush;
vector<bool> changed(Col);
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool isPuyo(char p) {
	if (p == 'R' || p == 'G' || p == 'B' || p == 'P' || p == 'Y')
		return true;
	else
		return false;
}

void changeMap() {

	for (int j = 0; j < Col; ++j) {

		if (changed[j] == false)
			continue;

		for (int i = Row - 1; i >= 0; --i) {

			if (isPuyo(map[i][j])) {
				int k = i + 1;
				while (map[k][j] == '.' && k < Row)
					k++;

				if (k <= 12 && map[k - 1][j] == '.') {
					map[k - 1][j] = map[i][j];
					map[i][j] = '.';
				}
			}
		}
	}
}

void bfs(int x, int y, char puyo) {

	crush.push_back({ x, y });
	q.push({ x, y });
	visit[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int n_x = x + dir[i][0];
			int n_y = y + dir[i][1];

			if (n_x < 0 || n_x >= Row || n_y < 0 || n_y >= Col)
				continue;

			if (map[n_x][n_y] != puyo || visit[n_x][n_y])
				continue;

			crush.push_back({ n_x, n_y });
			q.push({ n_x, n_y });
			visit[n_x][n_y] = true;
		}
	}

	if (crush.size() >= 4) {
		for (int i = 0; i < crush.size(); ++i) {
			map[crush[i].first][crush[i].second] = '.';
			changed[crush[i].second] = true;
			deletePuyo--;
		}
	}
	crush.clear();
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			cin >> map[i][j];
		}
	}

	int res = 0;

	while (1) {

		for (int i = 0; i < Col; ++i)
			changed[i] = false;

		for (int i = 0; i < Row; ++i) {
			for (int j = 0; j < Col; ++j) {
				visit[i][j] = false;
			}
		}

		deletePuyo = 0;
		for (int i = 0; i < Row; ++i) {
			for (int j = 0; j < Col; ++j) {

				if (isPuyo(map[i][j]) && !visit[i][j])
					bfs(i, j, map[i][j]);
			}
		}

		if (deletePuyo == 0)
			break;

		changeMap();
		res++;
	}

	cout << res << "\n";
	return 0;
}