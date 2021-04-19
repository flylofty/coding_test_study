#include <iostream>

using namespace std;

int main() {

	long long N, M;
	cin >> N >> M;

    long long x, y, cnt;
    
	if (N > M) {
		y = (M - 2) / 2;
		x = M / 2;

		if (M % 2 != 0) {
			y = y + 1;
			x = x + (N - M);
		}

		cnt = M * 2 - 1;
	}
	else { // N <= M
		y = N / 2 - 1;
		x = (N - 1) / 2;

		if (N % 2 != 0)
			y = y + (M - N + 1);
		else
			x++;

		cnt = (N - 1) * 2;

		if (N == M)
			cnt == M * 2;
	}

	cout << cnt << "\n";
	x++; y++;
	cout << x << " " << y << "\n";

	return 0;
}