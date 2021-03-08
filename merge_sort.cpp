#include <iostream>
#include <vector>

// Merge Sort
// 백준 수 정렬하기 2
// boj.kr/2751

using namespace std;

int N;
vector<int> v(1000000);
vector<int> t(1000000);

void Merge(int L, int M, int R) {

	int i = L;
	int j = M + 1;
	int k = L;

	while (i <= M && j <= R) {

		if (v[i] <= v[j]) {
			t[k++] = v[i++];
		}
		else {
			t[k++] = v[j++];
		}
	}

	while(i <= M)
		t[k++] = v[i++];

	while (j <= R)
		t[k++] = v[j++];

	for (int i = L; i <= R; ++i)
		v[i] = t[i];
}

void rMerge(int L, int R) {

	if (L < R) {

		int M = (L + R) / 2;

		// 분할
		rMerge(L, M);
		rMerge(M + 1, R);

		// 정복
		Merge(L, M, R);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> v[i];

	rMerge(0, N - 1);

	for (int i = 0; i < N; ++i)
		cout << v[i] << "\n";

	return 0;
}