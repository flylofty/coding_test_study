#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 1000001;
int dp[Max];
int tracking[Max];

int main() {

	int X; cin >> X;

	for (int i = 2; i <= X; ++i) {

		dp[i] = dp[i - 1] + 1;
		int t = i - 1;

		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
			
			if (dp[i] == dp[i / 2] + 1)
				t = i / 2;
		}

		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);

			if (dp[i] == dp[i / 3] + 1)
				t = i / 3;
		}

		tracking[i] = t;
	}

	cout << dp[X] << "\n";

	while (X > 0) {
		cout << X << " ";
		X = tracking[X];
	}

	return 0;
}