#include <iostream>

using namespace std;

int main() {

	int conbination[31][31]{0};
	conbination[1][0] = 1;
	conbination[1][1] = 1;
	for (int i = 2; i <= 30; ++i) {
		conbination[i][0] = 1;
		for (int j = 1; j <= 30; ++j) {
			conbination[i][j] = conbination[i - 1][j - 1] + conbination[i - 1][j];
		}
	}

	int T = 0;
	cin >> T;

	while (T--) {

		int n, r; cin >> r >> n;
		cout << conbination[n][r] << "\n";
	}

	return 0;
}