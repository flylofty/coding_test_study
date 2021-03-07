#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a; cin >> a;

		int index = lower_bound(v.begin(), v.end(), a) - v.begin();

		if (index >= N)
			cout << "0 ";
		else {
			cout << "1 ";
		}
	}

	return 0;
}