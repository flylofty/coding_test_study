#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<vector<int>> table;
int Min = 987654321;
int half = 0;

void findCase(int start, vector<bool> v, int cnt) {

	if (cnt > 0 && cnt <= half) {

		int teamA = 0;
		int teamB = 0;
		for (int i = 1; i <= N; ++i) {

			for (int j = i + 1; j <= N; ++j) {

				if (v[j] != v[i]) continue;

				if (v[i]) teamA += (table[i][j] + table[j][i]);
				else teamB += (table[i][j] + table[j][i]);
			}

		}

		Min = min(Min, abs(teamA - teamB));

		//cout << Min << "\n";
		////for (int i = 1; i <= N; ++i)
		////	if (v[i]) cout << i << " ";
		////cout << "  //////  ";
		////for (int i = 1; i <= N; ++i)
		////	if (!v[i]) cout << i << " ";
		////cout << "\n\n";
	}

	for (int i = start + 1; i <= N; ++i) {
		if (!v[i]) {
			v[i] = true;
			findCase(i, v, cnt + 1);
			v[i] = false;
		}
	}
}

int main() {

	cin >> N;
	table.assign(N + 1, vector<int>(N + 1, 0));
	
	half = N / 2;
	if (N % 2 != 0) half++;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> table[i][j];
		}
	}

	vector<bool> v(N + 1, false);
	findCase(1, v, 0);

	cout << Min << "\n";

	return 0;
}