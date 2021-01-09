#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int t = 0;
int n = 0;
vector<vector<int>> c;
vector<bool> check;
bool isHappy;

void findAnswer(int r) { // DFS

	check[r] = true;

	if (r == n + 1) {
		isHappy = true;
		return;
	}

	for (int i = 0; i < n + 2; ++i) {
		if (check[i]) continue;

		if (abs(c[r][0] - c[i][0]) + abs(c[r][1] - c[i][1]) <= 1000) {
			findAnswer(i);
		}
	}
}

void input() {
	cin >> t;

	while (t--) {

		cin >> n;
		c.assign(n + 2, vector<int>(2, 0));
		for (int i = 0; i < n + 2; ++i) {
			cin >> c[i][0] >> c[i][1];
		}
		check.assign(n + 2, false);
		isHappy = false;
		findAnswer(0);

		if (isHappy)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	return 0;
}