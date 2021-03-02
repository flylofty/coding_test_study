#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(1001, vector<int>(1001, 987654321));
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c; cin >> a >> b >> c;
		v[a][b] = v[b][a] = c;
	}

	for (int i = 1; i <= N; ++i) {
		v[i][i] = 0;
	}

	vector<vector<int>> p(1001, vector<int>(2, 0));
	for (int i = 0; i < M; ++i) {
		cin >> p[i][0] >> p[i][1];
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (v[i][k] + v[k][j] < v[i][j] && v[i][k] + v[k][j] > 0)
					v[i][j] = v[i][k] + v[k][j];
			}
		}
	}

	for (int i = 0; i < M; ++i)
		cout << v[p[i][0]][p[i][1]] << "\n";

	return 0;
}