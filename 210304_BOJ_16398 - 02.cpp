#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> v[1001];
vector<bool> visit(1001, false);

void input() {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int c; cin >> c;

			if (c == 0)
				continue;

			v[i].push_back({ j, c });
			v[j].push_back({ i, c });
		}
	}
}

void prim(int start) {

	visit[start] = true;

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for (int i = 0; i < v[start].size(); ++i) {
		int x = v[start][i].first;
		int cost = v[start][i].second;
		pq.push({ cost, x });
	}

	long long sum = 0;
	while (!pq.empty()) {
		int cost1 = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (visit[x])
			continue;

		visit[x] = true;

		sum += cost1;

		for (int i = 0; i < v[x].size(); ++i) {
			int y = v[x][i].first;

			if (visit[y])
				continue;

			int cost2 = v[x][i].second;
			pq.push({ cost2, y });
		}
	}
	cout << sum << "\n";
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	input();
	prim(1);
}