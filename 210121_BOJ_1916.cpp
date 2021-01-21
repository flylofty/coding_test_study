#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0; // N개의 도시, 정점의 수
int M = 0; // 간선
vector<pair<int, int>> v[1001];
int from = 0;
int to = 0;

void input() {
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int s, e, w;
		cin >> s >> e >> w;
		v[s].push_back({w, e});
	}

	cin >> from >> to;
}

void shortestPath() {
	vector<int> d(N + 1, 987654321);
	d[from] = 0;

	//priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	queue<pair<int, int>> q;
	q.push({0, from});

	while (!q.empty()) {
		int x = q.front().second;
		int weight = q.front().first;
		q.pop();

		for (int i = 0; i < v[x].size(); ++i) {
			int y = v[x][i].second;
			int distance = weight + v[x][i].first;

			if (d[y] > distance) {
				q.push({ distance, y });
				d[y] = distance;
			}
		}
	}

	cout << d[to] << "\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	input();
	shortestPath();
	return 0;
}