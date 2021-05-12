#include <iostream>

using namespace std;

int dp[100005];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	dp[0] = 0;

	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	while (M--) {
		int i, j; cin >> i >> j;

		cout << dp[j] - dp[i - 1] << "\n";
	}

	return 0;
}