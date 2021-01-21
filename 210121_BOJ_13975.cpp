#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T = 0;
	cin >> T;
	
	priority_queue<long long, vector<long long>, greater<long long>> pq;

	while (T--) {
		int K = 0;
		cin >> K;

		while (!pq.empty())
			pq.pop();

		for (int i = 0; i < K; ++i) {
			int s = 0; cin >> s;
			pq.push(s);
		}

		long long sum = 0;
		while (pq.size() > 1) {
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();

			sum += (a + b);
			pq.push(a + b);
		}

		cout << sum << "\n";
	}

	return 0;
}