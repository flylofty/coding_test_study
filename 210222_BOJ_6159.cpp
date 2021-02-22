#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
vector<int> cows;

int main() {

	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		int c; cin >> c;
		cows.push_back(c);
	}

	sort(cows.begin(), cows.end());

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cnt += upper_bound(cows.begin() + i + 1, cows.end(), S - cows[i]) - (cows.begin() + i + 1);
	}

	cout << cnt << "\n";

	return 0;
}