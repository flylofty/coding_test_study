#include <iostream>

using namespace std;

int A[1000000];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	int B, C; cin >> B >> C;

	long long total = 0;

	for (int i = 0; i < N; ++i) {
		
		total++;
		
		int temp = A[i] - B;

		if (temp <= 0)
			continue;

		total += temp / C;

		if (temp % C != 0)
			total++;
	}

	cout << total;

	return 0;
}