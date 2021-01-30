#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, L;
	cin >> N >> L;

	vector<vector<int>> v(N + 1, vector<int>(3, 0));
	v[0][0] = v[0][1] = v[0][2] = 0;
	int seconds = 0;
	for (int i = 1; i < N + 1; ++i) {

		for (int j = 0; j < 3; ++j) {
			cin >> v[i][j];
		}

		seconds += v[i][0] - v[i - 1][0];

		int waitTime = v[i][1] - (seconds % (v[i][1] + v[i][2]));

		if (waitTime >= 0)
			seconds += waitTime;
	}

	seconds += L - v[v.size() - 1][0];

	cout << seconds << "\n";

	return 0;
}