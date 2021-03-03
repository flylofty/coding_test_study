#include <iostream>

using namespace std;

int N, S;
int v[21];
int cnt = 0;

void findAnswer(int pre, int sum) {

	if (pre >= 0 && sum == S)
		cnt++;

	for (int i = pre + 1; i < N; ++i) {
		findAnswer(i, sum + v[i]);
	}
}

int main() {

	cin >> N >> S;

	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	findAnswer(-1, 0);

	cout << cnt << "\n";

	return 0;
}