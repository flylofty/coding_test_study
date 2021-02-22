#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int bucket[1000000]{0};
	int N, K;
	cin >> N >> K;

	int last = 0;
	for (int i = 0; i < N; ++i) {
		int g, p; cin >> g >> p;
		bucket[p] = g;

		if (last < p)
			last = p;
	}

	int a = 0;
	int b = 0;

	int fin;
	if (K * 2 + 1 > 1000000) {
		fin = 1000000;
	}
	else {
		fin = K * 2 + 1;
	}

	int sum = 0;
	for ( ; b < fin; ++b) {
		sum += bucket[b];
	}
	b--;

	int Max = sum;

	while (b <= last) {
		sum -= bucket[a];
		a++, b++;
		sum += bucket[b];

		if (sum > Max)
			Max = sum;
	}

	cout << Max << "\n";

	return 0;
}