#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<int, pair<int, int>>> v;
vector<int> u(1001);

void input() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {

		u[i] = i;
		for (int j = 1; j <= N; ++j) {
			int c; cin >> c;

			if (c == 0)
				continue;

			if (i < j)
				v.push_back({ c ,{i, j} });
		}
	}

	sort(v.begin(), v.end());
}

int Find(int a) {
	if (u[a] == a) return a;
	else return u[a] = Find(u[a]);
}

bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b)
		return true;

	u[b] = a;
	return false;
}

void kruskal() {

	int cnt = 0;
	long long sum = 0;
	for (int i = 0; i < v.size(); ++i) {

		int x = v[i].second.first;
		int y = v[i].second.second;
		int cost = v[i].first;

		if (!Union(x, y)) {
			cnt++;
			sum += cost;
		}

		if (cnt == N - 1)
			break;
	}

	cout << sum << "\n";
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	input();
	kruskal();
	return 0;
}