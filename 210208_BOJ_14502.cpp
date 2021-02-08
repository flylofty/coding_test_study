#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int M = 0;
vector<pair<int, int>> s;
vector<vector<int>> v(8, vector<int>(8));
vector<vector<int>> temp(8, vector<int>(8));
bool visit[8][8];
int zero = 0;
int Max = 0;
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int bfs(int a, int b) {

	queue<pair<int, int>> q;
	q.push({ a, b });
	visit[a][b] = true;
	int cnt = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int n_x = x + dir[i][0];
			int n_y = y + dir[i][1];

			if (!(n_x >= 0 && n_x < N && n_y >= 0 && n_y < M))
				continue;

			if (temp[n_x][n_y] == 1 || temp[n_x][n_y] == 2 || visit[n_x][n_y])
				continue;

			visit[n_x][n_y] = true;
			cnt++;
			q.push({ n_x, n_y });
		}
	}

	return cnt;
}

void findSituation(vector<int> t, int previous) {

	if (t.size() == 3) {

		temp = v;
		for (int i = 0; i < 3; ++i) {
			temp[s[t[i]].first][s[t[i]].second] = 1;
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				visit[i][j] = false;
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (temp[i][j] == 2 && !visit[i][j]) {
					cnt += bfs(i, j);
				}
			}
		}

		int result = zero - cnt - 3;
		if (result > Max) {
			Max = result;
            //// cout << s[t[0]].first << ", " << s[t[0]].second << "\n";
			//// cout << s[t[1]].first << ", " << s[t[1]].second << "\n";
			//// cout << s[t[2]].first << ", " << s[t[2]].second << "\n";
			//// cout << Max << "\n\n";
		}
		return;
	}

	for (int i = previous + 1; i < N * M; ++i) {
		if (v[s[i].first][s[i].second] == 0) {
			t.push_back(i);
			findSituation(t, i);
			t.pop_back();
		}
	}
}

int main() {
    
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			s.push_back({ i, j });
			cin >> v[i][j];
			if (v[i][j] == 0) zero++;
		}
	}

	findSituation({}, -1);
	cout << Max << "\n";

	return 0;
}