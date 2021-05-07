#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long q[200001]{ 0 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> q[i];
		if (i > 0)
			q[i] += q[i - 1];
	}

	for (int i = 0; i < M; ++i) {
		int time; cin >> time;
		int idx = upper_bound(q, q + N, time) - q;
		cout << idx << "\n";
	}

	return 0;
}