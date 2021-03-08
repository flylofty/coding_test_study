#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> A(N + M);
	for (int i = 0; i < N + M; ++i) {
		cin >> A[i];
	}

	vector<int> B(N + M);
	int L = 0;
	int R = N + M - 1;
	int mid = N - 1;

	int i = L;
	int j = mid + 1;
	int k = L;
	
	while (i <= mid && j <= R) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}

	while(i <= mid)
		B[k++] = A[i++];

	while (j <= R)
		B[k++] = A[j++];

	for (int i = L; i <= R; ++i)
		cout << B[i] << " ";
	cout << "\n";

	return 0;
}