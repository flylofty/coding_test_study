#include <iostream>

using namespace std;

int n[200001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < N; ++i)
		cin >> n[i];

	for (int i = 0; i < M; ++i) {
		int K; cin >> K;

		if (K >= N) {
			cout << n[(K - N) % (N - (V - 1)) + (V - 1)] << "\n";
		}
		else {
			cout << n[K] << "\n";
		}
	}

	return 0;
}