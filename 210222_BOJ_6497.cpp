#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<pair<int, pair<int, int>>> v;
vector<int> group(200000, 0);
int total;

int find(int a) {
	if (group[a] == a) return a;
	else return group[a] = find(group[a]);
}

bool isSameGroup(int a, int b) {

	a = find(a);
	b = find(b);

	if (a == b)
		return true;

	group[b] = a;

	return false;
}

void kruskal() {

	for (int i = 0; i < m; ++i)
		group[i] = i;

	int cnt = 0;
	for (int i = 0; i < v.size(); ++i) {
		int x = v[i].second.first;
		int y = v[i].second.second;

		if (!isSameGroup(x, y)) {
			cnt++;
			total -= v[i].first;
		}

		if (cnt == m - 1)
			break;
	}

	cout << total << "\n";
	total = 0;
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	while (1) {
		cin >> m >> n;

		if (m == 0 && n == 0)
			break;

		v.clear();

		for (int i = 0; i < n; ++i) {
			int x, y, z; cin >> x >> y >> z;
			v.push_back({ z, {x, y} });
			total += z;
		}

		sort(v.begin(), v.end());
		kruskal();
	}

	return 0;
}