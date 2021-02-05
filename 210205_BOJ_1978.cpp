#include <iostream>
#include  <vector>

using namespace std;

vector<bool> v(1001, true);

void findPrimeNumber() {

	v[0] = v[1] = false;

	for (int i = 2; i <= 1000; ++i) {
		if (v[i]) {

			int index = i + i;

			while (index <= 1000) {
				v[index] = false;
				index = index + i;
			}
		}
	}
}

int main() {

	findPrimeNumber();

	int N = 0;
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		int num; cin >> num;
		if (v[num])
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}