#include <iostream>
#include <vector>

using namespace std;

int N, M;

void findAnswer(vector<int> t, int previous) {

	if (t.size() == M) {

		for (int i = 0; i < M; ++i) {
			cout << t[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = previous + 1; i <= N; ++i) {
		t.push_back(i);
		findAnswer(t, i);
		t.pop_back();
	}
}

int main() {

	cin >> N >> M;
	findAnswer({}, 0);

	return 0;
}