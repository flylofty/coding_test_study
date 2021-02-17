#include <iostream>
#include <queue>

using namespace std;

const int EMPTY = -1;
int N = 0;
int M = 0;
int v[1000][1000];
queue<pair<int, int>> q;

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];

			if (v[i][j] == 1)
				q.push({ i, j });
		}
	}

	int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int n_x = x + dir[i][0];
			int n_y = y + dir[i][1];

			if (!(n_x >= 0 && n_x < N && n_y >= 0 && n_y < M))
				continue;

			if (v[n_x][n_y] != 0)
				continue;

			v[n_x][n_y] = v[x][y] + 1;
			q.push({n_x, n_y});
		}
	}

	int Max = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			
			if (v[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}

			if (v[i][j] == EMPTY) 
				continue;
			
			if (v[i][j] > Max)
				Max = v[i][j];
		}
	}

	cout << Max - 1 << "\n";

	return 0;
}