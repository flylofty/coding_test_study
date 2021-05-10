#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
pair<int, pair<int, int>> edge[1000000];
int group[100001];

void init() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
		cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;

	sort(edge, edge + M);
}

int find(int a) {
	if (a == group[a]) return a;
	else return group[a] = find(group[a]);
}

bool Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a == b)
		return true;

	group[b] = a;
	return false;
}

void kruskal() {

	for (int i = 1; i <= N; ++i)
		group[i] = i;

	int sum = 0;
	int cnt = 0;

	for (int i = 0; i < M; ++i) {
		int x = edge[i].second.first;
		int y = edge[i].second.second;

		if (!Union(x, y)) {
			cnt++;
			sum += edge[i].first;
		}

		if (cnt == N - 2)
			break;
	}

	cout << sum << "\n";
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	init();
	kruskal();

	return 0;
}