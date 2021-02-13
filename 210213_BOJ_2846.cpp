#include <iostream>
#include <vector>

using namespace std;

int N = 0;
vector<int> v;

int main() {

	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	int Max = 0;
	for (int i = 0; i < N - 1; ++i) {
		
		int j = i + 1;
		for (; j < N; ++j) {
			if (v[j - 1] >= v[j])
				break;
		}

		if (Max < v[j - 1] - v[i]) {
			Max = v[j - 1] - v[i];
			i = j - 1;
		}
	}

	cout << Max << "\n";

	return 0;
}