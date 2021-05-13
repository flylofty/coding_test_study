#include <iostream>
#include <vector>

using namespace std;

int N, M, K, Min = 5001;
int A[51][51];
int B[51][51];
int op[6][3];
vector<int> v;
bool check[6];

void rotate(int x1, int y1, int x2, int y2) {

	while (x1 < x2 && y1 < y2) {

		int temp = B[x1][y1];

		for (int i = x1 + 1; i <= x2; ++i)
			B[i - 1][y1] = B[i][y1];

		for (int i = y1 + 1; i <= y2; ++i)
			B[x2][i - 1] = B[x2][i];

		for (int i = x2 - 1; i >= x1; --i)
			B[i + 1][y2] = B[i][y2];

		for (int i = y2 - 1; i >= y1 + 1; --i)
			B[x1][i + 1] = B[x1][i];

		B[x1][y1 + 1] = temp;

		x1++, y1++, x2--, y2--;
	}
}

void findAnswer() {

	if (v.size() == K) {

		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j)
				B[i][j] = A[i][j];

		for (int i = 0; i < K; ++i)
			rotate(op[v[i]][0] - op[v[i]][2], op[v[i]][1] - op[v[i]][2], op[v[i]][0] + op[v[i]][2], op[v[i]][1] + op[v[i]][2]);

		for (int i = 1; i <= N; ++i) {
			int sum = 0;
			for (int j = 1; j <= M; ++j) {
				sum += B[i][j];
			}

			if (Min > sum)
				Min = sum;
		}

		return;
	}

	for (int i = 0; i < K; ++i) {

		if (check[i])
			continue;

		check[i] = true;
		v.push_back(i);
		findAnswer();
		v.pop_back();
		check[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < K; ++i)
		cin >> op[i][0] >> op[i][1] >> op[i][2];

	findAnswer();

	cout << Min << "\n";

	return 0;
}