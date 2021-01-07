#include <iostream>
#include <vector>

using namespace std;

long N = 0;
long M = 0;
vector<int> v;

void input() {
	cin >> N >> M;
	
	v.assign(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> v[i];
}

void findAnswer() {
	int left = 1;
	int right = 1000000000;
	int answer = 0;

	while (left <= right) {
		
		// 최대의 mid를 구해야함!!!
		int mid = (left + right) / 2;

		long long sum = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] > mid)
				sum += v[i] - mid;
		}

		if (sum >= M) {
			if (answer < mid) {
				answer = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	findAnswer();
	return 0;
}