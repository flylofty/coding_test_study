#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int M = 0;
vector<int> v[101];
vector<bool> visited(101, false);

int main() {

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;

	int cnt = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); ++i) {

			int y = v[x][i];

			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				cnt++;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}