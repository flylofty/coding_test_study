#include <iostream>
#include <cmath>

using namespace std;
// 배열 없이 바로 출력하는 경우
int N;
const int Max = 531441;

void findAnswer(int s, int e) {

	if (e - s == 3) {
		for (int i = s + 1; i <= e; ++i) {
			if (i % 2 == 1) {
				cout << "-";
			}
			else {
				cout << " ";
			}
		}
		return;
	}

	e = (e - s);
	findAnswer(s, e / 3 * 1 + s);
	for (int i = e / 3 * 1 + s + 1; i <= e / 3 * 2 + s; ++i)
		cout << " ";
	findAnswer( e / 3 * 2 + s, e / 3 * 3 + s);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while (cin >> N) {

		N = pow(3, N);

		if (N == 1) {
			cout << "-\n";
			continue;
		}
		else if (N == 3) {
			cout << "- -\n";
			continue;
		}

		findAnswer(0, N / 3 * 1);
		for (int i = N / 3 * 1 + 1; i <= N / 3 * 2; ++i)
			cout << " ";
		findAnswer(N / 3 * 2, N);
		cout << "\n";
	}

	return 0;
}


// bool 배열을 이용하는 경우
// #include <iostream>
// #include <cmath>

// using namespace std;

// int N;
// const int Max = 531441;
// bool bar[Max + 1]{ false };

// void findAnswer(int s, int e) {

// 	if (e % 2 == 0)
// 		return;

// 	if (e - s == 3) {
// 		for (int i = s + 1; i <= e; ++i) {
// 			if (i % 2 == 1) {
// 				bar[i] = true;
// 			}
// 		}
// 		return;
// 	}

// 	findAnswer(s, (e - s) / 3 * 1 + s);
// 	findAnswer((e - s) / 3 * 2 + s, (e - s) / 3 * 3 + s);
// }

// int main() {
    
//     ios::sync_with_stdio(0);
// 	cin.tie(0), cout.tie(0);

// 	while (cin >> N) {

// 		N = pow(3, N);

// 		if (N == 1) {
// 			cout << "-\n";
// 			continue;
// 		}
// 		else if (N == 3) {
// 			cout << "- -\n";
// 			continue;
// 		}

// 		findAnswer(0, N / 3 * 1);
// 		findAnswer(N / 3 * 2, N);

// 		for (int i = 1; i <= N; ++i) {
// 			if (bar[i]) {
// 				cout << "-";
// 			}
// 			else {
// 				cout << " ";
// 			}
// 		}
// 		cout << "\n";
// 	}

// 	return 0;
// }