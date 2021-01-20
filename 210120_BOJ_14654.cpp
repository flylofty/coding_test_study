#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<int> A;
vector<int> B;

void input() {
	cin >> N;

	A.assign(N, 0);
	B.assign(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
}

void rps() {

	int a = 0;
	int b = 0;
	int Max = 0;

	for (int i = 0; i < N; ++i) {
		
		if (A[i] == 1) { // 가위
			if (B[i] == 1) { //가위
				if (a > 0) {
					a = 0;
					b++;
				}
				else {
					a++;
					b = 0;
				}
			}
			else if (B[i] == 2) { // 바위
				a = 0;
				b++;
			}
			else { // 보
				a++;
				b = 0;
			}
		}
		else if (A[i] == 2) { // 바위
			if (B[i] == 1) { //가위
				a++;
				b = 0;
			}
			else if (B[i] == 2) { // 바위
				if (a > 0) {
					a = 0;
					b++;
				}
				else {
					a++;
					b = 0;
				}
			}
			else { // 보
				a = 0;
				b++;
			}
		}
		else if (A[i] == 3) { // 보
			if (B[i] == 1) { //가위
				a = 0;
				b++;
			}
			else if (B[i] == 2) { // 바위
				a++;
				b = 0;
			}
			else { // 보
				if (a > 0) {
					a = 0;
					b++;
				}
				else {
					a++;
					b = 0;
				}
			}
		}

		int M = max(a, b);
		Max = max(Max, M);
	}

	cout << Max << "\n";
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	input();
	rps();

	return 0;
}