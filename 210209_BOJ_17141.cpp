#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
const int VIRUS = -2;
const int WALL = -1;
int N = 0;
int M = 0;
vector <vector<int>> v(51, vector<int>(51));
vector <vector<int>> temp(51, vector<int>(51));
bool visit[51][51];
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<pair<int, int>> virus;
int Min = 987654321;

void bfs(int a, int b) {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			visit[i][j] = false;
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ {a, b}, 0 });
	visit[a][b] = true;
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int n_x = x + dir[i][0];
			int n_y = y + dir[i][1];

			if (!(n_x >= 0 && n_x < N && n_y >= 0 && n_y < N))
				continue;

			if (temp[n_x][n_y] == VIRUS || temp[n_x][n_y] == WALL || visit[n_x][n_y])
				continue;

			if (temp[n_x][n_y] <= time + 1)
				continue;

			visit[n_x][n_y] = true;
			q.push({ {n_x, n_y}, time + 1 });
			temp[n_x][n_y] = time + 1;
		}
	}

	//cout << "\n";
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < N; ++j) {
	//		cout << temp[i][j] << "\t";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";
}

void findAnswer(vector<int> t, int previous) {

	if (t.size() == M) {

		temp = v;
		for (int i = 0; i < M; ++i) {
			temp[virus[t[i]].first][virus[t[i]].second] = -2;
		}

		for (int i = 0; i < M; ++i) {
			bfs(virus[t[i]].first, virus[t[i]].second);
		}

		int Max = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {

				if (temp[i][j] == WALL || temp[i][j] == VIRUS)
					continue;

				if (temp[i][j] > Max)
					Max = temp[i][j];
			}
		}

		if (Min > Max)
			Min = Max;

		return;
	}

	for (int i = previous + 1; i < virus.size(); ++i) {
		t.push_back(i);
		findAnswer(t, i);
		t.pop_back();
	}
}

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];

			v[i][j] = v[i][j] * -1;

			if (v[i][j] == VIRUS) {
				virus.push_back({ i, j });
				v[i][j] = 0;
			}

			if (v[i][j] == 0)
				v[i][j] = INF;
		}
	}

	findAnswer({}, -1);

	if (Min == INF)
		cout << -1 << "\n";
	else
		cout << Min << "\n";

	return 0;
}