#include <iostream>

using namespace std;

long long b[51];
long long w[51];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;

	b[0] = 1;
	b[1] = 1;
	b[2] = 2;
	w[0] = 1;
	w[1] = 2;
	w[2] = 3;

	for (int i = 6; i <= 100; ++i) {
		if (i % 2 == 0) {
			b[i / 2] = w[i / 2 - 1] + w[i / 2 - 3];
		}
		else {
			w[i / 2] = b[i / 2] + b[i / 2 - 2];
		}
	}

	while (T--) {
		int N; cin >> N;
		if (N % 2 == 1) {
			cout << b[N / 2];
		}
		else {
			cout << w[N / 2 - 1];
		}
		cout << "\n";
	}

	return 0;
}