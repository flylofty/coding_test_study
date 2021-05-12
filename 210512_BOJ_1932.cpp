#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp[500];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			int a; cin >> a;
			dp[i].push_back(a);
		}
	}

	for (int i = N - 2; i >= 0; --i) {
		for (int j = 0; j < dp[i].size(); ++j) {
			dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}

	cout << dp[0][0] << "\n";

	return 0;
}