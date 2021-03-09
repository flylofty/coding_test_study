#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N, M;
int v[8][8]{ 0 };
vector<pair<int, int>> c;
int zero = 0;
int Max = 0;
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool t[8][8];

void camera(int x, int y, int z) {

	x += dir[z][0];
	y += dir[z][1];

	while (x >= 0 && x < N && y >= 0 && y < M) {

		if (v[x][y] == 6)
			break;

		if (v[x][y] == 0)
			t[x][y] = true;

		x += dir[z][0];
		y += dir[z][1];
	}
}

void findAnswer() {

	int limit = pow(4, c.size());
	for (int d = 0; d < limit; ++d) {

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				t[i][j] = false;
			}
		}

		int tmp = d;
		for (int i = 0; i < c.size(); ++i) {

			int x = c[i].first;
			int y = c[i].second;
			int z = tmp % 4;
			tmp /= 4;

			if (v[x][y] == 1) {
				camera(x, y, z);
			}
			else if (v[x][y] == 2) {
				camera(x, y, z % 4);
				camera(x, y, (z + 2) % 4);
			}
			else if (v[x][y] == 3) {
				camera(x, y, z % 4);
				camera(x, y, (z + 1) % 4);
			}
			else if (v[x][y] == 4) {
				camera(x, y, z % 4);
				camera(x, y, (z + 1) % 4);
				camera(x, y, (z + 2) % 4);
			}
			else {
				camera(x, y, 0);
				camera(x, y, 1);
				camera(x, y, 2);
				camera(x, y, 3);
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (t[i][j]) cnt++;
			}
		}

		if (Max < cnt)
			Max = cnt;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

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

	findAnswer();
	cout << zero - Max << "\n";
	return 0;
}