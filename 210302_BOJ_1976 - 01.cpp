#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> v[201];
vector<int> p;

bool bfs(int a, int b) {
	
	vector<bool> visit(N + 1, false);
	
	queue<int> q;
	q.push(a);
	visit[a] = true;


	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == b) {
			return true;
		}

		for (int i = 0; i < v[x].size(); ++i) {
			if (!visit[v[x][i]]) {
				q.push(v[x][i]);
				visit[v[x][i]] = true;
			}
		}
	}

	return false;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int a; cin >> a;
			if (a == 1) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		int a; cin >> a;
		p.push_back(a);
	}

	int i = 1;
	for (; i < M; ++i) {
		if (!bfs(p[i - 1], p[i]))
			break;
	}

	if (i == M)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}