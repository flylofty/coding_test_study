#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	vector<int> lion;
	for (int i = 0; i < N; ++i) {
		int doll; cin >> doll;
		if (doll == 1)
			lion.push_back(i + 1);
	}

	if (K > lion.size()) {
		cout << "-1\n";
		return 0;
	}

	int Min = 1000001;

	int a = 0;
	for (int b = a + K - 1; b < lion.size(); ++b, ++a) {
		int size = lion[b] - lion[a] + 1;
		if (Min > size)
			Min = size;
	}

	cout << Min << "\n";

	return 0;
}