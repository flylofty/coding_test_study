#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N = 0;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int Max = 0;
	for (int i = v.size() - 1; i >= 0; --i) {

		if (Max < v[i] * (N - i))
			Max = v[i] * (N - i);
	}

	cout << Max << "\n";

	return 0;
}