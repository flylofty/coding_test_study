#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
vector<int> v;
int Max = 0;

void input() {

	cin >> N >> M;
	v.assign(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		if (Max < v[i])
			Max = v[i];
	}
}

void findAnswer() {
	int left = 0;
	int right = 1000000000;

	int Min = right;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (mid < Max) {
			left = mid + 1;
			continue;
		}

		int temp = mid;
		int cnt = 1;
		for (int i = 0; i < N; ++i) {
			if (temp - v[i] < 0) {
				cnt++;
				temp = mid;
			}
			temp -= v[i];
		}

		if (cnt <= M) {
			right = mid - 1;
			if (Min > mid)
				Min = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << Min << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	findAnswer();
	return 0;
}