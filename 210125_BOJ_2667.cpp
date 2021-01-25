#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
//int m[25][25]{ 0 };
vector<vector<int>> m;

void input() {

	cin >> N;
	m.assign(N, vector<int>(N));

	for (int i = 0; i < N; ++i) {
		string t; cin >> t;
		for (int j = 0; j < t.size(); ++j) {
			m[i][j] = t[j] - '0';
		}
	}
}

int bfs(int a, int b) {

	int numOfHouse = 0;
	int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

	queue<pair<int, int>> q;
	q.push({ a, b });
	m[a][b] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		numOfHouse++;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int n_x = x + dir[i][0];
			int n_y = y + dir[i][1];

			if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N && m[n_x][n_y]) {
				q.push({ n_x, n_y });
				m[n_x][n_y] = 0;
			}
		}
	}

	return numOfHouse;
}

void findAnswer() {

	int count = 0;
	vector<int> h;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (m[i][j] == 1) {
				h.push_back(bfs(i, j));
				count++;
			}
		}
	}

	cout << count << "\n";
	sort(h.begin(), h.end());
	for (int i = 0; i < h.size(); ++i) {
		cout << h[i] << "\n";
	}
}

int main() {
	input();
	findAnswer();
	return 0;
}