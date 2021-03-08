#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	long long N, M;
	cin >> N >> M;

	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	long long left = 0;
	long long right = v[N - 1] * M;

	while (left <= right) {
		
		long long mid = (left + right) / 2;

		long long time = mid;
		long long total = 0;
		for (int i = N - 1; i >= 0; --i) {

			if (total > M)
				break;

			total += (time / v[i]);
		}

		if (total >= M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << left << "\n";

	return 0;
}