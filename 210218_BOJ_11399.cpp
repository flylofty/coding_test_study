#include <iostream>
#include <queue>

using namespace std;

int main() {

	int N = 0;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		pq.push(a);
	}

	int sum = 0;
	while (!pq.empty()) {
		sum += pq.top() * pq.size();
		pq.pop();
	}

	cout << sum << "\n";

	return 0;
}