#include <iostream>
#include <vector>

using namespace std;

int N, M;
int v[9][9]{ 0 };
vector<pair<int, int>> c;
int zero = 0;
int Max = 0;
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void camera(int x, int y, vector<vector<bool>>& t, int k) {

	x += dir[k][0];
	y += dir[k][1];

	while (x >= 0 && x < N && y >= 0 && y < M) {

		if (v[x][y] == 6)
			break;

		if (v[x][y] == 0)
			t[x][y] = true;

		x += dir[k][0];
		y += dir[k][1];
	}
}

void findAnswer(int index, vector<vector<bool>> t) {

	if (index == c.size()) {

		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (t[i][j]) cnt++;
			}
		}

		if (cnt > Max)
			Max = cnt;

		return;
	}

	int x = c[index].first;
	int y = c[index].second;

	int cnt;
	if (v[x][y] == 2)
		cnt = 2;
	else if (v[x][y] == 5)
		cnt = 1;
	else
		cnt = 4;

	for (int i = 0; i < cnt; ++i) {

		vector<vector<bool>> temp = t;

		if (v[x][y] == 1) {
			camera(x, y, temp, i);
		}
		else if (v[x][y] == 2) {
			camera(x, y, temp, i);
			camera(x, y, temp, i + 2);
		}
		else if (v[x][y] == 3) {
			camera(x, y, temp, i % 4);
			camera(x, y, temp, (i + 1) % 4);
		}
		else if (v[x][y] == 4) {
			camera(x, y, temp, i % 4);
			camera(x, y, temp, (i + 1) % 4);
			camera(x, y, temp, (i + 2) % 4);
		}
		else {
			camera(x, y, temp, 0);
			camera(x, y, temp, 1);
			camera(x, y, temp, 2);
			camera(x, y, temp, 3);
		}

		findAnswer(index + 1, temp);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];

			if (v[i][j] == 0 || v[i][j] == 6) {
				if (v[i][j] == 0)
					zero++;
				continue;
			}
			else {
				c.push_back({ i, j });
			}
		}
	}

	vector<vector<bool>> t(N, vector<bool>(M, false));
	findAnswer(0, t);
	cout << zero - Max << "\n";

	return 0;
}