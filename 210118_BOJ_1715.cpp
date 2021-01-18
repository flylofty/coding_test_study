#include <iostream>
#include <queue>

using namespace std;

int main() {

	int N = 0;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; ++i) {
		int card; cin >> card;
		pq.push(card);
	}

	int sum = 0;
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		sum += (a + b);
		pq.push(a + b);
	}

	cout << sum << "\n";

	return 0;
}