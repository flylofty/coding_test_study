#include <iostream>

using namespace std;

int N = 0;
int v[100000];
long long total = 0;

int main() {

	cin >> N;
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		sum += v[i];
	}

	for (int i = 0; i < N; ++i) {
		total += (sum - v[i]) * v[i];
		sum = sum - v[i];
	}

	cout << total << "\n";

	return 0;
}