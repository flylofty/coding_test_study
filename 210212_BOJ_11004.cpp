#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int num; cin >> num;
		pq.push(num);
	}

	for (int i = 1; i <= K - 1; ++i) {
		pq.pop();
	}

	cout << pq.top() << "\n";

	return 0;
}