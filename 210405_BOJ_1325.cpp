#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, Max = 0;
vector<int> edge[10001];
queue<int> q;
bool visit[10001];
vector<int> res;

void bfs(int s) {
	
	for (int i = 1; i <= N; ++i)
		visit[i] = false;

	q.push(s);
	visit[s] = true;
	int cnt = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < edge[x].size(); ++i) {
			int y = edge[x][i];

			if (visit[y] == false) {
				q.push(y);
				visit[y] = true;
				cnt++;
			}
		}
	}

	if (cnt >= Max) {

		if (cnt > Max) {
			res.clear();
			Max = cnt;
		}

		res.push_back(s);
	}
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		edge[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i) {
		bfs(i);
	}

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << "\n";

	return 0;
}