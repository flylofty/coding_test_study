#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, M, V;
vector<pair<int, int>> jewelry;
vector<int> pack;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> M >> V;
		jewelry.push_back({ M, V });
	}

	for (int i = 0; i < K; ++i) {
		cin >> M; pack.push_back(M);
	}

	sort(jewelry.begin(), jewelry.end());
	sort(pack.begin(), pack.end());

	long long sum = 0;
	priority_queue<int> pq;
	int index = 0;

	for (int i = 0; i < K; ++i) {

		while (index < N && pack[i] >= jewelry[index].first)
			pq.push(jewelry[index++].second);

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum << "\n";

	return 0;
}