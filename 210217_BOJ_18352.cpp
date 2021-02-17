#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
int N, M, K, X;
vector<int> v[300001];
vector<int> D(300001, INF);

void dijkstra() {

	D[X] = 0;

	queue<pair<int, int>> pq;
	pq.push({ D[X], X });

	while (!pq.empty()) {
		int weight = pq.front().first;
		int n1 = pq.front().second;
		pq.pop();

		for (int i = 0; i < v[n1].size(); ++i) {
			int sum = weight + 1;
			int n2 = v[n1][i];

			if (D[n2] > sum) {
				D[n2] = sum;
				pq.push({sum, n2});
			}
		}
	}

	vector<int> result;
	for (int i = 1; i <= N; ++i) {
		if (D[i] == K)
			result.push_back(i);
	}

	if (result.empty())
		cout << "-1\n";
	else {
		for (int i = 0; i < result.size(); ++i)
			cout << result[i] << "\n";
	}
}

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}

	dijkstra();

	return 0;
}