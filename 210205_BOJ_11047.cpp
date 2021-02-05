#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int K = 0;
vector<int> v;

int main() {

	cin >> N >> K;
	v.assign(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	int cnt = 0;
	int index = v.size() - 1;
	
	while (index >= 0) {

		if (K / v[index] > 0) {
			cnt += K / v[index];
			K = K % v[index];
		}

		index--;
	}

	cout << cnt << "\n";

	return 0;
}