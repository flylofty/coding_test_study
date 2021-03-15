#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
int N, M, f, t;
vector<pair<int, int>> E[1001];
int D[1001];
priority_queue<pair<int, int>> pq;
int visit[1001]{ 0 };

void input() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b, c; cin >> a >> b >> c;
		E[a].push_back({ c, b });
	}
	cin >> f >> t;
}

void Dijkstra() {

	for (int i = 1; i <= N; ++i)
		D[i] = INF;
	
	D[f] = 0;

	pq.push({ 0, f });

	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = pq.top().first * -1;
		pq.pop();

		for (int i = 0; i < E[x].size(); ++i) {
			int y = E[x][i].second;
			int sum = cost + E[x][i].first;

			if (D[y] > sum) {
				D[y] = sum;
				pq.push({ -sum, y });
				visit[y] = x;
			}
		}
	}

	cout << D[t] << "\n";

	int index = t;
	vector<int> res;
	res.push_back(t);
	while (1) {
		res.push_back(visit[index]);
		index = visit[index];
		if (visit[index] == 0)
			break;
	}

	cout << res.size() << "\n";
	for (int i = res.size() - 1; i >= 0; --i)
		cout << res[i] << " ";
	cout << "\n";

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	Dijkstra();
	return 0;
}