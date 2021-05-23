#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;

int N, student, mate[4];
int classRoom[21][21];
bool like[401][401]{ false };
int dir[4][2]{ { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

bool isEmpty(vector<II> v[5]) {

	for (int i = 0; i < 5; ++i) {
		if (!v[i].empty())
			return false;
	}
	return true;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	for (int tmp = 1; tmp <= N * N; ++tmp) {

		cin >> student;
		for (int i = 0; i < 4; ++i) {
			cin >> mate[i];

			like[student][mate[i]] = true;
		}

		int adjMax = 0, emptyMax = 0;
		vector<II> adjMate[5];
		vector<II> Empty[5];
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {

				if (classRoom[i][j] > 0)
					continue;

				int adjCount = 0;
				int emptyCount = 0;

				for (int k = 0; k < 4; ++k) {

					int x = i + dir[k][0];
					int y = j + dir[k][1];

					if (x < 1 || x > N || y < 1 || y > N)
						continue;

					if (like[student][classRoom[x][y]])
						adjCount++;

					if (classRoom[x][y] == 0)
						emptyCount++;
				}

				if (adjCount > adjMax)
					adjMax = adjCount;

				if (emptyCount > emptyMax)
					emptyMax = emptyCount;

				adjMate[adjCount].push_back({ i, j });
				Empty[emptyCount].push_back({ i, j });
			}
		}

		int a = 0, b = 0;

		vector<II> res;

		for (int i = emptyMax; i >= 0; --i) {

			for (int j = 0; j < Empty[i].size(); ++j) {

				II t1 = Empty[i][j];

				for (int k = 0; k < adjMate[adjMax].size(); ++k) {
					II t2 = adjMate[adjMax][k];

					if (t1.first == t2.first && t1.second == t2.second)
						res.push_back(t2);
				}
			}

			if (!res.empty())
				break;
		}

		sort(res.begin(), res.end());
		a = res[0].first;
		b = res[0].second;

		classRoom[a][b] = student;
	}

	int total = 0;
	int socre[5]{ 0, 1, 10, 100, 1000 };
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {

			int cnt = 0;
			for (int k = 0; k < 4; ++k) {

				int x = i + dir[k][0];
				int y = j + dir[k][1];

				if (x < 1 || x > N || y < 1 || y > N)
					continue;

				if (like[classRoom[i][j]][classRoom[x][y]])
					cnt++;
			}

			total += socre[cnt];
		}
	}

	cout << total;
	return 0;
}