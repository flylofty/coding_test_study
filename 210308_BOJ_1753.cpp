#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
int V, E;
int start;
vector<pair<int, int>> edge[20001];
vector<int> d(20001, INF);

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> V >> E;
	cin >> start;

	for (int i = 0; i < E; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edge[u].push_back({w, v});
	}

	// Dijkstra
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {

		int x = pq.top().second;
		int w = pq.top().first * -1;
		pq.pop();

		for (int i = 0; i < edge[x].size(); ++i) {
			int y = edge[x][i].second;
			int sum = w + edge[x][i].first;

			if (d[y] > sum) {
				d[y] = sum;
				pq.push({ sum * -1, y });
			}
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << "\n";
	}

	return 0;
}