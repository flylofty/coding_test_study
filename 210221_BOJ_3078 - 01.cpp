#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> v[21];

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		string name;
		cin >> name;
		v[name.size()].push_back(i);
	}

	long long cnt = 0;
	for (int i = 2; i < 21; ++i) {

		if (v[i].size() < 2)
			continue;

		for (int j = 0; j < v[i].size() - 1; ++j) {
			cnt += upper_bound(v[i].begin() + j, v[i].end(), v[i][j] + K) - (v[i].begin() + j) - 1;
		}
	}

	cout << cnt << "\n";

	return 0;
}