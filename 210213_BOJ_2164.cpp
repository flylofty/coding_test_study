#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second > b.second)
		return false;
	else if (a.second < b.second) {
		return true;
	}
	else {
		if (a.first > b.first)
			return false;
		else
			return true;
	}
}

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; ++i)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}